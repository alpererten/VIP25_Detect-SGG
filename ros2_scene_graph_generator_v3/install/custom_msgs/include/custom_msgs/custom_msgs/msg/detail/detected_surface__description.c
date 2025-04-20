// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/DetectedSurface.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/detected_surface__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__DetectedSurface__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfa, 0x1a, 0x5e, 0x05, 0x87, 0x1b, 0x6a, 0xa9,
      0xa6, 0xbf, 0xc9, 0xa9, 0xdd, 0xa8, 0x36, 0xc8,
      0x26, 0xd5, 0xaa, 0xac, 0x12, 0xb6, 0xd8, 0x4e,
      0xa4, 0xee, 0x7b, 0x88, 0x99, 0x0b, 0x0f, 0x36,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_msgs__msg__DetectedSurface__TYPE_NAME[] = "custom_msgs/msg/DetectedSurface";

// Define type names, field names, and default values
static char custom_msgs__msg__DetectedSurface__FIELD_NAME__id[] = "id";
static char custom_msgs__msg__DetectedSurface__FIELD_NAME__type[] = "type";
static char custom_msgs__msg__DetectedSurface__FIELD_NAME__normal[] = "normal";
static char custom_msgs__msg__DetectedSurface__FIELD_NAME__center[] = "center";
static char custom_msgs__msg__DetectedSurface__FIELD_NAME__confidence[] = "confidence";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__DetectedSurface__FIELDS[] = {
  {
    {custom_msgs__msg__DetectedSurface__FIELD_NAME__id, 2, 2},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__DetectedSurface__FIELD_NAME__type, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__DetectedSurface__FIELD_NAME__normal, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__DetectedSurface__FIELD_NAME__center, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__DetectedSurface__FIELD_NAME__confidence, 10, 10},
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
custom_msgs__msg__DetectedSurface__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__DetectedSurface__TYPE_NAME, 31, 31},
      {custom_msgs__msg__DetectedSurface__FIELDS, 5, 5},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 id\n"
  "string type           # e.g., \"floor\", \"table\", or \"unknown\"\n"
  "float64[3] normal     # surface normal vector (a, b, c)\n"
  "float64[3] center     # surface center point (x, y, z)\n"
  "float64 confidence    # currently using number of inlier points\n"
  "";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__msg__DetectedSurface__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__DetectedSurface__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 246, 246},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__DetectedSurface__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__DetectedSurface__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
