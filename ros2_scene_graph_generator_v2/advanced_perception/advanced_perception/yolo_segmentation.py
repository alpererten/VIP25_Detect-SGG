#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from ultralytics import YOLO
from message_filters import ApproximateTimeSynchronizer, Subscriber

import numpy as np
import cv2
from custom_msgs.msg import SegmentationResult, YoloSegmentationMsg

class YoloSegmentation(Node):
    def __init__(self):
        super().__init__('segmentation')

        self.model = YOLO('/home/alper/ros2_ws/src/advanced_perception/data/yolov8m-seg.pt')
        self.bridge = CvBridge()

        self.rgb_sub = Subscriber(self, Image, '/iphone_rgb_image')
        self.depth_sub = Subscriber(self, Image, '/iphone_depth_image')

        self.ts = ApproximateTimeSynchronizer([self.rgb_sub, self.depth_sub], queue_size=10, slop=0.1)
        self.ts.registerCallback(self.synced_callback)

        self.yolo_pub = self.create_publisher(YoloSegmentationMsg, "/Yolo_segmentation", 1)
        self.img_pub = self.create_publisher(Image, "/segmentation_result", 1)

        self.get_logger().info("YOLO Segmentation Node initialized.")

    def synced_callback(self, rgb_msg, depth_msg):
        rgb = self.bridge.imgmsg_to_cv2(rgb_msg, "bgr8")
        
        # Depth conversion: resize to match YOLO input resolution
        depth_raw = self.bridge.imgmsg_to_cv2(depth_msg, "mono16")
        depth_raw = cv2.resize(depth_raw, (rgb.shape[1], rgb.shape[0]), interpolation=cv2.INTER_NEAREST)
        depth = depth_raw.astype(np.float32) / 1000.0  # Convert mm to meters

        self.get_logger().info(f"RGB shape: {rgb.shape}, Depth shape: {depth.shape}")

        results = self.model(rgb, max_det=50)

        yolo_segmentation = YoloSegmentationMsg()
        yolo_segmentation.header = rgb_msg.header

        for r in results:
            boxes = r.boxes
            for box in boxes:
                b = box.xyxy[0].cpu().numpy()
                cx = int((b[0] + b[2]) / 2)
                cy = int((b[1] + b[3]) / 2)

                segmentation_result = SegmentationResult()
                segmentation_result.class_id = int(box.cls)
                segmentation_result.class_name = self.model.names[int(box.cls)]
                segmentation_result.x = float(cx)
                segmentation_result.y = float(cy)
                segmentation_result.width = float(b[2] - b[0])
                segmentation_result.height = float(b[3] - b[1])

                try:
                    region = depth[max(0, cy - 2):cy + 3, max(0, cx - 2):cx + 3]
                    valid = region[(region > 0.0) & (~np.isnan(region))]
                    if valid.size > 0:
                        segmentation_result.depth = float(np.median(valid))
                    else:
                        raise ValueError("No valid depth in region")
                except (IndexError, ValueError):
                    segmentation_result.depth = -1.0  # fallback

                yolo_segmentation.yolo_segmentation_msg.append(segmentation_result)

        if len(results) > 0:
            annotated_frame = results[0].plot()
            img_msg = self.bridge.cv2_to_imgmsg(annotated_frame, encoding="bgr8")
            self.img_pub.publish(img_msg)

        self.yolo_pub.publish(yolo_segmentation)

def main(args=None):
    rclpy.init(args=args)
    node = YoloSegmentation()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
