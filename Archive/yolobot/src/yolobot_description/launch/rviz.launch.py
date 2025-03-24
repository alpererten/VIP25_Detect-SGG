from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    pkg_yolobot_description = get_package_share_directory('yolobot_description')
    
    rviz_config = os.path.join(pkg_yolobot_description, 'rviz', 'robot_view.rviz')
    
    return LaunchDescription([
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_config],
            output='screen'
        )
    ]) 