from launch import LaunchDescription
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_yolobot_description = get_package_share_directory('yolobot_description')

    return LaunchDescription([
        Node(
            package='yolobot_description',
            executable='spawn_yolobot.py',
            arguments=[os.path.join(pkg_yolobot_description, 'robot', 'yolobot.urdf')],
            output='screen'
        )
    ])