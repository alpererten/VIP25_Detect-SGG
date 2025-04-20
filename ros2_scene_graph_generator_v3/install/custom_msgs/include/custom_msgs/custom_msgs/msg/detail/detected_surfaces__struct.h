// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/DetectedSurfaces.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/detected_surfaces.h"


#ifndef CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACES__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACES__STRUCT_H_

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
// Member 'surfaces'
#include "custom_msgs/msg/detail/detected_surface__struct.h"

/// Struct defined in msg/DetectedSurfaces in the package custom_msgs.
typedef struct custom_msgs__msg__DetectedSurfaces
{
  std_msgs__msg__Header header;
  custom_msgs__msg__DetectedSurface__Sequence surfaces;
} custom_msgs__msg__DetectedSurfaces;

// Struct for a sequence of custom_msgs__msg__DetectedSurfaces.
typedef struct custom_msgs__msg__DetectedSurfaces__Sequence
{
  custom_msgs__msg__DetectedSurfaces * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__DetectedSurfaces__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACES__STRUCT_H_
