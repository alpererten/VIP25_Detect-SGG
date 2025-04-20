// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_msgs:msg/YoloSegmentationMsg.idl
// generated code does not contain a copyright notice

#include "custom_msgs/msg/detail/yolo_segmentation_msg__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_msgs
const rosidl_type_hash_t *
custom_msgs__msg__YoloSegmentationMsg__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x68, 0x85, 0xa8, 0xc5, 0x9c, 0xe0, 0xfc, 0x3b,
      0x10, 0xc2, 0xa5, 0x49, 0x00, 0x14, 0x3f, 0xc1,
      0xf1, 0xd3, 0xb7, 0x2e, 0xf4, 0xcd, 0x13, 0x93,
      0xce, 0xa9, 0x18, 0xa5, 0x86, 0xbf, 0xb3, 0xc8,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "builtin_interfaces/msg/detail/time__functions.h"
#include "std_msgs/msg/detail/header__functions.h"
#include "custom_msgs/msg/detail/segmentation_result__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t custom_msgs__msg__SegmentationResult__EXPECTED_HASH = {1, {
    0xe6, 0x03, 0x60, 0x47, 0x00, 0x7e, 0xda, 0xe5,
    0x53, 0x44, 0x41, 0xec, 0x60, 0x82, 0xbd, 0xe1,
    0xf7, 0xdd, 0x76, 0x29, 0xce, 0xe0, 0x4f, 0xdc,
    0xf4, 0x38, 0xf6, 0xae, 0x74, 0x97, 0x0e, 0x15,
  }};
static const rosidl_type_hash_t std_msgs__msg__Header__EXPECTED_HASH = {1, {
    0xf4, 0x9f, 0xb3, 0xae, 0x2c, 0xf0, 0x70, 0xf7,
    0x93, 0x64, 0x5f, 0xf7, 0x49, 0x68, 0x3a, 0xc6,
    0xb0, 0x62, 0x03, 0xe4, 0x1c, 0x89, 0x1e, 0x17,
    0x70, 0x1b, 0x1c, 0xb5, 0x97, 0xce, 0x6a, 0x01,
  }};
#endif

static char custom_msgs__msg__YoloSegmentationMsg__TYPE_NAME[] = "custom_msgs/msg/YoloSegmentationMsg";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char custom_msgs__msg__SegmentationResult__TYPE_NAME[] = "custom_msgs/msg/SegmentationResult";
static char std_msgs__msg__Header__TYPE_NAME[] = "std_msgs/msg/Header";

// Define type names, field names, and default values
static char custom_msgs__msg__YoloSegmentationMsg__FIELD_NAME__header[] = "header";
static char custom_msgs__msg__YoloSegmentationMsg__FIELD_NAME__yolo_segmentation_msg[] = "yolo_segmentation_msg";

static rosidl_runtime_c__type_description__Field custom_msgs__msg__YoloSegmentationMsg__FIELDS[] = {
  {
    {custom_msgs__msg__YoloSegmentationMsg__FIELD_NAME__header, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    },
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__YoloSegmentationMsg__FIELD_NAME__yolo_segmentation_msg, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {custom_msgs__msg__SegmentationResult__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription custom_msgs__msg__YoloSegmentationMsg__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {custom_msgs__msg__SegmentationResult__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {std_msgs__msg__Header__TYPE_NAME, 19, 19},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_msgs__msg__YoloSegmentationMsg__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_msgs__msg__YoloSegmentationMsg__TYPE_NAME, 35, 35},
      {custom_msgs__msg__YoloSegmentationMsg__FIELDS, 2, 2},
    },
    {custom_msgs__msg__YoloSegmentationMsg__REFERENCED_TYPE_DESCRIPTIONS, 3, 3},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&custom_msgs__msg__SegmentationResult__EXPECTED_HASH, custom_msgs__msg__SegmentationResult__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = custom_msgs__msg__SegmentationResult__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&std_msgs__msg__Header__EXPECTED_HASH, std_msgs__msg__Header__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[2].fields = std_msgs__msg__Header__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "std_msgs/Header header\n"
  "SegmentationResult[] yolo_segmentation_msg";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_msgs__msg__YoloSegmentationMsg__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_msgs__msg__YoloSegmentationMsg__TYPE_NAME, 35, 35},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 66, 66},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_msgs__msg__YoloSegmentationMsg__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[4];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 4, 4};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_msgs__msg__YoloSegmentationMsg__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *custom_msgs__msg__SegmentationResult__get_individual_type_description_source(NULL);
    sources[3] = *std_msgs__msg__Header__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
