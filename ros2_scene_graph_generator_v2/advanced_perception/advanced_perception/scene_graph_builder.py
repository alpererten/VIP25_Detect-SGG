import rclpy
from rclpy.node import Node
from custom_msgs.msg import YoloSegmentationMsg, DetectedSurfaces
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

        self.surface_sub = self.create_subscription(
            DetectedSurfaces,
            '/detected_surfaces',
            self.surfaces_callback,
            10)

        self.object_id_counter = 0
        self.tracked_objects = {}
        self.detected_surfaces = []
        self.max_tracking_distance = 50
        self.expiry_seconds = 5

        self.get_logger().info("SceneGraphBuilder node initialized and listening to /Yolo_segmentation and /detected_surfaces")

    def surfaces_callback(self, msg):
        self.detected_surfaces = []
        for s in msg.surfaces:
            surface = s
            height = s.center[2]
            if height < 0.15:
                surface.type = 'floor'
            else:
                surface.type = 'table'
            self.detected_surfaces.append(surface)

    def segmentation_callback(self, msg):
        current_time = time.time()
        current_objects = []

        self.get_logger().info(f"Received {len(msg.yolo_segmentation_msg)} objects from segmentation.")

        for result in msg.yolo_segmentation_msg[:50]:
            cx, cy = result.x, result.y
            depth = result.depth
            class_id = result.class_id
            class_name = result.class_name

            if depth <= 0.0:
                continue

            current_objects.append((cx, cy, depth, class_id, class_name))

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

        for obj_id, obj_data in self.tracked_objects.items():
            if obj_id not in updated_tracked and (current_time - obj_data["last_seen"]) < self.expiry_seconds:
                updated_tracked[obj_id] = obj_data

        self.tracked_objects = updated_tracked
        self.print_scene_graph()

    def print_scene_graph(self):
        timestamp = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
        self.get_logger().info(f"Scene Graph [{timestamp}]:")

        obj_list = list(self.tracked_objects.items())
        relations = []
        obj_support_map = {}
        obj_supported_by_object = {}

        for obj_id, obj in obj_list:
            cx, cy = obj["centroid"]
            d = obj["depth"]
            self.get_logger().info(
                f"  ID {obj_id}: {obj['class_name']} (class {obj['class_id']}) at ({round(cx,1)}, {round(cy,1)}), depth: {round(d,2)} m")

            obj_pos = np.array([cx, cy, d])
            supported_by = None
            min_dist = float('inf')

            for other_id, other_obj in obj_list:
                if other_id == obj_id:
                    continue
                ox, oy = other_obj["centroid"]
                od = other_obj["depth"]
                lateral_dist = np.linalg.norm([cx - ox, cy - oy])
                vertical_offset = od - d
                if lateral_dist < 80 and 0.005 < vertical_offset < 0.15:
                    if vertical_offset < min_dist:
                        supported_by = f"object_{other_id}"
                        obj_supported_by_object[obj_id] = other_id
                        min_dist = vertical_offset

            if supported_by is None:
                for surface in self.detected_surfaces:
                    normal = np.array(surface.normal)
                    center = np.array(surface.center)
                    to_obj = obj_pos - center
                    height_above = np.dot(to_obj, normal)
                    if abs(height_above) < 0.1:
                        dist = np.linalg.norm(to_obj)
                        if dist < min_dist:
                            supported_by = f"{surface.type}_{surface.id}"
                            min_dist = dist

            if supported_by:
                obj_support_map[obj_id] = supported_by
                if supported_by.startswith("floor_"):
                    relations.append(f"    Relation: {obj['class_name']} (ID {obj_id}) is on the floor")
                elif supported_by.startswith("object_"):
                    support_id = int(supported_by.split("_")[1])
                    support_name = self.tracked_objects.get(support_id, {}).get("class_name", "unknown")
                    relations.append(f"    Relation: {obj['class_name']} (ID {obj_id}) is on {support_name} (ID {support_id})")
                else:
                    relations.append(f"    Relation: {obj['class_name']} (ID {obj_id}) is on {supported_by}")

        def format_relation_phrase(terms):
            return " and ".join(["behind" if r == "behind" else "in front" if r == "in front of" else r for r in terms])

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

                skip_all_spatial = id1 in obj_supported_by_object or id2 in obj_supported_by_object
                same_support = obj_support_map.get(id1) == obj_support_map.get(id2)

                rel_1_to_2 = []
                rel_2_to_1 = []

                if not skip_all_spatial:
                    if abs(x2 - x1) > 20:
                        if x1 < x2:
                            rel_1_to_2.append("left")
                            rel_2_to_1.append("right")
                        else:
                            rel_1_to_2.append("right")
                            rel_2_to_1.append("left")

                    if not same_support and abs(y2 - y1) > 20:
                        if y1 < y2:
                            rel_1_to_2.append("above")
                            rel_2_to_1.append("below")
                        else:
                            rel_1_to_2.append("below")
                            rel_2_to_1.append("above")

                    if d1 > 0 and d2 > 0 and abs(d2 - d1) > 0.02:
                        if d1 < d2:
                            rel_1_to_2.append("in front of")
                            rel_2_to_1.append("behind")
                        else:
                            rel_1_to_2.append("behind")
                            rel_2_to_1.append("in front of")

                if rel_1_to_2:
                    phrase = format_relation_phrase(rel_1_to_2)
                    self.get_logger().info(f"    Relation: {name1} (ID {id1}) is to the {phrase} of {name2} (ID {id2})")
                if rel_2_to_1:
                    phrase = format_relation_phrase(rel_2_to_1)
                    self.get_logger().info(f"    Relation: {name2} (ID {id2}) is to the {phrase} of {name1} (ID {id1})")

        for r in relations:
            self.get_logger().info(r)

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
