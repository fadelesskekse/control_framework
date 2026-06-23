// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from control_framework_interfaces:srv/InitState.idl
// generated code does not contain a copyright notice
#include "control_framework_interfaces/srv/detail/init_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `pos_init`
// Member `vel_init`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
control_framework_interfaces__srv__InitState_Request__init(control_framework_interfaces__srv__InitState_Request * msg)
{
  if (!msg) {
    return false;
  }
  // pos_init
  if (!rosidl_runtime_c__double__Sequence__init(&msg->pos_init, 0)) {
    control_framework_interfaces__srv__InitState_Request__fini(msg);
    return false;
  }
  // vel_init
  if (!rosidl_runtime_c__double__Sequence__init(&msg->vel_init, 0)) {
    control_framework_interfaces__srv__InitState_Request__fini(msg);
    return false;
  }
  return true;
}

void
control_framework_interfaces__srv__InitState_Request__fini(control_framework_interfaces__srv__InitState_Request * msg)
{
  if (!msg) {
    return;
  }
  // pos_init
  rosidl_runtime_c__double__Sequence__fini(&msg->pos_init);
  // vel_init
  rosidl_runtime_c__double__Sequence__fini(&msg->vel_init);
}

bool
control_framework_interfaces__srv__InitState_Request__are_equal(const control_framework_interfaces__srv__InitState_Request * lhs, const control_framework_interfaces__srv__InitState_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pos_init
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->pos_init), &(rhs->pos_init)))
  {
    return false;
  }
  // vel_init
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->vel_init), &(rhs->vel_init)))
  {
    return false;
  }
  return true;
}

bool
control_framework_interfaces__srv__InitState_Request__copy(
  const control_framework_interfaces__srv__InitState_Request * input,
  control_framework_interfaces__srv__InitState_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // pos_init
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->pos_init), &(output->pos_init)))
  {
    return false;
  }
  // vel_init
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->vel_init), &(output->vel_init)))
  {
    return false;
  }
  return true;
}

