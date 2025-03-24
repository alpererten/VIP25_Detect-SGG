import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, CameraInfo
from cv_bridge import CvBridge
from visualization_msgs.msg import Marker, MarkerArray
from geometry_msgs.msg import Point
import numpy as np
import cv2
import tf2_ros
import tf2_geometry_msgs
from ultralytics import YOLO

class ObjectDetector(Node):
    def __init__(self):
        super().__init__("object_detector")

        # Load YOLO model
        self.model = YOLO("yolov8n.pt")
        self.bridge = CvBridge()

        # TF2 buffer and listener
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        # Create publishers
        self.marker_pub = self.create_publisher(MarkerArray, "detected_objects", 10)
        self.processed_image_pub = self.create_publisher(Image, "processed_image", 10)

        # Subscribe to Gazebo camera topics
        self.image_sub = self.create_subscription(Image, "/gazebo/camera/image_raw", self.image_callback, 10)
        self.camera_info_sub = self.create_subscription(CameraInfo, "/gazebo/camera/camera_info", self.camera_info_callback, 10)

        # Store camera parameters
        self.camera_matrix = None
        self.dist_coeffs = None
        self.camera_frame = None

        # Configure visualization parameters
        self.colors = {}
        self.marker_id = 0

        self.get_logger().info("Object Detector Node Initialized")

    def camera_info_callback(self, msg):
        """Store camera calibration parameters"""
        if self.camera_matrix is None:
            self.camera_matrix = np.array(msg.k).reshape(3, 3)
            self.dist_coeffs = np.array(msg.d)
            self.camera_frame = msg.header.frame_id
            self.get_logger().info("Camera calibration parameters received")

    def image_callback(self, data):
        if self.camera_matrix is None:
            self.get_logger().warn("Waiting for camera calibration...")
            return

        try:
            # Convert ROS Image to OpenCV format
            cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")

            # Run YOLO inference
            results = self.model(cv_image, conf=0.25)

            # Create marker array for visualization
            marker_array = MarkerArray()

            for r in results:
                boxes = r.boxes
                for box in boxes:
                    # Get detection details
                    cls = int(box.cls[0])
                    conf = float(box.conf[0])
                    xyxy = box.xyxy[0].tolist()
                    class_name = self.model.names[cls]

                    # Draw on image
                    cv2.rectangle(cv_image,
                                  (int(xyxy[0]), int(xyxy[1])),
                                  (int(xyxy[2]), int(xyxy[3])),
                                  self.get_color(class_name), 2)

                    # Add label
                    label = f"{class_name} {conf:.2f}"
                    cv2.putText(cv_image, label,
                                (int(xyxy[0]), int(xyxy[1] - 10)),
                                cv2.FONT_HERSHEY_SIMPLEX, 0.5,
                                self.get_color(class_name), 2)

                    # Create marker with proper Gazebo world coordinates
                    marker = self.create_marker_gazebo(xyxy, class_name, conf, data.header.stamp)
                    if marker:
                        marker_array.markers.append(marker)

            # Publish processed image
            processed_msg = self.bridge.cv2_to_imgmsg(cv_image, "bgr8")
            processed_msg.header = data.header
            self.processed_image_pub.publish(processed_msg)

            # Publish markers
            self.marker_pub.publish(marker_array)

            # Display image (optional)
            cv2.imshow("YOLO Detection", cv_image)
            cv2.waitKey(1)

        except Exception as e:
            self.get_logger().error(f"Error in object detection: {str(e)}")

    def get_color(self, class_name):
        """Generate and cache consistent colors for each class"""
        if class_name not in self.colors:
            self.colors[class_name] = tuple(map(int, np.random.randint(0, 255, 3)))
        return self.colors[class_name]

    def create_marker_gazebo(self, xyxy, class_name, confidence, timestamp):
        """Create a visualization marker in Gazebo world coordinates"""
        try:
            # Calculate center point of detection in image coordinates
            center_x = (xyxy[0] + xyxy[2]) / 2
            center_y = (xyxy[1] + xyxy[3]) / 2

            # Project point to 3D using a default depth (you might want to use actual depth data)
            default_depth = 2.0  # meters
            point_3d = np.array([
                (center_x - self.camera_matrix[0, 2]) * default_depth / self.camera_matrix[0, 0],
                (center_y - self.camera_matrix[1, 2]) * default_depth / self.camera_matrix[1, 1],
                default_depth
            ])

            # Create marker
            marker = Marker()
            marker.header.frame_id = self.camera_frame
            marker.header.stamp = timestamp
            marker.ns = "detected_objects"
            marker.id = self.marker_id
            self.marker_id += 1
            marker.type = Marker.CUBE
            marker.action = Marker.ADD

            # Set position
            marker.pose.position.x = point_3d[0]
            marker.pose.position.y = point_3d[1]
            marker.pose.position.z = point_3d[2]

            # Set size
            width = (xyxy[2] - xyxy[0]) * default_depth / self.camera_matrix[0, 0]
            height = (xyxy[3] - xyxy[1]) * default_depth / self.camera_matrix[1, 1]
            marker.scale.x = width
            marker.scale.y = height
            marker.scale.z = min(width, height)

            # Set color
            color = self.get_color(class_name)
            marker.color.r = color[0] / 255.0
            marker.color.g = color[1] / 255.0
            marker.color.b = color[2] / 255.0
            marker.color.a = min(confidence, 0.5)

            return marker

        except Exception as e:
            self.get_logger().error(f"Error creating marker: {str(e)}")
            return None


def main(args=None):
    rclpy.init(args=args)
    node = ObjectDetector()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()
        cv2.destroyAllWindows()


if __name__ == '__main__':
    main()
