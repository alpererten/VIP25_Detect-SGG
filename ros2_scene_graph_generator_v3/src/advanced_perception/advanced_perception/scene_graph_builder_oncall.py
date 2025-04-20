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
        self.ema_alpha = 0.4

        self.get_logger().info("SceneGraphBuilder node initialized and listening to /Yolo_segmentation and /detected_surfaces")

        self.received_log_interval = 2.0   ########################
        self.last_received_log_time = 0
        self.last_scene_signature = []

        self.generate_mode = 'continuous'  # Options: 'on_call' or 'continuous'   #######################
        if self.generate_mode == 'continuous':
            self.timer = self.create_timer(self.received_log_interval, self.timer_callback)

        self.depth_tolerance = 0.03  # meters
        self.pixel_tolerance = 6     # pixels

    def surfaces_callback(self, msg):
        self.detected_surfaces = []
        for s in msg.surfaces:
            surface = s
            height = s.center[2]
            surface.type = 'floor' if height < 0.15 else 'table'
            self.detected_surfaces.append(surface)

    def segmentation_callback(self, msg):
        current_time = time.time()
        current_objects = []

        #if current_time - self.last_received_log_time > self.received_log_interval:
            #self.get_logger().info(f"Received {len(msg.yolo_segmentation_msg)} objects from segmentation.")

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
                prev = self.tracked_objects[matched_id]
                smoothed_cx = self.ema_alpha * cx + (1 - self.ema_alpha) * prev["centroid"][0]
                smoothed_cy = self.ema_alpha * cy + (1 - self.ema_alpha) * prev["centroid"][1]
                smoothed_depth = self.ema_alpha * depth + (1 - self.ema_alpha) * prev["depth"]
                updated_tracked[matched_id] = {
                    "centroid": (smoothed_cx, smoothed_cy),
                    "depth": smoothed_depth,
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

        if self.generate_mode == 'on_call':
            self.print_scene_graph(force=False)

    def timer_callback(self):
        self.print_scene_graph(force=True)

    def is_significantly_different(self, sig1, sig2):
        if len(sig1) != len(sig2):
            return True
        for (id1, cls1, x1, y1, d1), (id2, cls2, x2, y2, d2) in zip(sig1, sig2):
            if id1 != id2 or cls1 != cls2:
                return True
            if abs(x1 - x2) > self.pixel_tolerance:
                return True
            if abs(y1 - y2) > self.pixel_tolerance:
                return True
            if abs(d1 - d2) > self.depth_tolerance:
                return True
        return False

    def print_scene_graph(self, force=False):
        if not self.tracked_objects:
            return

        obj_list = sorted(self.tracked_objects.items(), key=lambda x: x[0])

        obj_support_map = {}
        obj_supported_by_object = {}
        graph_lines = []
        semantic_key = []
        relation_map = {}

        timestamp = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
        graph_lines.append(f"Scene Graph [{timestamp}]:")

        for obj_id, obj in obj_list:
            cx, cy = obj["centroid"]
            d = obj["depth"]

            bin_x = int(cx / 6) * 6
            bin_y = int(cy / 6) * 6
            rd = round(d, 2)

            graph_lines.append(
                f"  ID {obj_id}: {obj['class_name']} (class {obj['class_id']}) at ({bin_x}, {bin_y}), depth: {rd} m")

            semantic_key.append((obj_id, obj['class_name'], bin_x, bin_y, rd))

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

        def inverse_relation(rel):
            return {
                "to the left of": "to the right of",
                "to the right of": "to the left of",
                "in front of": "behind",
                "behind": "in front of",
                "above": "below",
                "below": "above"
            }.get(rel, rel)

        def record_relation(name1, id1, rel, name2, id2):
            key = (name1, id1, name2, id2)
            relation_map.setdefault(key, []).append(rel)

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

                skip_spatial = id1 in obj_supported_by_object or id2 in obj_supported_by_object
                same_support = obj_support_map.get(id1) == obj_support_map.get(id2)

                if not skip_spatial:
                    if abs(x2 - x1) > 20:
                        if x1 < x2:
                            record_relation(name1, id1, "to the left of", name2, id2)
                        else:
                            record_relation(name1, id1, "to the right of", name2, id2)

                    if not same_support and abs(y2 - y1) > 20:
                        if y1 < y2:
                            record_relation(name1, id1, "above", name2, id2)
                        else:
                            record_relation(name1, id1, "below", name2, id2)

                    if d1 > 0 and d2 > 0 and abs(d2 - d1) > 0.01:
                        if d1 < d2:
                            record_relation(name1, id1, "in front of", name2, id2)
                        else:
                            record_relation(name1, id1, "behind", name2, id2)

        current_time = time.time()
        scene_changed = self.is_significantly_different(semantic_key, self.last_scene_signature)
        enough_time_passed = (current_time - self.last_received_log_time) > self.received_log_interval

        if force or (scene_changed and enough_time_passed):
            for (name1, id1, name2, id2), relations in relation_map.items():
                combined = " and ".join(relations)
                graph_lines.append(f"    Relation: {name1} (ID {id1}) is {combined} {name2} (ID {id2})")
                inverse_combined = " and ".join([inverse_relation(r) for r in relations])
                graph_lines.append(f"    Relation: {name2} (ID {id2}) is {inverse_combined} {name1} (ID {id1})")

            for line in graph_lines:
                self.get_logger().info(line)

            self.last_scene_signature = semantic_key
            self.last_received_log_time = current_time

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
