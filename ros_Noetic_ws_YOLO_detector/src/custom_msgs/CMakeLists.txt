cmake_minimum_required(VERSION 3.0.2)
project(custom_msgs)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  std_msgs
  sensor_msgs
)

# Generate messages
add_message_files(
  FILES
  InferenceResult.msg
  Yolov8Inference.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime std_msgs sensor_msgs
)
