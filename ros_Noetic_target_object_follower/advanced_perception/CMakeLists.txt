cmake_minimum_required(VERSION 3.0.2)
project(advanced_perception)

find_package(catkin REQUIRED COMPONENTS
  rospy
  sensor_msgs
  custom_msgs
)

catkin_package(
  CATKIN_DEPENDS rospy sensor_msgs custom_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

catkin_install_python(PROGRAMS
  scripts/yolov8_object_detection.py
  scripts/yolo_target_object_follower.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
) 