// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/YoloSegmentationMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/yolo_segmentation_msg.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__YOLO_SEGMENTATION_MSG__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__YOLO_SEGMENTATION_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/yolo_segmentation_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_YoloSegmentationMsg_yolo_segmentation_msg
{
public:
  explicit Init_YoloSegmentationMsg_yolo_segmentation_msg(::custom_msgs::msg::YoloSegmentationMsg & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::YoloSegmentationMsg yolo_segmentation_msg(::custom_msgs::msg::YoloSegmentationMsg::_yolo_segmentation_msg_type arg)
  {
    msg_.yolo_segmentation_msg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::YoloSegmentationMsg msg_;
};

class Init_YoloSegmentationMsg_header
{
public:
  Init_YoloSegmentationMsg_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_YoloSegmentationMsg_yolo_segmentation_msg header(::custom_msgs::msg::YoloSegmentationMsg::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_YoloSegmentationMsg_yolo_segmentation_msg(msg_);
  }

private:
  ::custom_msgs::msg::YoloSegmentationMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::YoloSegmentationMsg>()
{
  return custom_msgs::msg::builder::Init_YoloSegmentationMsg_header();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__YOLO_SEGMENTATION_MSG__BUILDER_HPP_
