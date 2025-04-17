#!/usr/bin/env python3
# The following code is adapted from Section 6.2 of The Construct’s ROS2 Perception in 5 Days course and modified to work with user entered target object class.
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from geometry_msgs.msg import Twist
from custom_msgs.msg import InferenceResult, YoloInference

class TargetFollower(Node):
    def __init__(self) -> None:
        super().__init__('target_object_follower')
        
        
        # Declare and get ROS 2 parameter for target object
        self.declare_parameter("target_object", "person")
        self.target_object = self.get_parameter("target_object").get_parameter_value().string_value
        self.get_logger().info(f"Target object set to: {self.target_object}")
        
        
        self.subscription_inference = self.create_subscription(
            YoloInference,
            '/Yolo_Inference',
            self.inference_callback,
            10)
        self.subscription_image = self.create_subscription(
            Image,
            #change this to match the camera image topic of the lab robot
            '/deepmind_robot1/deepmind_robot1_camera/image_raw',
            self.image_callback,
            10)
        self.cmd_vel_publisher = self.create_publisher(Twist, '/cmd_vel', 10)
        self.bridge = CvBridge()
        self.image_width = None  
        self.target_detected = False
        

    def image_callback(self, data: Image) -> None:
        """ Updates the image width from the incoming camera image """
        self.image_width = data.width

    def inference_callback(self, msg: YoloInference) -> None:
        """ Processes each inference result, checks for the target ('person') class, and moves the robot accordingly """
        target_detected = False
        if self.image_width is None:
            self.get_logger().warn("Image width not set yet...")
            return

        for inference_result in msg.yolo_inference:
            if inference_result.class_name == self.target_object:
                target_detected = True
                self.get_logger().info(f"Target object detected: {inference_result}")
                # Calculate error_x as the difference between x and the center of the image
                error_x = inference_result.x - (self.image_width / 2)
                self.get_logger().info(f"error_x = {error_x}")
                self.move_towards_target(inference_result, error_x)
                break  # Assuming we only follow the first detected target class instance

        if not target_detected and self.target_detected:
            self.get_logger().info("Target lost, stopping...")
            self.stop_moving()
        self.target_detected = target_detected

    def move_towards_target(self, inference_result: InferenceResult, error_x: float) -> None:
        """ Calculates and publishes velocities to move towards the detected target """
        gain = 0.001 
        linear_velocity = 0.4
        max_box_width = 200
        angular_velocity = -error_x * gain

        self.get_logger().info(f'Moving towards target with error_x: {error_x}, angular velocity: {angular_velocity}, linear velocity: {linear_velocity}, box_width = {inference_result.box_width}')
        if inference_result.box_width > max_box_width:
            linear_velocity = 0.0
            angular_velocity = 0.0
            self.get_logger().info("Arrived at destination...")
            
        self.publish_velocities(linear_velocity, angular_velocity)

    def publish_velocities(self, linear_velocity: float, angular_velocity: float) -> None:
        """ Publishes linear and angular velocities to the cmd_vel topic """
        twist_msg = Twist()
        twist_msg.linear.x = linear_velocity
        twist_msg.angular.z = angular_velocity
        self.cmd_vel_publisher.publish(twist_msg)

    def stop_moving(self) -> None:
        """ Publishes zero velocities to stop the robot """
        twist_msg = Twist()
        self.cmd_vel_publisher.publish(twist_msg)

def main(args=None) -> None:
    rclpy.init(args=args)
    target_follower = TargetFollower()
    rclpy.spin(target_follower)
    target_follower.destroy_node()
    rclpy.shutdown()
    
if __name__ == '__main__':
    main()