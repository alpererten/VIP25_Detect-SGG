// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/YoloInference.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/yolo_inference.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__YOLO_INFERENCE__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__YOLO_INFERENCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/msg/detail/yolo_inference__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'yolo_inference'
#include "custom_msgs/msg/detail/inference_result__traits.hpp"

namespace custom_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const YoloInference & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: yolo_inference
  {
    if (msg.yolo_inference.size() == 0) {
      out << "yolo_inference: []";
    } else {
      out << "yolo_inference: [";
      size_t pending_items = msg.yolo_inference.size();
      for (auto item : msg.yolo_inference) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const YoloInference & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: yolo_inference
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.yolo_inference.size() == 0) {
      out << "yolo_inference: []\n";
    } else {
      out << "yolo_inference:\n";
      for (auto item : msg.yolo_inference) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const YoloInference & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::msg::YoloInference & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::msg::YoloInference & msg)
{
  return custom_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::msg::YoloInference>()
{
  return "custom_msgs::msg::YoloInference";
}

template<>
inline const char * name<custom_msgs::msg::YoloInference>()
{
  return "custom_msgs/msg/YoloInference";
}

template<>
struct has_fixed_size<custom_msgs::msg::YoloInference>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msgs::msg::YoloInference>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msgs::msg::YoloInference>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__YOLO_INFERENCE__TRAITS_HPP_
