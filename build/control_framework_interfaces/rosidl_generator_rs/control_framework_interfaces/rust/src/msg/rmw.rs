#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "control_framework_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__msg__ControlInput() -> *const std::ffi::c_void;
}

#[link(name = "control_framework_interfaces__rosidl_generator_c")]
extern "C" {
    fn control_framework_interfaces__msg__ControlInput__init(msg: *mut ControlInput) -> bool;
    fn control_framework_interfaces__msg__ControlInput__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ControlInput>, size: usize) -> bool;
    fn control_framework_interfaces__msg__ControlInput__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ControlInput>);
    fn control_framework_interfaces__msg__ControlInput__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ControlInput>, out_seq: *mut rosidl_runtime_rs::Sequence<ControlInput>) -> bool;
}

// Corresponds to control_framework_interfaces__msg__ControlInput
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ControlInput {

    // This member is not documented.
    #[allow(missing_docs)]
    pub control_input: rosidl_runtime_rs::Sequence<f64>,

}



impl Default for ControlInput {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !control_framework_interfaces__msg__ControlInput__init(&mut msg as *mut _) {
        panic!("Call to control_framework_interfaces__msg__ControlInput__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ControlInput {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__msg__ControlInput__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__msg__ControlInput__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__msg__ControlInput__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ControlInput {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ControlInput where Self: Sized {
  const TYPE_NAME: &'static str = "control_framework_interfaces/msg/ControlInput";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__msg__ControlInput() }
  }
}


#[link(name = "control_framework_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__msg__JointState() -> *const std::ffi::c_void;
}

#[link(name = "control_framework_interfaces__rosidl_generator_c")]
extern "C" {
    fn control_framework_interfaces__msg__JointState__init(msg: *mut JointState) -> bool;
    fn control_framework_interfaces__msg__JointState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<JointState>, size: usize) -> bool;
    fn control_framework_interfaces__msg__JointState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<JointState>);
    fn control_framework_interfaces__msg__JointState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<JointState>, out_seq: *mut rosidl_runtime_rs::Sequence<JointState>) -> bool;
}

// Corresponds to control_framework_interfaces__msg__JointState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct JointState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pos_state: [f32; 2],


    // This member is not documented.
    #[allow(missing_docs)]
    pub vel_state: [f32; 2],

}



impl Default for JointState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !control_framework_interfaces__msg__JointState__init(&mut msg as *mut _) {
        panic!("Call to control_framework_interfaces__msg__JointState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for JointState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__msg__JointState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__msg__JointState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { control_framework_interfaces__msg__JointState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for JointState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for JointState where Self: Sized {
  const TYPE_NAME: &'static str = "control_framework_interfaces/msg/JointState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__control_framework_interfaces__msg__JointState() }
  }
}


