// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/SegmentationResult.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/segmentation_result.h"


#ifndef CUSTOM_MSGS__MSG__DETAIL__SEGMENTATION_RESULT__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__SEGMENTATION_RESULT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'class_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SegmentationResult in the package custom_msgs.
typedef struct custom_msgs__msg__SegmentationResult
{
  int64_t class_id;
  rosidl_runtime_c__String class_name;
  double x;
  double y;
  double width;
  double height;
  double depth;
} custom_msgs__msg__SegmentationResult;

// Struct for a sequence of custom_msgs__msg__SegmentationResult.
typedef struct custom_msgs__msg__SegmentationResult__Sequence
{
  custom_msgs__msg__SegmentationResult * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__SegmentationResult__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__SEGMENTATION_RESULT__STRUCT_H_
