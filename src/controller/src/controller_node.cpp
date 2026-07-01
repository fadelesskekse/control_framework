
#include "../include/controller/controller_node.hpp"

using std::placeholders::_1;
using std::placeholders::_2;
using namespace std::chrono_literals;

static BaseController* active_controller = nullptr;

ControllerNode::ControllerNode() :
Node(
    "controller_node",
    rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true)
)
{
    state_subscriber_ = this->create_subscription<sensor_msgs::msg::JointState>("joint_states", 10, std::bind(&ControllerNode::joint_state_callback, this, _1)); //Need custom msg
    
    auto publishers = this->get_publishers_info_by_topic("/control_input");

    if (!publishers.empty()) {
        RCLCPP_ERROR(
            this->get_logger(),
            "Another node is already publishing to /control_input. This node should not run at the same time."
        );

        throw std::runtime_error("Duplicate /control_input publisher detected");
    }

    else{
        control_publisher_ = this->create_publisher<control_framework_interfaces::msg::ControlInput>("control_input", 10);
     } 

    swap_controllers_service = this->create_service<control_framework_interfaces::srv::ControllerSelect>("controller_select", std::bind(&ControllerNode::controller_select, this, _1, _2));
    
    control_timer_ = this->create_wall_timer(
      1ms, std::bind(&ControllerNode::control_timer_callback, this));

    if (!this->has_parameter("controller_list")) {
        this->declare_parameter<vector<string>>("controller_list", vector<string> {});
    }
    
    vector<string> controller_list = this->get_parameter("controller_list").as_string_array();

    set_controllers(controller_list);

    active_controller = controllers[0].get(); //set a default controller

   
}

void ControllerNode::controller_select(const std::shared_ptr<control_framework_interfaces::srv::ControllerSelect::Request> request,
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

void ControllerNode::joint_state_callback(const sensor_msgs::msg::JointState joint_state){
    joint_state_ = joint_state;
}


void ControllerNode::control_timer_callback(){

    control_framework_interfaces::msg::ControlInput control_input_;

    control_publisher_->publish(control_input_);

}

void ControllerNode::set_controllers(const std::vector<std::string>& controller_list)
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
