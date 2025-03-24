#!/usr/bin/python3
# -*- coding: utf-8 -*-
import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    pkg_yolobot_gazebo = get_package_share_directory('yolobot_gazebo')
    
    # Set Gazebo model path
    if 'GZ_SIM_RESOURCE_PATH' in os.environ:
        os.environ['GZ_SIM_RESOURCE_PATH'] = f"{os.environ['GZ_SIM_RESOURCE_PATH']}:/usr/share/gz/models"
    else:
        os.environ['GZ_SIM_RESOURCE_PATH'] = "/usr/share/gz/models"

    # Start Gazebo with our world
    gz_sim = ExecuteProcess(
        cmd=['gz', 'sim', '-v4',  # Added verbose flag for debugging
             os.path.join(pkg_yolobot_gazebo, 'worlds', 'yolo_test.world')],
        output='screen',
        additional_env={
            'GZ_SIM_RESOURCE_PATH': '/usr/share/gz/models',
            'GZ_SIM_SYSTEM_PLUGIN_PATH': '/usr/lib/x86_64-linux-gnu/gz-sim-8/plugins',  # Updated for Harmonic
        }
    )

    return LaunchDescription([
        gz_sim
    ])