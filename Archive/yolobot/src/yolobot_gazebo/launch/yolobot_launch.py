#!/usr/bin/python3
# -*- coding: utf-8 -*-
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, IncludeLaunchDescription
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():

    pkg_yolobot_gazebo = get_package_share_directory('yolobot_gazebo')
    pkg_yolobot_description = get_package_share_directory('yolobot_description')
    pkg_yolobot_control = get_package_share_directory('yolobot_control')
    pkg_yolobot_recognition = get_package_share_directory('yolobot_recognition')

    # Read URDF contents
    urdf_file = os.path.join(pkg_yolobot_description, 'robot', 'yolobot.urdf')
    with open(urdf_file, 'r') as infp:
        robot_desc = infp.read()

    # Start world
    start_world = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(pkg_yolobot_gazebo, 'launch', 'start_world_launch.py')
        )
    )

    # Spawn robot
    spawn_robot = Node(
        package='yolobot_description',
        executable='spawn_yolobot.py',
        arguments=[urdf_file],
        output='screen'
    )

    # Start robot state publisher
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[{
            'robot_description': robot_desc,
            'use_sim_time': True
        }]
    )

    # Start controller
    robot_controller = Node(
        package='yolobot_control',
        executable='robot_control.py',
        output='screen'
    )

    # Start YOLO node
    yolo_node = Node(
        package='yolobot_recognition',
        executable='yolov8_ros2_pt.py',
        name='yolov8_ros2_pt',
        output='screen'
    )

    # Start joystick
    joy_node = Node(
        package='joy',
        executable='joy_node',
        name='joy_node',
        parameters=[{
            'dev': '/dev/input/js0',
            'deadzone': 0.3,
            'autorepeat_rate': 20.0,
        }]
    )

    return LaunchDescription([
        start_world,
        spawn_robot,
        robot_state_publisher,
        robot_controller,
        yolo_node,
        joy_node
    ])