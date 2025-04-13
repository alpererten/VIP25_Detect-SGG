cmake_minimum_required(VERSION 2.8.3)
project(custom_msgs)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS
  message_generation
  std_msgs
)

## Declare ROS messages and services
add_message_files(
  DIRECTORY ${PROJECT_SOURCE_DIR}/msg
  FILES
  InferenceResult.msg
  YoloInference.msg
)

## Generate added messages and services
generate_messages(
  DEPENDENCIES
  std_msgs
)

## Declare a catkin package
catkin_package(
  CATKIN_DEPENDS message_runtime std_msgs
)

## Specify additional locations of header files
include_directories(
  ${catkin_INCLUDE_DIRS}
)