control_framework_interfaces__srv__InitState_Request *
control_framework_interfaces__srv__InitState_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_framework_interfaces__srv__InitState_Request * msg = (control_framework_interfaces__srv__InitState_Request *)allocator.allocate(sizeof(control_framework_interfaces__srv__InitState_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(control_framework_interfaces__srv__InitState_Request));
  bool success = control_framework_interfaces__srv__InitState_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
control_framework_interfaces__srv__InitState_Request__destroy(control_framework_interfaces__srv__InitState_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    control_framework_interfaces__srv__InitState_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
control_framework_interfaces__srv__InitState_Request__Sequence__init(control_framework_interfaces__srv__InitState_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_framework_interfaces__srv__InitState_Request * data = NULL;

  if (size) {
    data = (control_framework_interfaces__srv__InitState_Request *)allocator.zero_allocate(size, sizeof(control_framework_interfaces__srv__InitState_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = control_framework_interfaces__srv__InitState_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        control_framework_interfaces__srv__InitState_Request__fini(&data[i - 1]);
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
control_framework_interfaces__srv__InitState_Request__Sequence__fini(control_framework_interfaces__srv__InitState_Request__Sequence * array)
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
      control_framework_interfaces__srv__InitState_Request__fini(&array->data[i]);
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

control_framework_interfaces__srv__InitState_Request__Sequence *
control_framework_interfaces__srv__InitState_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_framework_interfaces__srv__InitState_Request__Sequence * array = (control_framework_interfaces__srv__InitState_Request__Sequence *)allocator.allocate(sizeof(control_framework_interfaces__srv__InitState_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = control_framework_interfaces__srv__InitState_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
control_framework_interfaces__srv__InitState_Request__Sequence__destroy(control_framework_interfaces__srv__InitState_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    control_framework_interfaces__srv__InitState_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
control_framework_interfaces__srv__InitState_Request__Sequence__are_equal(const control_framework_interfaces__srv__InitState_Request__Sequence * lhs, const control_framework_interfaces__srv__InitState_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!control_framework_interfaces__srv__InitState_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
control_framework_interfaces__srv__InitState_Request__Sequence__copy(
  const control_framework_interfaces__srv__InitState_Request__Sequence * input,
  control_framework_interfaces__srv__InitState_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(control_framework_interfaces__srv__InitState_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    control_framework_interfaces__srv__InitState_Request * data =
      (control_framework_interfaces__srv__InitState_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!control_framework_interfaces__srv__InitState_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          control_framework_interfaces__srv__InitState_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!control_framework_interfaces__srv__InitState_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
control_framework_interfaces__srv__InitState_Response__init(control_framework_interfaces__srv__InitState_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    control_framework_interfaces__srv__InitState_Response__fini(msg);
    return false;
  }
  return true;
}

void
control_framework_interfaces__srv__InitState_Response__fini(control_framework_interfaces__srv__InitState_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
control_framework_interfaces__srv__InitState_Response__are_equal(const control_framework_interfaces__srv__InitState_Response * lhs, const control_framework_interfaces__srv__InitState_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
control_framework_interfaces__srv__InitState_Response__copy(
  const control_framework_interfaces__srv__InitState_Response * input,
  control_framework_interfaces__srv__InitState_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

control_framework_interfaces__srv__InitState_Response *
control_framework_interfaces__srv__InitState_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_framework_interfaces__srv__InitState_Response * msg = (control_framework_interfaces__srv__InitState_Response *)allocator.allocate(sizeof(control_framework_interfaces__srv__InitState_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(control_framework_interfaces__srv__InitState_Response));
  bool success = control_framework_interfaces__srv__InitState_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
control_framework_interfaces__srv__InitState_Response__destroy(control_framework_interfaces__srv__InitState_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    control_framework_interfaces__srv__InitState_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
control_framework_interfaces__srv__InitState_Response__Sequence__init(control_framework_interfaces__srv__InitState_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_framework_interfaces__srv__InitState_Response * data = NULL;

  if (size) {
    data = (control_framework_interfaces__srv__InitState_Response *)allocator.zero_allocate(size, sizeof(control_framework_interfaces__srv__InitState_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = control_framework_interfaces__srv__InitState_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        control_framework_interfaces__srv__InitState_Response__fini(&data[i - 1]);
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
control_framework_interfaces__srv__InitState_Response__Sequence__fini(control_framework_interfaces__srv__InitState_Response__Sequence * array)
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
      control_framework_interfaces__srv__InitState_Response__fini(&array->data[i]);
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

control_framework_interfaces__srv__InitState_Response__Sequence *
control_framework_interfaces__srv__InitState_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  control_framework_interfaces__srv__InitState_Response__Sequence * array = (control_framework_interfaces__srv__InitState_Response__Sequence *)allocator.allocate(sizeof(control_framework_interfaces__srv__InitState_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = control_framework_interfaces__srv__InitState_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
control_framework_interfaces__srv__InitState_Response__Sequence__destroy(control_framework_interfaces__srv__InitState_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    control_framework_interfaces__srv__InitState_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
control_framework_interfaces__srv__InitState_Response__Sequence__are_equal(const control_framework_interfaces__srv__InitState_Response__Sequence * lhs, const control_framework_interfaces__srv__InitState_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!control_framework_interfaces__srv__InitState_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
control_framework_interfaces__srv__InitState_Response__Sequence__copy(
  const control_framework_interfaces__srv__InitState_Response__Sequence * input,
  control_framework_interfaces__srv__InitState_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(control_framework_interfaces__srv__InitState_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    control_framework_interfaces__srv__InitState_Response * data =
      (control_framework_interfaces__srv__InitState_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!control_framework_interfaces__srv__InitState_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          control_framework_interfaces__srv__InitState_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!control_framework_interfaces__srv__InitState_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
