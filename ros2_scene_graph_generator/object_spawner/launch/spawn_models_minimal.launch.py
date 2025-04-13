import launch
from launch import LaunchDescription
from launch_ros.actions import Node
import os

def generate_launch_description():
    local_models_dir = os.path.expanduser('~/ros2_ws/simulations/models')

    apple_model_path = os.path.join(local_models_dir, 'apple', 'model.sdf')
    banana_model_path = os.path.join(local_models_dir, 'banana', 'model.sdf')
    tennis_ball_model_path = os.path.join(local_models_dir, 'tennis_ball', 'model.sdf')

    bench_height = 0.42

    apple1_position = [0.0, -6.3, bench_height]
    apple2_position = [-0.2, -6.1, bench_height]
    banana3_position = [-0.2, -5.8, bench_height, 1.4]  # ⬅️ Using banana3 now
    tennis_ball1_position = [-0.1, -5.4, bench_height+0.03, 0.2]

    spawn_apple1 = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        name='spawn_apple1',
        arguments=[
            '-entity', 'apple1',
            '-file', apple_model_path,
            '-x', str(apple1_position[0]),
            '-y', str(apple1_position[1]),
            '-z', str(apple1_position[2])
        ],
        output='screen'
    )

    spawn_apple2 = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        name='spawn_apple2',
        arguments=[
            '-entity', 'apple2',
            '-file', apple_model_path,
            '-x', str(apple2_position[0]),
            '-y', str(apple2_position[1]),
            '-z', str(apple2_position[2])
        ],
        output='screen'
    )

    spawn_banana3 = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        name='spawn_banana3',
        arguments=[
            '-entity', 'banana3',
            '-file', banana_model_path,
            '-x', str(banana3_position[0]),
            '-y', str(banana3_position[1]),
            '-z', str(banana3_position[2]),
            '-Y', str(banana3_position[3])
        ],
        output='screen'
    )

    spawn_tennis_ball1 = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        name='spawn_tennis_ball1',
        arguments=[
            '-entity', 'tennis_ball1',
            '-file', tennis_ball_model_path,
            '-x', str(tennis_ball1_position[0]),
            '-y', str(tennis_ball1_position[1]),
            '-z', str(tennis_ball1_position[2]),
            '-Y', str(tennis_ball1_position[3])
        ],
        output='screen'
    )

    return LaunchDescription([
        spawn_apple1,
        spawn_apple2,
        spawn_banana3,  # ⬅️ Updated reference
        spawn_tennis_ball1,
    ])
