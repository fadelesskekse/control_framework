#ifndef CONTROLLER_NODE_HPP_
#define CONTROLLER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "control_framework_interfaces/msg/control_input.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "controllers.hpp"
#include "control_framework_interfaces/srv/controller_select.hpp"



    class ControllerNode : public rclcpp::Node
    {
        public:
            ControllerNode();
            virtual ~ControllerNode() = default;

        private:

            void control_timer_callback();
            void joint_state_callback(const sensor_msgs::msg::JointState joint_state);

            void controller_select(const std::shared_ptr<control_framework_interfaces::srv::ControllerSelect::Request> request,
                std::shared_ptr<control_framework_interfaces::srv::ControllerSelect::Response> response);


            void set_controllers(const std::vector<std::string>& controller_list);
  

            
            sensor_msgs::msg::JointState joint_state_;

            rclcpp::TimerBase::SharedPtr control_timer_;
            rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr state_subscriber_;

            rclcpp::Publisher<control_framework_interfaces::msg::ControlInput>::SharedPtr control_publisher_;

            rclcpp::Service<control_framework_interfaces::srv::ControllerSelect>::SharedPtr swap_controllers_service;
      
            std::vector<std::unique_ptr<BaseController>> controllers;
            
    };

#endif