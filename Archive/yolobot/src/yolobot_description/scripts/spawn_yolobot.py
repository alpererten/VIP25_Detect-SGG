#!/usr/bin/python3
import os
import sys
import rclpy
from ros_gz_interfaces.srv import SpawnEntity
from ament_index_python.packages import get_package_share_directory
from pathlib import Path

def main():
    # Get input arguments from user
    argv = sys.argv[1:]

    # Start node
    rclpy.init()
    node = rclpy.create_node("entity_spawner")

    node.get_logger().info(
        'Creating Service client to connect to `/spawn_entity`')
    client = node.create_client(SpawnEntity, "/spawn_entity")

    node.get_logger().info("Connecting to `/spawn_entity` service...")
    if not client.service_is_ready():
        client.wait_for_service()
        node.get_logger().info("...connected!")

    # Get path to urdf
    sdf_file_path = argv[0]
    node.get_logger().info('robot_sdf: {}'.format(sdf_file_path))

    # Set data for request
    request = SpawnEntity.Request()
    request.name = 'yolobot'
    request.xml = Path(sdf_file_path).read_text()
    request.initial_pose.position.x = 0.0
    request.initial_pose.position.y = 0.0
    request.initial_pose.position.z = 0.0

    node.get_logger().info("Sending service request to `/spawn_entity`")
    future = client.call_async(request)
    rclpy.spin_until_future_complete(node, future)
    if future.result() is not None:
        node.get_logger().info('response: {}'.format(future.result()))
    else:
        raise RuntimeError(
            'exception while calling service: {}'.format(future.exception()))

    node.get_logger().info('Done! Shutting down node.')
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
