// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msgs:msg/YoloInference.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/yolo_inference__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `yolo_inference`
#include "custom_msgs/msg/detail/inference_result__functions.h"

bool
custom_msgs__msg__YoloInference__init(custom_msgs__msg__YoloInference * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    custom_msgs__msg__YoloInference__fini(msg);
    return false;
  }
  // yolo_inference
  if (!custom_msgs__msg__InferenceResult__Sequence__init(&msg->yolo_inference, 0)) {
    custom_msgs__msg__YoloInference__fini(msg);
    return false;
  }
  return true;
}

void
custom_msgs__msg__YoloInference__fini(custom_msgs__msg__YoloInference * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // yolo_inference
  custom_msgs__msg__InferenceResult__Sequence__fini(&msg->yolo_inference);
}

bool
custom_msgs__msg__YoloInference__are_equal(const custom_msgs__msg__YoloInference * lhs, const custom_msgs__msg__YoloInference * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // yolo_inference
  if (!custom_msgs__msg__InferenceResult__Sequence__are_equal(
      &(lhs->yolo_inference), &(rhs->yolo_inference)))
  {
    return false;
  }
  return true;
}

bool
custom_msgs__msg__YoloInference__copy(
  const custom_msgs__msg__YoloInference * input,
  custom_msgs__msg__YoloInference * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // yolo_inference
  if (!custom_msgs__msg__InferenceResult__Sequence__copy(
      &(input->yolo_inference), &(output->yolo_inference)))
  {
    return false;
  }
  return true;
}

custom_msgs__msg__YoloInference *
custom_msgs__msg__YoloInference__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__YoloInference * msg = (custom_msgs__msg__YoloInference *)allocator.allocate(sizeof(custom_msgs__msg__YoloInference), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msgs__msg__YoloInference));
  bool success = custom_msgs__msg__YoloInference__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msgs__msg__YoloInference__destroy(custom_msgs__msg__YoloInference * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msgs__msg__YoloInference__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msgs__msg__YoloInference__Sequence__init(custom_msgs__msg__YoloInference__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__YoloInference * data = NULL;

  if (size) {
    data = (custom_msgs__msg__YoloInference *)allocator.zero_allocate(size, sizeof(custom_msgs__msg__YoloInference), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msgs__msg__YoloInference__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msgs__msg__YoloInference__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_msgs__msg__YoloInference__Sequence__fini(custom_msgs__msg__YoloInference__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_msgs__msg__YoloInference__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_msgs__msg__YoloInference__Sequence *
custom_msgs__msg__YoloInference__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__YoloInference__Sequence * array = (custom_msgs__msg__YoloInference__Sequence *)allocator.allocate(sizeof(custom_msgs__msg__YoloInference__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msgs__msg__YoloInference__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msgs__msg__YoloInference__Sequence__destroy(custom_msgs__msg__YoloInference__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msgs__msg__YoloInference__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msgs__msg__YoloInference__Sequence__are_equal(const custom_msgs__msg__YoloInference__Sequence * lhs, const custom_msgs__msg__YoloInference__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msgs__msg__YoloInference__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msgs__msg__YoloInference__Sequence__copy(
  const custom_msgs__msg__YoloInference__Sequence * input,
  custom_msgs__msg__YoloInference__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msgs__msg__YoloInference);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_msgs__msg__YoloInference * data =
      (custom_msgs__msg__YoloInference *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msgs__msg__YoloInference__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_msgs__msg__YoloInference__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msgs__msg__YoloInference__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
