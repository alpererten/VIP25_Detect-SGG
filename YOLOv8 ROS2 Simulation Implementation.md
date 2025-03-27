# Commands to activate the YOLOv8 detection package and run in simulation:

# Note: You'll likely need to install the required packages used for the YOLO object detection node:
-rclpy
-ultralytics library
-cv_bridge

# Launch RViz2 (Terminal 1)
```bash
source /home/simulations/ros2_sims_ws/install/setup.bash
rviz2 -d /home/simulations/ros2_sims_ws/src/course_perception_ros2_files/perception_ros2/rviz/yolo_object_detection.rviz
```

# Create the fruits in simulation (Terminal 2)
```bash
source /home/simulations/ros2_sims_ws/install/setup.bash
ros2 launch perception_ros2 spawn_fruits.launch.py
```

# Activate robot controller (Terminal 2)
```bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```

# Tilt Robot's head down (Terminal 3)
```bash
source /home/simulations/ros2_sims_ws/install/setup.bash
ros2 run deepmind_bot_trajectory_sender move_head.py 0.0 0.5 1
```

# Turn on yolo detection node (Terminal 4)
```bash
cd ~/ros2_ws/
colcon build; source install/setup.bash
ros2 run advanced_perception yolo_object_detection
```