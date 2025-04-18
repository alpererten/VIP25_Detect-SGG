#!/usr/bin/env python3
# The following code is adapted from Section 6.2 of The Construct’s ROS2 Perception in 5 Days course and modified to work with user entered target object class and ROS Noetic environment.
import rospy
from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist
from cv_bridge import CvBridge
from custom_msgs.msg import InferenceResult, YoloInference

class TargetFollower:
    def __init__(self):
        rospy.init_node('target_object_follower', anonymous=False)
        
        # Get ROS parameter for target object, defaulting to "person"
        self.target_object = rospy.get_param("~target_object", "person")
        rospy.loginfo(f"Target object set to: {self.target_object}")

        # ROS Subscribers
        self.sub_inference = rospy.Subscriber('/Yolo_Inference', YoloInference, self.inference_callback)
        self.sub_image = rospy.Subscriber('/deepmind_robot1/deepmind_robot1_camera/image_raw', Image, self.image_callback)

        # ROS Publisher
        self.cmd_vel_pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)

        self.bridge = CvBridge()
        self.image_width = None
        self.target_detected = False

    def image_callback(self, msg):
        """ Updates the image width from the incoming camera image """
        self.image_width = msg.width

    def inference_callback(self, msg):
        """ Processes each inference result, checks for the target ('person') class, and moves the robot accordingly """
        target_detected = False
        if self.image_width is None:
            rospy.logwarn("Image width not set yet...")
            return

        for inference_result in msg.yolo_inference:
            if inference_result.class_name == self.target_object:
                target_detected = True
                rospy.loginfo(f"Target object detected: {inference_result}")
                error_x = inference_result.x - (self.image_width / 2)
                rospy.loginfo(f"error_x = {error_x}")
                self.move_towards_target(inference_result, error_x)
                break  # Only follow the first matching target

        if not target_detected and self.target_detected:
            rospy.loginfo("Target lost, stopping...")
            self.stop_moving()

        self.target_detected = target_detected

    def move_towards_target(self, inference_result, error_x):
        """ Calculates and publishes velocities to move towards the detected target """
        gain = 0.001
        linear_velocity = 0.4
        max_box_width = 200
        angular_velocity = -error_x * gain

        rospy.loginfo(f'Moving towards target: error_x={error_x}, angular={angular_velocity}, linear={linear_velocity}, box_width={inference_result.box_width}')
        if inference_result.box_width > max_box_width:
            linear_velocity = 0.0
            angular_velocity = 0.0
            rospy.loginfo("Arrived at destination...")

        self.publish_velocities(linear_velocity, angular_velocity)

    def publish_velocities(self, linear_velocity, angular_velocity):
        """ Publishes Twist message with the given velocities """
        twist_msg = Twist()
        twist_msg.linear.x = linear_velocity
        twist_msg.angular.z = angular_velocity
        self.cmd_vel_pub.publish(twist_msg)

    def stop_moving(self):
        """ Stops the robot by publishing zero velocity """
        twist_msg = Twist()
        self.cmd_vel_pub.publish(twist_msg)

def main():
    TargetFollower()
    rospy.spin()

if __name__ == '__main__':
    main()
