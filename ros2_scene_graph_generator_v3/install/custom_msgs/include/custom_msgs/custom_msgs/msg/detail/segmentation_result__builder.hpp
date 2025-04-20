// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/SegmentationResult.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/segmentation_result.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__SEGMENTATION_RESULT__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__SEGMENTATION_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/segmentation_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_SegmentationResult_depth
{
public:
  explicit Init_SegmentationResult_depth(::custom_msgs::msg::SegmentationResult & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::SegmentationResult depth(::custom_msgs::msg::SegmentationResult::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::SegmentationResult msg_;
};

class Init_SegmentationResult_height
{
public:
  explicit Init_SegmentationResult_height(::custom_msgs::msg::SegmentationResult & msg)
  : msg_(msg)
  {}
  Init_SegmentationResult_depth height(::custom_msgs::msg::SegmentationResult::_height_type arg)
  {
    msg_.height = std::move(arg);
    return Init_SegmentationResult_depth(msg_);
  }

private:
  ::custom_msgs::msg::SegmentationResult msg_;
};

class Init_SegmentationResult_width
{
public:
  explicit Init_SegmentationResult_width(::custom_msgs::msg::SegmentationResult & msg)
  : msg_(msg)
  {}
  Init_SegmentationResult_height width(::custom_msgs::msg::SegmentationResult::_width_type arg)
  {
    msg_.width = std::move(arg);
    return Init_SegmentationResult_height(msg_);
  }

private:
  ::custom_msgs::msg::SegmentationResult msg_;
};

class Init_SegmentationResult_y
{
public:
  explicit Init_SegmentationResult_y(::custom_msgs::msg::SegmentationResult & msg)
  : msg_(msg)
  {}
  Init_SegmentationResult_width y(::custom_msgs::msg::SegmentationResult::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_SegmentationResult_width(msg_);
  }

private:
  ::custom_msgs::msg::SegmentationResult msg_;
};

class Init_SegmentationResult_x
{
public:
  explicit Init_SegmentationResult_x(::custom_msgs::msg::SegmentationResult & msg)
  : msg_(msg)
  {}
  Init_SegmentationResult_y x(::custom_msgs::msg::SegmentationResult::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_SegmentationResult_y(msg_);
  }

private:
  ::custom_msgs::msg::SegmentationResult msg_;
};

class Init_SegmentationResult_class_name
{
public:
  explicit Init_SegmentationResult_class_name(::custom_msgs::msg::SegmentationResult & msg)
  : msg_(msg)
  {}
  Init_SegmentationResult_x class_name(::custom_msgs::msg::SegmentationResult::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return Init_SegmentationResult_x(msg_);
  }

private:
  ::custom_msgs::msg::SegmentationResult msg_;
};

class Init_SegmentationResult_class_id
{
public:
  Init_SegmentationResult_class_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SegmentationResult_class_name class_id(::custom_msgs::msg::SegmentationResult::_class_id_type arg)
  {
    msg_.class_id = std::move(arg);
    return Init_SegmentationResult_class_name(msg_);
  }

private:
  ::custom_msgs::msg::SegmentationResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::SegmentationResult>()
{
  return custom_msgs::msg::builder::Init_SegmentationResult_class_id();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__SEGMENTATION_RESULT__BUILDER_HPP_
