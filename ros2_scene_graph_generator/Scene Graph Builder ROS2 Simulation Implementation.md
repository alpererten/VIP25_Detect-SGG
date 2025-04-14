
# Commands to activate the person follower package and YOLOv8 detection package and run in simulation:


# Note: You'll likely need to install the required packages used for the YOLO object detection node:
- rclpy
- ultralytics library
- cv_bridge


# Launch objecs withing the existing simulation environment
```bash
source /home/simulations/ros2_sims_ws/install/setup.bash
source ~/ros2_ws/install/setup.bash
ros2 launch object_spawner spawn_models_minimal.launch.py
```

# Tilt Robot's head down (Terminal 1) - simulation specific command, should be ignored in lab robot trial
```bash
source /home/simulations/ros2_sims_ws/install/setup.bash
ros2 run deepmind_bot_trajectory_sender move_head.py 0.0 0.7 1
```

# Activate robot controller (Terminal 2) - ignore in lab robot trial
```bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```

# Launch RViz2 (Terminal 2) - the second line is for the specific course simulation environment only and can be replaced by "rviz2" command otherwise
```bash
source /home/simulations/ros2_sims_ws/install/setup.bash
rviz2 -d /home/simulations/ros2_sims_ws/src/course_perception_ros2_files/perception_ros2/rviz/yolo_segmentation.rviz
```

# Compile and Turn on yolo object segmentation node (Terminal 3) 
```bash
cd ~/ros2_ws/
colcon build;source install/setup.bash
ros2 run advanced_perception yolo_segmentation
```
python3 src/advanced_perception/advanced_perception/yolo_segmentation.py

# Compile and run to create a snapshot image of the detected object pixel clouds (Terminal 4) - OPTIONAL STEP
```bash
cd ~/ros2_ws/
colcon build;source install/setup.bash
ros2 run advanced_perception yolo_object_mask_saver
```

# Compile and run to build scene graph generation node (Terminal 5)
```bash
cd ~/ros2_ws/
colcon build;source install/setup.bash
ros2 run advanced_perception scene_graph_builder
```


