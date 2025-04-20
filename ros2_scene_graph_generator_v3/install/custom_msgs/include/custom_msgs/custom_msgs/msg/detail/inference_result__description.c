// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/InferenceResult.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/inference_result__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__InferenceResult__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x51, 0x29, 0x15, 0xd4, 0xe0, 0x0c, 0x73, 0xb0,
      0x85, 0x52, 0xb4, 0x00, 0xad, 0x59, 0x9a, 0xf5,
      0x01, 0xc9, 0x5b, 0xf2, 0xa4, 0x06, 0x96, 0xd1,
      0x2d, 0x1a, 0x3c, 0x66, 0xf0, 0x8c, 0x1f, 0xde,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_msgs__msg__InferenceResult__TYPE_NAME[] = "custom_msgs/msg/InferenceResult";

// Define type names, field names, and default values
static char custom_msgs__msg__InferenceResult__FIELD_NAME__class_name[] = "class_name";
static char custom_msgs__msg__InferenceResult__FIELD_NAME__top[] = "top";
static char custom_msgs__msg__InferenceResult__FIELD_NAME__left[] = "left";
static char custom_msgs__msg__InferenceResult__FIELD_NAME__bottom[] = "bottom";
static char custom_msgs__msg__InferenceResult__FIELD_NAME__right[] = "right";
static char custom_msgs__msg__InferenceResult__FIELD_NAME__box_width[] = "box_width";
static char custom_msgs__msg__InferenceResult__FIELD_NAME__box_height[] = "box_height";
static char custom_msgs__msg__InferenceResult__FIELD_NAME__x[] = "x";
static char custom_msgs__msg__InferenceResult__FIELD_NAME__y[] = "y";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__InferenceResult__FIELDS[] = {
  {
    {custom_msgs__msg__InferenceResult__FIELD_NAME__class_name, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__InferenceResult__FIELD_NAME__top, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__InferenceResult__FIELD_NAME__left, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__InferenceResult__FIELD_NAME__bottom, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__InferenceResult__FIELD_NAME__right, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__InferenceResult__FIELD_NAME__box_width, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__InferenceResult__FIELD_NAME__box_height, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__InferenceResult__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__InferenceResult__FIELD_NAME__y, 1, 1},
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
custom_msgs__msg__InferenceResult__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__InferenceResult__TYPE_NAME, 31, 31},
      {custom_msgs__msg__InferenceResult__FIELDS, 9, 9},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string class_name\n"
  "int64 top\n"
  "int64 left\n"
  "int64 bottom\n"
  "int64 right\n"
  "int64 box_width\n"
  "int64 box_height\n"
  "float64 x\n"
  "float64 y";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__msg__InferenceResult__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__InferenceResult__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 117, 117},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__InferenceResult__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__InferenceResult__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
