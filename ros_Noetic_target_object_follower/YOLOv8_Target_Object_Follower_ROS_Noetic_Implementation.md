# Commands to build the YOLOv8 detection package in ROS Noetic:

# Note
you may need to install the following packages for YOLO to work on your local machine
```bash
pip3 install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cpu  #required for virtual machine or low RAM machine installations only
sudo pip3 install ultralytics      
pip3 install opencv-python
sudo apt-get install ros-noetic-cv-bridge
``` 

# Note
Change the camera topic name referenced inside the yolo_object_detection.py node to match the name of your local camera topic name (see comment on line 25 in yolo_object_detection.py)

# build and source your workspace:
# change this directory name to match your local setup for ros workspace
```bash
cd ~/catkin_ws      
catkin_make
source devel/setup.bash
```

# Start the ROS master in a new terminal:
```bash
roscore
```

# In another terminal, run your YOLO detection node:
```bash
cd ~/catkin_ws  
rosrun advanced_perception yolov8_object_detection.py
```


# To visualize the results in RViz, open RViz in another terminal
```bash
rosrun rviz rviz
```

# To run the target object follower in a new terminal, the first line assings the target object class, replace 'person' with any other target class
```bash
cd ~/catkin_ws
rosparam set /target_object_follower/target_object person
rosrun advanced_perception yolo_target_object_follower.py
```

# In RViz:
# Add an Image display (Click "Add" → "By topic" → Select "/inference_result")
# Set the Fixed Frame to "inference" in Global Options