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
  scripts/yolo_object_detection.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
) 