#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import numpy as np
import cv2
from threading import Event
from record3d import Record3DStream

class Record3DPublisher(Node):
    def __init__(self):
        super().__init__('record3d_publisher')
        self.bridge = CvBridge()
        self.event = Event()
        self.DEVICE_TYPE__TRUEDEPTH = 0
        self.DEVICE_TYPE__LIDAR = 1

        self.rgb_pub = self.create_publisher(Image, 'iphone_rgb_image', 10)
        self.depth_pub = self.create_publisher(Image, 'iphone_depth_image', 10)

        self.session = Record3DStream()
        self.session.on_new_frame = self.on_new_frame
        self.session.on_stream_stopped = self.on_stream_stopped

        self.connect_to_device(dev_idx=0)
        self.run_stream_loop()

    def connect_to_device(self, dev_idx):
        devs = Record3DStream.get_connected_devices()
        if len(devs) <= dev_idx:
            raise RuntimeError(f'Cannot connect to device #{dev_idx}')

        self.session.connect(devs[dev_idx])

    def on_new_frame(self):
        self.event.set()

    def on_stream_stopped(self):
        self.get_logger().info('Stream stopped')

    def run_stream_loop(self):
        self.get_logger().info('iphone camera node is active and running...')
        while rclpy.ok():
            self.event.wait()

            depth = self.session.get_depth_frame()
            rgb = self.session.get_rgb_frame()

            if self.session.get_device_type() == self.DEVICE_TYPE__TRUEDEPTH:
                depth = cv2.flip(depth, 1)
                rgb = cv2.flip(rgb, 1)

            rgb = cv2.cvtColor(rgb, cv2.COLOR_RGB2BGR)

            rgb_msg = self.bridge.cv2_to_imgmsg(rgb, encoding='bgr8')
            depth_uint16 = (depth * 1000).astype(np.uint16)  # Convert meters to millimeters and cast to uint16
            depth_msg = self.bridge.cv2_to_imgmsg(depth_uint16, encoding='mono16')


            self.rgb_pub.publish(rgb_msg)
            self.depth_pub.publish(depth_msg)

            self.event.clear()

def main(args=None):
    rclpy.init(args=args)
    node = Record3DPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
