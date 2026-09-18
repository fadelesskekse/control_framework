#ifndef PARALLEL_SIM_NODE_HPP_
#define PARALLEL_SIM_NODE_HPP_

#include "sim.hpp"
#include "control_framework_interfaces/srv/controller_select.hpp"

class ParallelSim : public SimBase
{
    public:
        ParallelSim();
        virtual ~ParallelSim() = default;

    private:


    void timer_callback() override;


    bool control_input_received_{false};

    vector<double> control_input_calculate(
          const vector<double>& state) override;

    void controller_select(const std::shared_ptr<control_framework_interfaces::srv::ControllerSelect::Request> request,
          std::shared_ptr<control_framework_interfaces::srv::ControllerSelect::Response> response);


    void control_input_callback(const control_framework_interfaces::msg::ControlInput & control_input);

      control_framework_interfaces::msg::ControlInput control_input_msg;
      rclcpp::Subscription<control_framework_interfaces::msg::ControlInput>::SharedPtr control_input_subscriber_;
     

};
  

#endif
