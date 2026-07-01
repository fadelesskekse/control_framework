
#include "../include/controller/controller_node.hpp"

using std::placeholders::_1;
using std::placeholders::_2;
using namespace std::chrono_literals;

ControllerNode::ControllerNode() :
Node("controller_node")
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
    
    

 
    control_timer_ = this->create_wall_timer(
      1ms, std::bind(&ControllerNode::control_timer_callback, this));
}

void ControllerNode::joint_state_callback(const sensor_msgs::msg::JointState joint_state){
    joint_state_ = joint_state;
}


void ControllerNode::control_timer_callback(){

    control_framework_interfaces::msg::ControlInput control_input_;

    control_publisher_->publish(control_input_);

}