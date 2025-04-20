// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/DetectedSurface.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/detected_surface.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACE__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/msg/detail/detected_surface__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DetectedSurface & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: normal
  {
    if (msg.normal.size() == 0) {
      out << "normal: []";
    } else {
      out << "normal: [";
      size_t pending_items = msg.normal.size();
      for (auto item : msg.normal) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: center
  {
    if (msg.center.size() == 0) {
      out << "center: []";
    } else {
      out << "center: [";
      size_t pending_items = msg.center.size();
      for (auto item : msg.center) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DetectedSurface & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: normal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.normal.size() == 0) {
      out << "normal: []\n";
    } else {
      out << "normal:\n";
      for (auto item : msg.normal) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: center
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.center.size() == 0) {
      out << "center: []\n";
    } else {
      out << "center:\n";
      for (auto item : msg.center) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DetectedSurface & msg, bool use_flow_style = false)
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
  const custom_msgs::msg::DetectedSurface & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::msg::DetectedSurface & msg)
{
  return custom_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::msg::DetectedSurface>()
{
  return "custom_msgs::msg::DetectedSurface";
}

template<>
inline const char * name<custom_msgs::msg::DetectedSurface>()
{
  return "custom_msgs/msg/DetectedSurface";
}

template<>
struct has_fixed_size<custom_msgs::msg::DetectedSurface>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msgs::msg::DetectedSurface>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msgs::msg::DetectedSurface>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACE__TRAITS_HPP_
