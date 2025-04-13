#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from custom_msgs.msg import YoloSegmentationMsg
import time
import numpy as np
from datetime import datetime 

class SceneGraphBuilder(Node):
    def __init__(self):
        super().__init__('scene_graph_builder')
        self.subscription = self.create_subscription(
            YoloSegmentationMsg,
            '/Yolo_segmentation',
            self.segmentation_callback,
            10)

        self.object_id_counter = 0
        self.tracked_objects = {}  # {id: {"centroid": (x, y), "class_id": int, "class_name": str, "last_seen": time.time()}}
        self.max_tracking_distance = 50  # pixels (2D proximity)
        self.expiry_seconds = 5  # seconds to retain unseen objects
        self.MAX_DETECTIONS = 50  # cap detections processed per frame

        self.get_logger().info("SceneGraphBuilder node initialized and listening to /Yolo_segmentation")

    def segmentation_callback(self, msg):
        current_time = time.time()
        current_objects = []

        # Limit the number of processed detections
        for result in msg.yolo_segmentation_msg[:self.MAX_DETECTIONS]:
            cx = result.x
            cy = result.y
            class_id = result.class_id
            class_name = result.class_name
            current_objects.append((cx, cy, class_id, class_name))

        updated_tracked = {}

        for cx, cy, class_id, class_name in current_objects:
            matched_id = None
            for obj_id, obj_data in self.tracked_objects.items():
                ox, oy = obj_data["centroid"]
                dist = np.linalg.norm([cx - ox, cy - oy])
                if dist < self.max_tracking_distance and obj_data["class_id"] == class_id:
                    matched_id = obj_id
                    break

            if matched_id is not None:
                updated_tracked[matched_id] = {
                    "centroid": (cx, cy),
                    "class_id": class_id,
                    "class_name": class_name,
                    "last_seen": current_time
                }
            else:
                new_id = self.object_id_counter
                self.object_id_counter += 1
                updated_tracked[new_id] = {
                    "centroid": (cx, cy),
                    "class_id": class_id,
                    "class_name": class_name,
                    "last_seen": current_time
                }

        # Retain recent unseen objects (prevent drop from minor occlusion or dropped frame)
        for obj_id, obj_data in self.tracked_objects.items():
            if obj_id not in updated_tracked and (current_time - obj_data["last_seen"]) < self.expiry_seconds:
                updated_tracked[obj_id] = obj_data

        self.tracked_objects = updated_tracked
        self.print_scene_graph()

    def print_scene_graph(self):
        timestamp = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
        self.get_logger().info(f"Scene Graph [{timestamp}]:")
        
        # Print object nodes
        for obj_id, obj in self.tracked_objects.items():
            self.get_logger().info(
                f"  ID {obj_id}: {obj['class_name']} (class {obj['class_id']}) at {tuple(round(c, 1) for c in obj['centroid'])}"
            )

        # Print spatial relationships
        obj_list = list(self.tracked_objects.items())
        for i in range(len(obj_list)):
            id1, obj1 = obj_list[i]
            x1, y1 = obj1["centroid"]
            name1 = obj1["class_name"]

            for j in range(i + 1, len(obj_list)):
                id2, obj2 = obj_list[j]
                x2, y2 = obj2["centroid"]
                name2 = obj2["class_name"]

                x_diff = x2 - x1
                y_diff = y2 - y1

                # Horizontal: Left / Right
                if abs(x_diff) > 20:
                    if x_diff > 0:
                        self.get_logger().info(f"    Relation: {name1} (ID {id1}) is left of {name2} (ID {id2})")
                        self.get_logger().info(f"    Relation: {name2} (ID {id2}) is right of {name1} (ID {id1})")
                    else:
                        self.get_logger().info(f"    Relation: {name1} (ID {id1}) is right of {name2} (ID {id2})")
                        self.get_logger().info(f"    Relation: {name2} (ID {id2}) is left of {name1} (ID {id1})")

                '''
                # Vertical: Above / Below
                if abs(y_diff) > 20:
                    if y_diff > 0:
                        self.get_logger().info(f"    Relation: {name1} (ID {id1}) is above {name2} (ID {id2})")
                        self.get_logger().info(f"    Relation: {name2} (ID {id2}) is below {name1} (ID {id1})")
                    else:
                        self.get_logger().info(f"    Relation: {name1} (ID {id1}) is below {name2} (ID {id2})")
                        self.get_logger().info(f"    Relation: {name2} (ID {id2}) is above {name1} (ID {id1})")
                '''

                # Depth-based: In front of / Behind (using y as proxy)
                if abs(y_diff) > 20:
                    if y1 > y2:
                        self.get_logger().info(f"    Relation: {name1} (ID {id1}) is in front of {name2} (ID {id2})")
                        self.get_logger().info(f"    Relation: {name2} (ID {id2}) is behind {name1} (ID {id1})")
                    else:
                        self.get_logger().info(f"    Relation: {name1} (ID {id1}) is behind {name2} (ID {id2})")
                        self.get_logger().info(f"    Relation: {name2} (ID {id2}) is in front of {name1} (ID {id1})")


def main(args=None):
    rclpy.init(args=args)
    node = SceneGraphBuilder()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
