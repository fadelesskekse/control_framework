#ifndef CONTROLLER_NODE_HPP_
#define CONTROLLER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "control_framework_interfaces/msg/control_input.hpp"
#include "sensor_msgs/msg/joint_state.hpp"


    class ControllerNode : public rclcpp::Node
    {
        public:
            ControllerNode();
            virtual ~ControllerNode() = default;

        private:

            void control_timer_callback();
            void joint_state_callback(const sensor_msgs::msg::JointState joint_state);

            
            sensor_msgs::msg::JointState joint_state_;

            rclcpp::TimerBase::SharedPtr control_timer_;
            rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr state_subscriber_;

            rclcpp::Publisher<control_framework_interfaces::msg::ControlInput>::SharedPtr control_publisher_;

            
    };

#endif