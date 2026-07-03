#ifndef LOCKSTEP_SIM_NODE_HPP_
#define LOCKSTEP_SIM_NODE_HPP_

#include "sim.hpp"
#include "controller/controllers.hpp"

#include "control_framework_interfaces/srv/controller_select.hpp"



class LockStepSim : public SimBase
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
