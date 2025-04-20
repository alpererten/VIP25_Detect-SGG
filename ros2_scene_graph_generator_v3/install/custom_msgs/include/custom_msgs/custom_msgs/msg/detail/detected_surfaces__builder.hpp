// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/DetectedSurfaces.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/detected_surfaces.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACES__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/detected_surfaces__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_DetectedSurfaces_surfaces
{
public:
  explicit Init_DetectedSurfaces_surfaces(::custom_msgs::msg::DetectedSurfaces & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::DetectedSurfaces surfaces(::custom_msgs::msg::DetectedSurfaces::_surfaces_type arg)
  {
    msg_.surfaces = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::DetectedSurfaces msg_;
};

class Init_DetectedSurfaces_header
{
public:
  Init_DetectedSurfaces_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectedSurfaces_surfaces header(::custom_msgs::msg::DetectedSurfaces::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DetectedSurfaces_surfaces(msg_);
  }

private:
  ::custom_msgs::msg::DetectedSurfaces msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::DetectedSurfaces>()
{
  return custom_msgs::msg::builder::Init_DetectedSurfaces_header();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACES__BUILDER_HPP_
