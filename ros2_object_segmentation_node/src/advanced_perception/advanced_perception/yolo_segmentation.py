#!/usr/bin/env python3
# The following code is adapted from Section 6.2 of The Construct’s ROS2 Perception in 5 Days course
from ultralytics import YOLO
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from custom_msgs.msg import SegmentationResult, YoloSegmentationMsg

bridge = CvBridge()

class YoloSegmentation(Node):
    """ This node publishes segmentation results of YOLO on ROS2 """

    def __init__(self) -> None:
        super().__init__('segmentation')
        # Load pre-trained yolov8n-pose model for instance segmentation
        self.model = YOLO('/home/user/ros2_ws/src/advanced_perception/data/yolov8n-seg.pt') 
        self.yolo_segmentation = YoloSegmentationMsg()

        self.subscription = self.create_subscription(
            Image,
            '/deepmind_robot1/deepmind_robot1_camera/image_raw',
            self.camera_callback,
            10)

        self.yolo_pub = self.create_publisher(YoloSegmentationMsg, "/Yolo_segmentation", 1)
        self.img_pub = self.create_publisher(Image, "/segmentation_result", 1)

    def camera_callback(self, data: Image) -> None:
        img = bridge.imgmsg_to_cv2(data, "bgr8")
        results = self.model(img)  

        self.yolo_segmentation.header.stamp = self.get_clock().now().to_msg()
        self.yolo_segmentation.header.frame_id = "segmentation"

        for r in results:
            boxes = r.boxes
            for box in boxes:
                self.segmentation_result = SegmentationResult()
                b = box.xyxy[0].to('cpu').detach().numpy().copy() 
                c = box.cls
                self.segmentation_result.class_id = int(c)
                self.segmentation_result.class_name = self.model.names[int(c)]
                self.segmentation_result.x = (b[0] + b[2]) / 2 
                self.segmentation_result.y = (b[1] + b[3]) / 2  
                self.segmentation_result.width = float(b[2] - b[0])
                self.segmentation_result.height = float(b[3] - b[1])
                self.yolo_segmentation.yolo_segmentation_msg.append(self.segmentation_result)

        annotated_frame = results[0].plot()
        img_msg = bridge.cv2_to_imgmsg(annotated_frame)  
        self.img_pub.publish(img_msg)

        self.yolo_pub.publish(self.yolo_segmentation)
        #self.yolo_segmentation.yolo_segmentation.clear()

def main(args=None) -> None:
    rclpy.init(args=args)
    segmentation = YoloSegmentation()
    rclpy.spin(segmentation)
    segmentation.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()