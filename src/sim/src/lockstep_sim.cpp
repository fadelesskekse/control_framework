
#include <iostream>
#include "../include/sim/lockstep_sim.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;
using std::placeholders::_2;
using namespace std;

static BaseController* active_controller = nullptr;


LockStepSim::LockStepSim() : SimBase("lockstep_sim", rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true))
{
     
    swap_controllers_service = this->create_service<control_framework_interfaces::srv::ControllerSelect>("controller_select", std::bind(&LockStepSim::controller_select, this, _1, _2));
      
    auto publishers = this->get_publishers_info_by_topic("/control_input"); //If we are in lockstep, there shouldn't exist another node publishing control as this sim should be publishign control

    if (!publishers.empty()) {
    RCLCPP_ERROR(
        this->get_logger(),
        "Another node is already publishing to /control_input. This node should not run at the same time."
    );

    throw std::runtime_error("Duplicate /control_input publisher detected");
    }

    else{
        control_input_publisher_ = this->create_publisher<control_framework_interfaces::msg::ControlInput>("control_input", 10); //Need custom msg;
    } 


	vector<string> controller_list = this->get_parameter("controller_list").as_string_array();

    set_controllers(controller_list);


    active_controller = controllers[0].get(); //set a default controller

    mj_resetDataKeyframe(m,d,default_init_pos_keyframe);
    mj_forward(m,d);
}

vector<double> LockStepSim::control_input_calculate(const vector<double>& state)
{
   // vector<double> control_input = active_controller->control_passthrough(state);
   // control_input_.control_input = control_input;
    //control_input_publisher_->publish(control_input_);
  //  return control_input;
    return active_controller->control_passthrough(state);
}

void LockStepSim::controller_select(const std::shared_ptr<control_framework_interfaces::srv::ControllerSelect::Request> request,
          std::shared_ptr<control_framework_interfaces::srv::ControllerSelect::Response> response)
{
  string active_controller_name_request = request->controller_name;

  vector<string> controller_list = this->get_parameter("controller_list").as_string_array();


  for (size_t i = 0; i < controller_list.size(); i++) {

        if(active_controller_name_request == controller_list[i]){
          active_controller = controllers[i].get();

          response->success = true;
          response->message = "Controller changed to: " + active_controller_name_request;

          return;
        }

    }
    response->success = false;
    response->message = "Invalid Controller Requested, Controller Is not Changed";
    RCLCPP_WARN(
          this->get_logger(),
          "Not a valid Controller Requested, Controller Is not Changed"
        );

}


void LockStepSim::set_controllers(const std::vector<std::string>& controller_list)
{
    std::string controller_names;

    for (const auto& controller_name : controller_list) {

        if (!controller_names.empty()) {
            controller_names += ", ";
        }
        controller_names += controller_name;

        std::string param_list_name = controller_name + "_param_list";

        if (!this->has_parameter(param_list_name)) { //param_list_name shoudl have been auto declared due to nodeoptions used
            this->declare_parameter<std::vector<std::string>>(
                param_list_name,
                std::vector<std::string>{}
            );
        }

        std::vector<std::string> param_list = this->get_parameter(param_list_name).as_string_array();

        std::vector<ControllerParamValue> controller_params;


        for (const auto& param_name : param_list) {

            if (!this->has_parameter(param_name)) {
                throw std::runtime_error(
                    "Parameter '" + param_name + "' listed in '" +
                    param_list_name + "' was not provided"
                );
            }

            auto param = this->get_parameter(param_name);
            
            switch (param.get_type()) {
                case rclcpp::ParameterType::PARAMETER_BOOL:
                    controller_params.push_back(param.as_bool());
                    break;

                case rclcpp::ParameterType::PARAMETER_INTEGER:
                    controller_params.push_back(param.as_int());
                    break;

                case rclcpp::ParameterType::PARAMETER_DOUBLE:
                    controller_params.push_back(param.as_double());
                    break;

                case rclcpp::ParameterType::PARAMETER_STRING:
                    controller_params.push_back(param.as_string());
                    break;

                case rclcpp::ParameterType::PARAMETER_INTEGER_ARRAY:
                    controller_params.push_back(param.as_integer_array());
                    break;

                case rclcpp::ParameterType::PARAMETER_DOUBLE_ARRAY:
                    controller_params.push_back(param.as_double_array());
                    break;

                case rclcpp::ParameterType::PARAMETER_STRING_ARRAY:
                    controller_params.push_back(param.as_string_array());
                    break;

                default:
                    throw std::runtime_error("Unsupported parameter type: " + param_name);
            }
                    
            RCLCPP_INFO(
                this->get_logger(),
                "Controller %s needs parameter: %s = %s",
                controller_name.c_str(),
                param_name.c_str(),
                param.value_to_string().c_str()
            );
        }

        if(controller_name == "lqr"){
            controllers.push_back(std::make_unique<Lqr>(controller_params));
        }
        else if(controller_name == "test"){
            controllers.push_back(std::make_unique<Test>(controller_params));
        }

    }

}

