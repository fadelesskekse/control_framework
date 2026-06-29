#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to control_framework_interfaces__srv__InitState_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InitState_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pos_init: Vec<f64>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub vel_init: Vec<f64>,

}



impl Default for InitState_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::InitState_Request::default())
  }
}

impl rosidl_runtime_rs::Message for InitState_Request {
  type RmwMsg = super::srv::rmw::InitState_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pos_init: msg.pos_init.into(),
        vel_init: msg.vel_init.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pos_init: msg.pos_init.as_slice().into(),
        vel_init: msg.vel_init.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      pos_init: msg.pos_init
          .into_iter()
          .collect(),
      vel_init: msg.vel_init
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to control_framework_interfaces__srv__InitState_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct InitState_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for InitState_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::InitState_Response::default())
  }
}

impl rosidl_runtime_rs::Message for InitState_Response {
  type RmwMsg = super::srv::rmw::InitState_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to control_framework_interfaces__srv__ResetRecord_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ResetRecord_Request {
    /// Allows us to pick which init_condition to reset to for the recording. 1 for default, 0 for custom
    pub use_default_init: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub record_time: f64,

}



impl Default for ResetRecord_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ResetRecord_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ResetRecord_Request {
  type RmwMsg = super::srv::rmw::ResetRecord_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        use_default_init: msg.use_default_init,
        record_time: msg.record_time,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      use_default_init: msg.use_default_init,
      record_time: msg.record_time,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      use_default_init: msg.use_default_init,
      record_time: msg.record_time,
    }
  }
}


// Corresponds to control_framework_interfaces__srv__ResetRecord_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ResetRecord_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for ResetRecord_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ResetRecord_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ResetRecord_Response {
  type RmwMsg = super::srv::rmw::ResetRecord_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}


// Corresponds to control_framework_interfaces__srv__ControllerSelect_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ControllerSelect_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub controller_name: std::string::String,

}



impl Default for ControllerSelect_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ControllerSelect_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ControllerSelect_Request {
  type RmwMsg = super::srv::rmw::ControllerSelect_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        controller_name: msg.controller_name.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        controller_name: msg.controller_name.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      controller_name: msg.controller_name.to_string(),
    }
  }
}


// Corresponds to control_framework_interfaces__srv__ControllerSelect_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ControllerSelect_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for ControllerSelect_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::ControllerSelect_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ControllerSelect_Response {
  type RmwMsg = super::srv::rmw::ControllerSelect_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}






#[link(name = "control_framework_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__control_framework_interfaces__srv__InitState() -> *const std::ffi::c_void;
}

// Corresponds to control_framework_interfaces__srv__InitState
#[allow(missing_docs, non_camel_case_types)]
pub struct InitState;

impl rosidl_runtime_rs::Service for InitState {
    type Request = InitState_Request;
    type Response = InitState_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__control_framework_interfaces__srv__InitState() }
    }
}




#[link(name = "control_framework_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__control_framework_interfaces__srv__ResetRecord() -> *const std::ffi::c_void;
}

// Corresponds to control_framework_interfaces__srv__ResetRecord
#[allow(missing_docs, non_camel_case_types)]
pub struct ResetRecord;

impl rosidl_runtime_rs::Service for ResetRecord {
    type Request = ResetRecord_Request;
    type Response = ResetRecord_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__control_framework_interfaces__srv__ResetRecord() }
    }
}




#[link(name = "control_framework_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__control_framework_interfaces__srv__ControllerSelect() -> *const std::ffi::c_void;
}

// Corresponds to control_framework_interfaces__srv__ControllerSelect
#[allow(missing_docs, non_camel_case_types)]
pub struct ControllerSelect;

impl rosidl_runtime_rs::Service for ControllerSelect {
    type Request = ControllerSelect_Request;
    type Response = ControllerSelect_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__control_framework_interfaces__srv__ControllerSelect() }
    }
}


