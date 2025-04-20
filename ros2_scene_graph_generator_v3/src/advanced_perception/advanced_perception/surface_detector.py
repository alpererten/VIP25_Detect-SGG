#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from std_msgs.msg import Header
from custom_msgs.msg import DetectedSurface, DetectedSurfaces

import numpy as np
import open3d as o3d
import cv2

class SurfaceDetector(Node):
    def __init__(self):
        super().__init__('surface_detector')

        self.bridge = CvBridge()
        self.subscription = self.create_subscription(
            Image,
            '/iphone_depth_image',
            self.depth_callback,
            10
        )

        self.surface_pub = self.create_publisher(DetectedSurfaces, '/detected_surfaces', 10)
        self.get_logger().info('SurfaceDetector node started.')

    def depth_callback(self, msg):
        try:
            depth_raw = self.bridge.imgmsg_to_cv2(msg, desired_encoding='mono16')
            depth = depth_raw.astype(np.float32) / 1000.0  # mm to meters
        except Exception as e:
            self.get_logger().error(f"Depth conversion failed: {e}")
            return

        height, width = depth.shape
        fx, fy = 500.0, 500.0  # Adjust according to actual camera intrinsics
        cx, cy = width / 2, height / 2

        # Generate point cloud
        xmap, ymap = np.meshgrid(np.arange(width), np.arange(height))
        valid = depth > 0
        z = depth[valid]
        x = (xmap[valid] - cx) * z / fx
        y = (ymap[valid] - cy) * z / fy
        points = np.stack((x, y, z), axis=-1)

        pcd = o3d.geometry.PointCloud()
        pcd.points = o3d.utility.Vector3dVector(points)

        # Detect multiple planes
        surfaces = []
        surface_id = 0
        min_points = 5000

        while len(pcd.points) > min_points:
            plane_model, inliers = pcd.segment_plane(distance_threshold=0.02,
                                                     ransac_n=3,
                                                     num_iterations=1000)
            [a, b, c, d] = plane_model
            normal = np.array([a, b, c])
            plane = pcd.select_by_index(inliers)
            center = np.mean(np.asarray(plane.points), axis=0)

            surfaces.append((surface_id, normal, center, len(inliers)))
            surface_id += 1
            pcd = pcd.select_by_index(inliers, invert=True)

        # Publish
        msg_out = DetectedSurfaces()
        msg_out.header = Header()
        msg_out.header.stamp = self.get_clock().now().to_msg()

        for sid, normal, center, n_points in surfaces:
            surface_msg = DetectedSurface()
            surface_msg.id = sid
            surface_msg.normal = normal.tolist()
            surface_msg.center = center.tolist()
            surface_msg.confidence = float(n_points)

            if abs(normal[1]) > 0.9:
                surface_msg.type = 'horizontal'
            else:
                surface_msg.type = 'unknown'

            msg_out.surfaces.append(surface_msg)

        self.surface_pub.publish(msg_out)
        self.get_logger().info(f"Published {len(msg_out.surfaces)} surface(s).")

def main(args=None):
    rclpy.init(args=args)
    node = SurfaceDetector()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

