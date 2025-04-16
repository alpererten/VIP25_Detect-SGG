#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from custom_msgs.msg import YoloSegmentationMsg
import time
import numpy as np

class SceneGraphBuilder(Node):
    def __init__(self):
        super().__init__('scene_graph_builder')
        self.subscription = self.create_subscription(
            YoloSegmentationMsg,
            '/Yolo_segmentation',
            self.segmentation_callback,
            10)

        self.object_id_counter = 0
        self.tracked_objects = {}  # {id: {"centroid": (x, y), "depth": d, "class_id": int, "class_name": str, "last_seen": time.time()}}
        self.max_tracking_distance = 50  # pixels
        self.expiry_seconds = 5  # seconds

        self.get_logger().info("SceneGraphBuilder node initialized and listening to /Yolo_segmentation")

    def segmentation_callback(self, msg):
        current_time = time.time()
        current_objects = []

        skipped = 0
        self.get_logger().info(f"Received {len(msg.yolo_segmentation_msg)} objects from segmentation.")

        for result in msg.yolo_segmentation_msg[:50]:
            cx, cy = result.x, result.y
            depth = result.depth
            class_id = result.class_id
            class_name = result.class_name

            if depth <= 0.0:
                skipped += 1
                self.get_logger().warn(f"Skipping '{class_name}' at ({cx:.1f}, {cy:.1f}) due to invalid depth: {depth}")
                continue

            current_objects.append((cx, cy, depth, class_id, class_name))

        if skipped > 0:
            self.get_logger().info(f"Skipped {skipped} object(s) with invalid depth.")

        updated_tracked = {}

        for cx, cy, depth, class_id, class_name in current_objects:
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
                    "depth": depth,
                    "class_id": class_id,
                    "class_name": class_name,
                    "last_seen": current_time
                }
            else:
                new_id = self.object_id_counter
                self.object_id_counter += 1
                updated_tracked[new_id] = {
                    "centroid": (cx, cy),
                    "depth": depth,
                    "class_id": class_id,
                    "class_name": class_name,
                    "last_seen": current_time
                }

        # Retain recently seen objects
        for obj_id, obj_data in self.tracked_objects.items():
            if obj_id not in updated_tracked and (current_time - obj_data["last_seen"]) < self.expiry_seconds:
                updated_tracked[obj_id] = obj_data

        self.tracked_objects = updated_tracked
        self.print_scene_graph()

    def print_scene_graph(self):
        timestamp = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
        self.get_logger().info(f"Scene Graph [{timestamp}]:")
        
        obj_list = list(self.tracked_objects.items())

        # Print object nodes
        for obj_id, obj in obj_list:
            cx, cy = obj["centroid"]
            d = obj["depth"]
            self.get_logger().info(
                f"  ID {obj_id}: {obj['class_name']} (class {obj['class_id']}) at ({round(cx,1)}, {round(cy,1)}), depth: {round(d,2)} m"
            )

        # Print spatial relationships
        for i in range(len(obj_list)):
            id1, obj1 = obj_list[i]
            x1, y1 = obj1["centroid"]
            d1 = obj1["depth"]
            name1 = obj1["class_name"]

            for j in range(i + 1, len(obj_list)):
                id2, obj2 = obj_list[j]
                x2, y2 = obj2["centroid"]
                d2 = obj2["depth"]
                name2 = obj2["class_name"]

                # Left vs Right
                if abs(x2 - x1) > 20:
                    if x1 < x2:
                        self.get_logger().info(f"    Relation: {name1} (ID {id1}) is left of {name2} (ID {id2})")
                        self.get_logger().info(f"    Relation: {name2} (ID {id2}) is right of {name1} (ID {id1})")
                    else:
                        self.get_logger().info(f"    Relation: {name1} (ID {id1}) is right of {name2} (ID {id2})")
                        self.get_logger().info(f"    Relation: {name2} (ID {id2}) is left of {name1} (ID {id1})")

                # Above vs Below
                if abs(y2 - y1) > 20:
                    if y1 < y2:
                        self.get_logger().info(f"    Relation: {name1} (ID {id1}) is above {name2} (ID {id2})")
                        self.get_logger().info(f"    Relation: {name2} (ID {id2}) is below {name1} (ID {id1})")
                    else:
                        self.get_logger().info(f"    Relation: {name1} (ID {id1}) is below {name2} (ID {id2})")
                        self.get_logger().info(f"    Relation: {name2} (ID {id2}) is above {name1} (ID {id1})")

                # In front of vs Behind (depth axis)
                if d1 > 0 and d2 > 0 and abs(d2 - d1) > 0.02:
                    if d1 < d2:
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
