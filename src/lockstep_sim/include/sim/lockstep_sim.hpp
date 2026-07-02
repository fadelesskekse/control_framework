#ifndef LOCKSTEP_SIM_NODE_HPP_
#define LOCKSTEP_SIM_NODE_HPP_

#include <chrono>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include "mujoco/mujoco.h"

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "controller/controllers.hpp"

#include "std_msgs/msg/float64.hpp"
#include "std_srvs/srv/trigger.hpp"
#include "control_framework_interfaces/srv/init_state.hpp"
#include "control_framework_interfaces/srv/reset_record.hpp"
#include "control_framework_interfaces/srv/controller_select.hpp"
#include "control_framework_interfaces/msg/control_input.hpp"

#include "render.hpp"


class LockStepSim : public rclcpp::Node
{
    public:
        LockStepSim();
        virtual ~LockStepSim() = default;

    private:

        vector<double> control_input_calculate(
          const vector<double>& state) override;

        void controller_select(const std::shared_ptr<control_framework_interfaces::srv::ControllerSelect::Request> request,
          std::shared_ptr<control_framework_interfaces::srv::ControllerSelect::Response> response);

        void set_controllers(string controller_name);
        
	      std::vector<std::unique_ptr<BaseController>> controllers;

        rclcpp::Publisher<control_framework_interfaces::msg::ControlInput>::SharedPtr control_input_publisher_;
        rclcpp::Service<control_framework_interfaces::srv::ControllerSelect>::SharedPtr swap_controllers_service;

};
  

#endif
