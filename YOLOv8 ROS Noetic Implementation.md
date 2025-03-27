#Commands to build the YOLOv8 detection package in ROS Noetic:

#build and source your workspace:
cd ~/ros_noetic_ws_YOLO_detector
catkin_make
source devel/setup.bash

#Start the ROS master in a new terminal:
roscore

#In another terminal, run your YOLO detection node:
rosrun advanced_perception yolo_object_detection.py

#To visualize the results in RViz, open RViz in another terminal
rosrun rviz rviz


#In RViz:
#Add an Image display (Click "Add" → "By topic" → Select "/inference_result")
#Set the Fixed Frame to "inference" in Global Options


