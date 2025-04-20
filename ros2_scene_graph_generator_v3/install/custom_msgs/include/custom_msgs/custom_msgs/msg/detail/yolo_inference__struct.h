// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/YoloInference.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/yolo_inference.h"


#ifndef CUSTOM_MSGS__MSG__DETAIL__YOLO_INFERENCE__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__YOLO_INFERENCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'yolo_inference'
#include "custom_msgs/msg/detail/inference_result__struct.h"

/// Struct defined in msg/YoloInference in the package custom_msgs.
typedef struct custom_msgs__msg__YoloInference
{
  std_msgs__msg__Header header;
  custom_msgs__msg__InferenceResult__Sequence yolo_inference;
} custom_msgs__msg__YoloInference;

// Struct for a sequence of custom_msgs__msg__YoloInference.
typedef struct custom_msgs__msg__YoloInference__Sequence
{
  custom_msgs__msg__YoloInference * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__YoloInference__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__YOLO_INFERENCE__STRUCT_H_
