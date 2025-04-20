// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/DetectedSurface.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/detected_surface.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACE__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/detected_surface__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_DetectedSurface_confidence
{
public:
  explicit Init_DetectedSurface_confidence(::custom_msgs::msg::DetectedSurface & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::DetectedSurface confidence(::custom_msgs::msg::DetectedSurface::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::DetectedSurface msg_;
};

class Init_DetectedSurface_center
{
public:
  explicit Init_DetectedSurface_center(::custom_msgs::msg::DetectedSurface & msg)
  : msg_(msg)
  {}
  Init_DetectedSurface_confidence center(::custom_msgs::msg::DetectedSurface::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_DetectedSurface_confidence(msg_);
  }

private:
  ::custom_msgs::msg::DetectedSurface msg_;
};

class Init_DetectedSurface_normal
{
public:
  explicit Init_DetectedSurface_normal(::custom_msgs::msg::DetectedSurface & msg)
  : msg_(msg)
  {}
  Init_DetectedSurface_center normal(::custom_msgs::msg::DetectedSurface::_normal_type arg)
  {
    msg_.normal = std::move(arg);
    return Init_DetectedSurface_center(msg_);
  }

private:
  ::custom_msgs::msg::DetectedSurface msg_;
};

class Init_DetectedSurface_type
{
public:
  explicit Init_DetectedSurface_type(::custom_msgs::msg::DetectedSurface & msg)
  : msg_(msg)
  {}
  Init_DetectedSurface_normal type(::custom_msgs::msg::DetectedSurface::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_DetectedSurface_normal(msg_);
  }

private:
  ::custom_msgs::msg::DetectedSurface msg_;
};

class Init_DetectedSurface_id
{
public:
  Init_DetectedSurface_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DetectedSurface_type id(::custom_msgs::msg::DetectedSurface::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_DetectedSurface_type(msg_);
  }

private:
  ::custom_msgs::msg::DetectedSurface msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::DetectedSurface>()
{
  return custom_msgs::msg::builder::Init_DetectedSurface_id();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__DETECTED_SURFACE__BUILDER_HPP_
