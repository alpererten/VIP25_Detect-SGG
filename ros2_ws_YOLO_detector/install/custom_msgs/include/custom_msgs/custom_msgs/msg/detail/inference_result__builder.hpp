// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/InferenceResult.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__INFERENCE_RESULT__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__INFERENCE_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/inference_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_InferenceResult_y
{
public:
  explicit Init_InferenceResult_y(::custom_msgs::msg::InferenceResult & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::InferenceResult y(::custom_msgs::msg::InferenceResult::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::InferenceResult msg_;
};

class Init_InferenceResult_x
{
public:
  explicit Init_InferenceResult_x(::custom_msgs::msg::InferenceResult & msg)
  : msg_(msg)
  {}
  Init_InferenceResult_y x(::custom_msgs::msg::InferenceResult::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_InferenceResult_y(msg_);
  }

private:
  ::custom_msgs::msg::InferenceResult msg_;
};

class Init_InferenceResult_box_height
{
public:
  explicit Init_InferenceResult_box_height(::custom_msgs::msg::InferenceResult & msg)
  : msg_(msg)
  {}
  Init_InferenceResult_x box_height(::custom_msgs::msg::InferenceResult::_box_height_type arg)
  {
    msg_.box_height = std::move(arg);
    return Init_InferenceResult_x(msg_);
  }

private:
  ::custom_msgs::msg::InferenceResult msg_;
};

class Init_InferenceResult_box_width
{
public:
  explicit Init_InferenceResult_box_width(::custom_msgs::msg::InferenceResult & msg)
  : msg_(msg)
  {}
  Init_InferenceResult_box_height box_width(::custom_msgs::msg::InferenceResult::_box_width_type arg)
  {
    msg_.box_width = std::move(arg);
    return Init_InferenceResult_box_height(msg_);
  }

private:
  ::custom_msgs::msg::InferenceResult msg_;
};

class Init_InferenceResult_right
{
public:
  explicit Init_InferenceResult_right(::custom_msgs::msg::InferenceResult & msg)
  : msg_(msg)
  {}
  Init_InferenceResult_box_width right(::custom_msgs::msg::InferenceResult::_right_type arg)
  {
    msg_.right = std::move(arg);
    return Init_InferenceResult_box_width(msg_);
  }

private:
  ::custom_msgs::msg::InferenceResult msg_;
};

class Init_InferenceResult_bottom
{
public:
  explicit Init_InferenceResult_bottom(::custom_msgs::msg::InferenceResult & msg)
  : msg_(msg)
  {}
  Init_InferenceResult_right bottom(::custom_msgs::msg::InferenceResult::_bottom_type arg)
  {
    msg_.bottom = std::move(arg);
    return Init_InferenceResult_right(msg_);
  }

private:
  ::custom_msgs::msg::InferenceResult msg_;
};

class Init_InferenceResult_left
{
public:
  explicit Init_InferenceResult_left(::custom_msgs::msg::InferenceResult & msg)
  : msg_(msg)
  {}
  Init_InferenceResult_bottom left(::custom_msgs::msg::InferenceResult::_left_type arg)
  {
    msg_.left = std::move(arg);
    return Init_InferenceResult_bottom(msg_);
  }

private:
  ::custom_msgs::msg::InferenceResult msg_;
};

class Init_InferenceResult_top
{
public:
  explicit Init_InferenceResult_top(::custom_msgs::msg::InferenceResult & msg)
  : msg_(msg)
  {}
  Init_InferenceResult_left top(::custom_msgs::msg::InferenceResult::_top_type arg)
  {
    msg_.top = std::move(arg);
    return Init_InferenceResult_left(msg_);
  }

private:
  ::custom_msgs::msg::InferenceResult msg_;
};

class Init_InferenceResult_class_name
{
public:
  Init_InferenceResult_class_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InferenceResult_top class_name(::custom_msgs::msg::InferenceResult::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return Init_InferenceResult_top(msg_);
  }

private:
  ::custom_msgs::msg::InferenceResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::InferenceResult>()
{
  return custom_msgs::msg::builder::Init_InferenceResult_class_name();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__INFERENCE_RESULT__BUILDER_HPP_
