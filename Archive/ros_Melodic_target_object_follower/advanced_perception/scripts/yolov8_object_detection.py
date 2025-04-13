#!/usr/bin/env python
# -*- coding: utf-8 -*-

import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from custom_msgs.msg import InferenceResult, YoloInference
import cv2
import numpy as np
import torch
from ultralytics import YOLO

bridge = CvBridge()

class YoloObjectDetection(object):  # Explicitly inherit from object for Python 2.7
    def __init__(self):
        # Initialize the ROS node
        rospy.init_node('object_detection')
        rospy.loginfo("Node initialized")  # Using rospy.loginfo instead of print

        # Load a pre-trained YOLO object detection model
        rospy.loginfo("Loading YOLO model...")
        try:
            self.model = YOLO('/home/user/catkin_ws/src/advanced_perception/data/yolov8n.pt')
            rospy.loginfo("Model loaded successfully")
        except Exception as e:
            rospy.logerr("Failed to load YOLO model: %s", str(e))
            raise

        self.yolo_inference = YoloInference()

        # ROS1 subscribers and publishers
        rospy.loginfo("Subscribing to camera topic...")
        self.subscription = rospy.Subscriber(
            '/camera/rgb/image_raw',
            Image,
            self.camera_callback,
            queue_size=10)

        self.yolo_pub = rospy.Publisher("/Yolo_Inference", YoloInference, queue_size=1)
        self.img_pub = rospy.Publisher("/inference_result", Image, queue_size=1)
        rospy.loginfo("Publishers created")

    def camera_callback(self, msg):
        """ Performs object detection using the loaded YOLO model
            and processes the detection results. The image with 
            annotated detections is also published for visualization """

        try:
            rospy.logdebug("Received camera frame")
            img = bridge.imgmsg_to_cv2(msg, "bgr8")
            results = self.model(img)

            self.yolo_inference.header.frame_id = "inference"
            self.yolo_inference.header.stamp = rospy.Time.now()

            for r in results:
                boxes = r.boxes
                for box in boxes:
                    self.inf_result = InferenceResult()
                    # get box coordinates in (top, left, bottom, right) format
                    b = box.xyxy[0].cpu().detach().numpy().copy()  # Removed .to() for Python 2.7
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
            self.yolo_inference.yolo_inference = []  # Using assignment instead of clear() for Python 2.7

        except Exception as e:
            rospy.logerr("Error in camera callback: %s", str(e))

def main():
    try:
        object_detection = YoloObjectDetection()
        rospy.spin()
    except rospy.ROSInterruptException:
        pass

if __name__ == '__main__':
    main()
     