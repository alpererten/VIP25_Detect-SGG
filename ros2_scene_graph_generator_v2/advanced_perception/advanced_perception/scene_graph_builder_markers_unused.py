import rclpy
from rclpy.node import Node
from visualization_msgs.msg import Marker, MarkerArray
from geometry_msgs.msg import Point  # ✅ Correct import for Point
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

        self.marker_pub = self.create_publisher(MarkerArray, '/scene_graph_markers', 10)

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
            surface.type = 'floor' if height < 0.15 else 'table'
            self.detected_surfaces.append(surface)

    def segmentation_callback(self, msg):
        current_time = time.time()
        current_objects = []

        self.get_logger().info(f"Received {len(msg.yolo_segmentation_msg)} objects from segmentation.")

        for result in msg.yolo_segmentation_msg[:50]:
            cx, cy = result.x, result.y
            depth = result.depth
            if depth <= 0.0:
                continue
            current_objects.append((cx, cy, depth, result.class_id, result.class_name))

        updated_tracked = {}

        for cx, cy, depth, class_id, class_name in current_objects:
            matched_id = None
            for obj_id, obj_data in self.tracked_objects.items():
                ox, oy = obj_data["centroid"]
                dist = np.linalg.norm([cx - ox, cy - oy])
                if dist < self.max_tracking_distance and obj_data["class_id"] == class_id:
                    matched_id = obj_id
                    break

            obj_info = {
                "centroid": (cx, cy),
                "depth": depth,
                "class_id": class_id,
                "class_name": class_name,
                "last_seen": current_time
            }

            if matched_id is not None:
                updated_tracked[matched_id] = obj_info
            else:
                updated_tracked[self.object_id_counter] = obj_info
                self.object_id_counter += 1

        for obj_id, obj_data in self.tracked_objects.items():
            if obj_id not in updated_tracked and (current_time - obj_data["last_seen"]) < self.expiry_seconds:
                updated_tracked[obj_id] = obj_data

        self.tracked_objects = updated_tracked
        self.print_scene_graph()

    def print_scene_graph(self):
        timestamp = time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())
        self.get_logger().info(f"Scene Graph [{timestamp}]:")
        obj_list = list(self.tracked_objects.items())

        # RViz visualization
        markers = MarkerArray()
        header_frame = "map"
        edge_id = 2000

        for idx, (obj_id, obj) in enumerate(obj_list):
            cx, cy, cz = obj["centroid"][0], obj["centroid"][1], obj["depth"]
            label = obj["class_name"]

            # Sphere marker
            m = Marker()
            m.header.frame_id = header_frame
            m.id = obj_id
            m.type = Marker.SPHERE
            m.action = Marker.ADD
            m.pose.position.x = cx / 100.0
            m.pose.position.y = cy / 100.0
            m.pose.position.z = cz
            m.scale.x = m.scale.y = m.scale.z = 0.05
            m.color.r = 0.0
            m.color.g = 1.0
            m.color.b = 0.0
            m.color.a = 1.0
            m.lifetime.sec = 2
            markers.markers.append(m)

            # Text label
            t = Marker()
            t.header.frame_id = header_frame
            t.id = 1000 + obj_id
            t.type = Marker.TEXT_VIEW_FACING
            t.action = Marker.ADD
            t.pose.position.x = cx / 100.0
            t.pose.position.y = cy / 100.0
            t.pose.position.z = cz + 0.05
            t.scale.z = 0.04
            t.color.r = t.color.g = t.color.b = 1.0
            t.color.a = 1.0
            t.text = f"{label} ({obj_id})"
            t.lifetime.sec = 2
            markers.markers.append(t)

        for i in range(len(obj_list)):
            id1, obj1 = obj_list[i]
            x1, y1, d1 = obj1["centroid"][0], obj1["centroid"][1], obj1["depth"]
            name1 = obj1["class_name"]

            for j in range(i + 1, len(obj_list)):
                id2, obj2 = obj_list[j]
                x2, y2, d2 = obj2["centroid"][0], obj2["centroid"][1], obj2["depth"]
                name2 = obj2["class_name"]

                # RViz Arrow Marker
                arrow = Marker()
                arrow.header.frame_id = header_frame
                arrow.id = edge_id
                arrow.type = Marker.ARROW
                arrow.action = Marker.ADD
                arrow.points = [
                    Point(x=x1 / 100.0, y=y1 / 100.0, z=d1),
                    Point(x=x2 / 100.0, y=y2 / 100.0, z=d2)
                ]
                arrow.scale.x = 0.01
                arrow.scale.y = 0.02
                arrow.scale.z = 0.03
                arrow.color.r = 1.0
                arrow.color.g = 0.0
                arrow.color.b = 0.0
                arrow.color.a = 1.0
                arrow.lifetime.sec = 2
                markers.markers.append(arrow)
                edge_id += 1

        self.marker_pub.publish(markers)


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
