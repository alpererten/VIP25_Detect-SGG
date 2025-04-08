#!/usr/bin/env python3
from ultralytics import YOLO
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from custom_msgs.msg import InferenceResult, YoloInference

bridge = CvBridge()

class YoloObjectDetection:
    def __init__(self):
        # Initialize the ROS node
        rospy.init_node('object_detection')
        print("Node initialized")  # Debug print

        # Load a pre-trained YOLO object detection model
        print("Loading YOLO model...")  # Debug print
        self.model = YOLO('/home/user/catkin_ws/src/advanced_perception/data/yolov8n.pt')
        print("Model loaded successfully")  # Debug print
        self.yolo_inference = YoloInference()

        # ROS1 subscribers and publishers
        print("Subscribing to camera topic...")  # Debug print
        self.subscription = rospy.Subscriber(
            '/camera/rgb/image_raw',  # CHANGE THE CAMERA TOPIC NAME TO MATCH THE LOCAL CAMERA TOPIC NAME FOR YOUR ROBOT
            Image,
            self.camera_callback,
            queue_size=10)

        self.yolo_pub = rospy.Publisher("/Yolo_Inference", YoloInference, queue_size=1)
        self.img_pub = rospy.Publisher("/inference_result", Image, queue_size=1)
        print("Publishers created")  # Debug print

    def camera_callback(self, msg):
        """ Performs object detection using the loaded YOLO model
            and processes the detection results. The image with 
            annotated detections is also published for visualization """

        print("Received camera frame")  # Debug print
        img = bridge.imgmsg_to_cv2(msg, "bgr8")
        results = self.model(img) 

        self.yolo_inference.header.frame_id = "inference"
        self.yolo_inference.header.stamp = rospy.Time.now()

        for r in results:
            boxes = r.boxes
            for box in boxes:
                self.inf_result = InferenceResult()
                # get box coordinates in (top, left, bottom, right) format
                b = box.xyxy[0].to('cpu').detach().numpy().copy()  
                c = box.cls
                self.inf_result.class_name = self.model.names[int(c)]
                self.inf_result.left = int(b[0])
                self.inf_result.top = int(b[1])
                self.inf_result.right = int(b[2])
                self.inf_result.bottom = int(b[3])
                self.inf_result.box_width = (self.inf_result.right - self.inf_result.left) 
                self.inf_result.box_height = (self.inf_result.bottom - self.inf_result.top)
                self.inf_result.x = self.inf_result.left + (self.inf_result.box_width/2.0)
                self.inf_result.y = self.inf_result.top + (self.inf_result.box_height/2.0)
                self.yolo_inference.yolo_inference.append(self.inf_result)

        annotated_frame = results[0].plot()
        img_msg = bridge.cv2_to_imgmsg(annotated_frame)  
        self.img_pub.publish(img_msg)

        self.yolo_pub.publish(self.yolo_inference)
        self.yolo_inference.yolo_inference.clear()

def main():
    try:
        object_detection = YoloObjectDetection()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass

if __name__ == '__main__':
    main()
     