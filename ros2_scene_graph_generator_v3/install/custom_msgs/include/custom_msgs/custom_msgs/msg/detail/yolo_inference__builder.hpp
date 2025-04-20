// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/YoloInference.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/yolo_inference.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__YOLO_INFERENCE__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__YOLO_INFERENCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/yolo_inference__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_YoloInference_yolo_inference
{
public:
  explicit Init_YoloInference_yolo_inference(::custom_msgs::msg::YoloInference & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::YoloInference yolo_inference(::custom_msgs::msg::YoloInference::_yolo_inference_type arg)
  {
    msg_.yolo_inference = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::YoloInference msg_;
};

class Init_YoloInference_header
{
public:
  Init_YoloInference_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_YoloInference_yolo_inference header(::custom_msgs::msg::YoloInference::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_YoloInference_yolo_inference(msg_);
  }

private:
  ::custom_msgs::msg::YoloInference msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::YoloInference>()
{
  return custom_msgs::msg::builder::Init_YoloInference_header();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__YOLO_INFERENCE__BUILDER_HPP_
