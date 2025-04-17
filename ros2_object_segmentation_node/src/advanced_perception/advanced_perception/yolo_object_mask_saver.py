#!/usr/bin/env python3
# The following code is adapted from Section 6.2 of The Construct’s ROS2 Perception in 5 Days course
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from custom_msgs.msg import YoloSegmentationMsg
import numpy as np
import cv2
import os
from advanced_perception.yolo_segmentation import YoloSegmentation 
import ultralytics
from datetime import datetime  

bridge = CvBridge()

class ObjectMaskSaver(Node):
    def __init__(self) -> None:
        """Initializes the ObjectMaskSaver node."""
        super().__init__('object_mask_saver')
        self.subscription = self.create_subscription(
            YoloSegmentationMsg,
            '/Yolo_segmentation',
            self.handle_segmentation,
            10)
        self.img_sub = self.create_subscription(
            Image,
            '/deepmind_robot1/deepmind_robot1_camera/image_raw',
            self.image_callback,
            10)
        
        self.output_dir = '/home/user/ros2_ws/src/advanced_perception/data/segmentation_results'
        os.makedirs(self.output_dir, exist_ok=True)
        self.img = None
        self.yolo_segmentation = []
        self.image_ready = False
        self.segmentation_ready = False

        # Create an instance of YoloSegmentation
        self.yolo_segmentation_instance = YoloSegmentation()

    def handle_segmentation(self, msg: YoloSegmentation) -> None:
        """ Handles incoming segmentation data """
        self.yolo_segmentation = msg.yolo_segmentation_msg
        self.segmentation_ready = True

    def image_callback(self, data: Image) -> None:
        """ Callback function for image data received from the camera """
        self.img = bridge.imgmsg_to_cv2(data, "bgr8")
        self.image_ready = True

    def save_masks_as_image(self, results: ultralytics.engine.results, output_dir: str) -> None:
        """ Saves the masks as images in the specified directory """
        if not hasattr(results, 'masks') or results.masks is None:
            self.get_logger().error("No 'masks' attribute found in the results or masks are empty. Please check the model configuration.")
            return

        masks = results.masks.data.cpu().numpy()
        combined_mask = self.combine_masks(masks, results)
        self.save_combined_mask(combined_mask, output_dir)

    def combine_masks(self, masks: np.ndarray, results: ultralytics.engine.results) -> np.ndarray:
        """ Combines all masks into a single mask image and labels each with its class name and index """
        combined_mask = np.zeros((self.img.shape[0], self.img.shape[1], 3), dtype=np.uint8)
        class_counts = {}  # e.g., {'apple': 2, 'banana': 1}

        for i, mask in enumerate(masks):
            # Skip if there's no corresponding box
            if i >= len(results.boxes.cls):
                continue

            class_id = int(results.boxes.cls[i])
            class_name = self.yolo_segmentation_instance.model.names[class_id]

            # Initialize count if first time seeing this class
            if class_name not in class_counts:
                class_counts[class_name] = 1
            else:
                class_counts[class_name] += 1

            mask_data = mask
            if mask_data.size != 0 and mask_data.ndim >= 2:
                if mask_data.shape[0] == 1:
                    mask_data = np.squeeze(mask_data, axis=0)
                mask_data = (mask_data * 255).astype(np.uint8)
                mask_data = cv2.resize(mask_data, (self.img.shape[1], self.img.shape[0]))

                # Assign a unique color using the class_id
                color = tuple(int(x) for x in np.random.default_rng(class_id).integers(0, 256, size=3))
                combined_mask[mask_data > 0] = color

                # Label with class name and count (e.g., "apple1", "banana2")
                M = cv2.moments(mask_data)
                if M["m00"] != 0:
                    cx = int(M["m10"] / M["m00"])
                    cy = int(M["m01"] / M["m00"])
                    label = f"{class_name}{class_counts[class_name]}"
                    cv2.putText(combined_mask, label, (cx, cy), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)

        # Log detected object summary
        summary = ", ".join(f"{cls}: {cnt}" for cls, cnt in class_counts.items())
        self.get_logger().info(f"Detected: {summary}")
        return combined_mask


    def save_combined_mask(self, combined_mask: np.ndarray, output_dir: str) -> None:
        """ Saves the combined mask image to the specified directory """
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        filename = f"combined_masks_{timestamp}.png"
        mask_path = os.path.join(output_dir, filename)
        cv2.imwrite(mask_path, combined_mask)
        self.get_logger().info(f"Successfully created and saved the mask image as {filename} inside {self.output_dir} folder")

def main(args=None) -> None:
    rclpy.init(args=args)
    object_mask_saver = ObjectMaskSaver()
    executor = rclpy.executors.SingleThreadedExecutor()
    executor.add_node(object_mask_saver)

    try:
        while rclpy.ok():
            executor.spin_once()
            if object_mask_saver.image_ready and object_mask_saver.segmentation_ready:
                if object_mask_saver.img is not None and object_mask_saver.yolo_segmentation:
                    results = object_mask_saver.yolo_segmentation_instance.model(object_mask_saver.img)
                    if results:
                        object_mask_saver.save_masks_as_image(results[0], object_mask_saver.output_dir)
                    break  # Process only once
            else:
                if object_mask_saver.segmentation_ready is False:
                    object_mask_saver.get_logger().error("Waiting to subscribe to the Segmentation results ..")
                else:
                    object_mask_saver.get_logger().error("Waiting to subscribe to the Image data ..")
    finally:
        object_mask_saver.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()