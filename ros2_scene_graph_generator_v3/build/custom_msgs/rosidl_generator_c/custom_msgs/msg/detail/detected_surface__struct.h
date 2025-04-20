// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/DetectedSurface.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/detected_surface.h"


#ifndef CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACE__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DetectedSurface in the package custom_msgs.
typedef struct custom_msgs__msg__DetectedSurface
{
  int32_t id;
  /// e.g., "floor", "table", or "unknown"
  rosidl_runtime_c__String type;
  /// surface normal vector (a, b, c)
  double normal[3];
  /// surface center point (x, y, z)
  double center[3];
  /// currently using number of inlier points
  double confidence;
} custom_msgs__msg__DetectedSurface;

// Struct for a sequence of custom_msgs__msg__DetectedSurface.
typedef struct custom_msgs__msg__DetectedSurface__Sequence
{
  custom_msgs__msg__DetectedSurface * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__DetectedSurface__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACE__STRUCT_H_
