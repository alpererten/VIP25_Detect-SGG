// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/SegmentationResult.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/segmentation_result__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__SegmentationResult__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xe6, 0x03, 0x60, 0x47, 0x00, 0x7e, 0xda, 0xe5,
      0x53, 0x44, 0x41, 0xec, 0x60, 0x82, 0xbd, 0xe1,
      0xf7, 0xdd, 0x76, 0x29, 0xce, 0xe0, 0x4f, 0xdc,
      0xf4, 0x38, 0xf6, 0xae, 0x74, 0x97, 0x0e, 0x15,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_msgs__msg__SegmentationResult__TYPE_NAME[] = "custom_msgs/msg/SegmentationResult";

// Define type names, field names, and default values
static char custom_msgs__msg__SegmentationResult__FIELD_NAME__class_id[] = "class_id";
static char custom_msgs__msg__SegmentationResult__FIELD_NAME__class_name[] = "class_name";
static char custom_msgs__msg__SegmentationResult__FIELD_NAME__x[] = "x";
static char custom_msgs__msg__SegmentationResult__FIELD_NAME__y[] = "y";
static char custom_msgs__msg__SegmentationResult__FIELD_NAME__width[] = "width";
static char custom_msgs__msg__SegmentationResult__FIELD_NAME__height[] = "height";
static char custom_msgs__msg__SegmentationResult__FIELD_NAME__depth[] = "depth";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__SegmentationResult__FIELDS[] = {
  {
    {custom_msgs__msg__SegmentationResult__FIELD_NAME__class_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__SegmentationResult__FIELD_NAME__class_name, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__SegmentationResult__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__SegmentationResult__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__SegmentationResult__FIELD_NAME__width, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__SegmentationResult__FIELD_NAME__height, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__SegmentationResult__FIELD_NAME__depth, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_msgs__msg__SegmentationResult__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__SegmentationResult__TYPE_NAME, 34, 34},
      {custom_msgs__msg__SegmentationResult__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int64 class_id\n"
  "string class_name\n"
  "float64 x\n"
  "float64 y\n"
  "float64 width\n"
  "float64 height\n"
  "float64 depth";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__msg__SegmentationResult__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__SegmentationResult__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 96, 96},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__SegmentationResult__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__SegmentationResult__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
