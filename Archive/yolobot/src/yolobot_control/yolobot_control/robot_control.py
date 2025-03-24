#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Joy

class RobotControl(Node):
    def __init__(self):
        super().__init__('robot_control')
        
        # Create publishers
        self.cmd_vel_pub = self.create_publisher(Twist, '/yolobot/cmd_vel', 10)
        
        # Create subscribers
        self.joy_sub = self.create_subscription(Joy, 'joy', self.joy_callback, 10)
        
        self.get_logger().info('Robot controller initialized')

    def joy_callback(self, msg):
        twist = Twist()
        # Linear velocity (left stick up/down)
        twist.linear.x = msg.axes[1] * 0.5  # Scale down to 0.5 m/s max
        # Angular velocity (left stick left/right)
        twist.angular.z = msg.axes[0] * 1.0  # Scale to 1.0 rad/s max
        self.cmd_vel_pub.publish(twist)

def main(args=None):
    rclpy.init(args=args)
    node = RobotControl()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main() 