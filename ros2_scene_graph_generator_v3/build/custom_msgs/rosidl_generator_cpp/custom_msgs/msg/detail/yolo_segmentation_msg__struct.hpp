// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/YoloSegmentationMsg.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_msgs/msg/yolo_segmentation_msg.hpp"


#ifndef CUSTOM_MSGS__MSG__DETAIL__YOLO_SEGMENTATION_MSG__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__YOLO_SEGMENTATION_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'yolo_segmentation_msg'
#include "custom_msgs/msg/detail/segmentation_result__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__YoloSegmentationMsg __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__YoloSegmentationMsg __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct YoloSegmentationMsg_
{
  using Type = YoloSegmentationMsg_<ContainerAllocator>;

  explicit YoloSegmentationMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit YoloSegmentationMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _yolo_segmentation_msg_type =
    std::vector<custom_msgs::msg::SegmentationResult_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msgs::msg::SegmentationResult_<ContainerAllocator>>>;
  _yolo_segmentation_msg_type yolo_segmentation_msg;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__yolo_segmentation_msg(
    const std::vector<custom_msgs::msg::SegmentationResult_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<custom_msgs::msg::SegmentationResult_<ContainerAllocator>>> & _arg)
  {
    this->yolo_segmentation_msg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::YoloSegmentationMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::YoloSegmentationMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::YoloSegmentationMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::YoloSegmentationMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::YoloSegmentationMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::YoloSegmentationMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::YoloSegmentationMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::YoloSegmentationMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::YoloSegmentationMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::YoloSegmentationMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__YoloSegmentationMsg
    std::shared_ptr<custom_msgs::msg::YoloSegmentationMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__YoloSegmentationMsg
    std::shared_ptr<custom_msgs::msg::YoloSegmentationMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const YoloSegmentationMsg_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->yolo_segmentation_msg != other.yolo_segmentation_msg) {
      return false;
    }
    return true;
  }
  bool operator!=(const YoloSegmentationMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct YoloSegmentationMsg_

// alias to use template instance with default allocator
using YoloSegmentationMsg =
  custom_msgs::msg::YoloSegmentationMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__YOLO_SEGMENTATION_MSG__STRUCT_HPP_
