# Commands to build the YOLOv8 detection package in ROS Noetic:

# Note
you may need to install the following packages for YOLO to work in your local machine
```bash
sudo pip3 install ultralytics      
pip3 install opencv-python
sudo apt-get install ros-noetic-cv-bridge
``` 

# Note
Change the camera topic name referenced inside the yolo_object_detection.py node to match the name of your local camera topic name (see comment on line 25 in yolo_object_detection.py)

# build and source your workspace:
# change this directory name to match your local setup for ros workspace
```bash
cd ~/catkin_ws      #change this directory name to match your local setup for ros workspace
catkin_make
source devel/setup.bash
```

# Start the ROS master in a new terminal:
```bash
roscore
```

# In another terminal, run your YOLO detection node:
```bash
rosrun advanced_perception yolo_object_detection.py
```

# To visualize the results in RViz, open RViz in another terminal
```bash
rosrun rviz rviz
```

# In RViz:
# Add an Image display (Click "Add" → "By topic" → Select "/inference_result")
# Set the Fixed Frame to "inference" in Global Options