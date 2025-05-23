// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_msgs:msg/YoloInference.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_msgs/msg/detail/yolo_inference__functions.h"
#include "custom_msgs/msg/detail/yolo_inference__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace custom_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void YoloInference_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_msgs::msg::YoloInference(_init);
}

void YoloInference_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_msgs::msg::YoloInference *>(message_memory);
  typed_message->~YoloInference();
}

size_t size_function__YoloInference__yolo_inference(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<custom_msgs::msg::InferenceResult> *>(untyped_member);
  return member->size();
}

const void * get_const_function__YoloInference__yolo_inference(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<custom_msgs::msg::InferenceResult> *>(untyped_member);
  return &member[index];
}

void * get_function__YoloInference__yolo_inference(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<custom_msgs::msg::InferenceResult> *>(untyped_member);
  return &member[index];
}

void fetch_function__YoloInference__yolo_inference(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const custom_msgs::msg::InferenceResult *>(
    get_const_function__YoloInference__yolo_inference(untyped_member, index));
  auto & value = *reinterpret_cast<custom_msgs::msg::InferenceResult *>(untyped_value);
  value = item;
}

void assign_function__YoloInference__yolo_inference(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<custom_msgs::msg::InferenceResult *>(
    get_function__YoloInference__yolo_inference(untyped_member, index));
  const auto & value = *reinterpret_cast<const custom_msgs::msg::InferenceResult *>(untyped_value);
  item = value;
}

void resize_function__YoloInference__yolo_inference(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<custom_msgs::msg::InferenceResult> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember YoloInference_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs::msg::YoloInference, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "yolo_inference",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<custom_msgs::msg::InferenceResult>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msgs::msg::YoloInference, yolo_inference),  // bytes offset in struct
    nullptr,  // default value
    size_function__YoloInference__yolo_inference,  // size() function pointer
    get_const_function__YoloInference__yolo_inference,  // get_const(index) function pointer
    get_function__YoloInference__yolo_inference,  // get(index) function pointer
    fetch_function__YoloInference__yolo_inference,  // fetch(index, &value) function pointer
    assign_function__YoloInference__yolo_inference,  // assign(index, value) function pointer
    resize_function__YoloInference__yolo_inference  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers YoloInference_message_members = {
  "custom_msgs::msg",  // message namespace
  "YoloInference",  // message name
  2,  // number of fields
  sizeof(custom_msgs::msg::YoloInference),
  false,  // has_any_key_member_
  YoloInference_message_member_array,  // message members
  YoloInference_init_function,  // function to initialize message memory (memory has to be allocated)
  YoloInference_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t YoloInference_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &YoloInference_message_members,
  get_message_typesupport_handle_function,
  &custom_msgs__msg__YoloInference__get_type_hash,
  &custom_msgs__msg__YoloInference__get_type_description,
  &custom_msgs__msg__YoloInference__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace custom_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_msgs::msg::YoloInference>()
{
  return &::custom_msgs::msg::rosidl_typesupport_introspection_cpp::YoloInference_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msgs, msg, YoloInference)() {
  return &::custom_msgs::msg::rosidl_typesupport_introspection_cpp::YoloInference_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
