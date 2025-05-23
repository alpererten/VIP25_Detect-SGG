
# Commands to activate the person follower package and YOLOv8 detection package and run in simulation:
- The tested simulation assumes that the robot is controlled by a diff_drive_controller which subscribes to the cmd_vel publisher created within the yolo_person_follower.py code
```bash
cd ~/ros2_ws/src
git clone https://github.com/ros-controls/ros2_controllers.git
cd ros2_controllers/diff_drive_controller
```

# Note: You'll likely need to install the required packages used for the YOLO object detection node:
- rclpy
- ultralytics library
- cv_bridge

# Launch RViz2 (Terminal 1) - the second line is for the specific course simulation environment only and can be replaced by "rviz2" command otherwise
```bash
source /home/simulations/ros2_sims_ws/install/setup.bash 
rviz2 -d /home/simulations/ros2_sims_ws/src/course_perception_ros2_files/perception_ros2/rviz/yolo_person_follower.rviz
```

# Tilt Robot's head down (Terminal 2) - simulation specific command, should be ignored in lab robot trial
```bash
source /home/simulations/ros2_sims_ws/install/setup.bash
ros2 run deepmind_bot_trajectory_sender move_head.py 0.0 0.0 1
```

# Activate robot controller (Terminal 2) - ignore in lab robot trial
```bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard
```


# Compile and Turn on yolo detection node (Terminal 3)
```bash
cd ~/ros2_ws/
colcon build; source install/setup.bash
ros2 run advanced_perception yolov8_object_detection
```


# Compile and Turn on person follower node (Terminal 4)
# you can assing the target_object parameter to any other object class that is within the COCO dataset such as bench, chair, apple,...etc
```bash
cd ~/ros2_ws/
colcon build;source install/setup.bash
ros2 ros2 run advanced_perception yolo_target_object_follower --ros-args -p target_object:=person
```




