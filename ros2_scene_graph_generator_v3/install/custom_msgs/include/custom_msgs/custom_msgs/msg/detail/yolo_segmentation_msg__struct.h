// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/YoloSegmentationMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/yolo_segmentation_msg.h"


#ifndef CUSTOM_MSGS__MSG__DETAIL__YOLO_SEGMENTATION_MSG__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__YOLO_SEGMENTATION_MSG__STRUCT_H_

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
// Member 'yolo_segmentation_msg'
#include "custom_msgs/msg/detail/segmentation_result__struct.h"

/// Struct defined in msg/YoloSegmentationMsg in the package custom_msgs.
typedef struct custom_msgs__msg__YoloSegmentationMsg
{
  std_msgs__msg__Header header;
  custom_msgs__msg__SegmentationResult__Sequence yolo_segmentation_msg;
} custom_msgs__msg__YoloSegmentationMsg;

// Struct for a sequence of custom_msgs__msg__YoloSegmentationMsg.
typedef struct custom_msgs__msg__YoloSegmentationMsg__Sequence
{
  custom_msgs__msg__YoloSegmentationMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__YoloSegmentationMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__YOLO_SEGMENTATION_MSG__STRUCT_H_