//
// void LockStepSim::set_controllers(string controller_name){

//     if (controller_name == "lqr") {

//       this->declare_parameter<int64_t>("lqr_gain_row_num", 0);
//       this->declare_parameter<int64_t>("lqr_gain_col_num", 0);
//       this->declare_parameter<std::vector<double>>("lqr_K", std::vector<double>{});

//       int lqr_gain_row_num =
//           this->get_parameter("lqr_gain_row_num").as_int();

//       int lqr_gain_col_num =
//           this->get_parameter("lqr_gain_col_num").as_int();

//       std::vector<double> lqr_K =
//           this->get_parameter("lqr_K").as_double_array();

//       controllers.push_back(std::make_unique<Lqr>(
//            static_cast<std::size_t>(lqr_gain_row_num),
//            static_cast<std::size_t>(lqr_gain_col_num),
//           lqr_K
//       ));

//       RCLCPP_WARN(
//           this->get_logger(),
//           "Instantiated LQR controller"
//       );

//       RCLCPP_WARN(
//           this->get_logger(),
//           "LQR params: rows=%ld, cols=%ld",
//           lqr_gain_row_num,
//           lqr_gain_col_num
//       );

//       std::string lqr_K_string;

//       for (const auto& gain : lqr_K) {
//           if (!lqr_K_string.empty()) {
//               lqr_K_string += ", ";
//           }
//           lqr_K_string += std::to_string(gain);
//       }

//             RCLCPP_WARN(
//           this->get_logger(),
//           "LQR K: [%s]",
//           lqr_K_string.c_str()
//       );


//   }
  
//   else if(controller_name == "test"){
//       this->declare_parameter<int64_t>("test_gain_row_num", 0);
//       this->declare_parameter<int64_t>("test_gain_col_num", 0);
//       this->declare_parameter<std::vector<double>>("test_K", std::vector<double>{});

//       int test_gain_row_num =
//           this->get_parameter("test_gain_row_num").as_int();

//       int test_gain_col_num =
//           this->get_parameter("test_gain_col_num").as_int();

//       std::vector<double> test_K =
//           this->get_parameter("test_K").as_double_array();

//       controllers.push_back(std::make_unique<Test>(
//            static_cast<std::size_t>(test_gain_row_num),
//            static_cast<std::size_t>(test_gain_col_num),
//           test_K
//       ));

//       RCLCPP_WARN(
//           this->get_logger(),
//           "Instantiated test controller"
//       );

//       RCLCPP_WARN(
//           this->get_logger(),
//           "test params: rows=%ld, cols=%ld",
//           test_gain_row_num,
//           test_gain_col_num
//       );

//       std::string test_K_string;

//       for (const auto& gain : test_K) {
//           if (!test_K_string.empty()) {
//               test_K_string += ", ";
//           }
//           test_K_string += std::to_string(gain);
//       }

//             RCLCPP_WARN(
//           this->get_logger(),
//           "test K: [%s]",
//           test_K_string.c_str()
//       );
//   }
  
//   else {
//       RCLCPP_ERROR(
//           this->get_logger(),
//           "Unknown controller requested: %s",
//           controller_name.c_str()
//       );
//   }

// }

