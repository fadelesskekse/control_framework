#ifndef PARALLEL_SIM_NODE_HPP_
#define PARALLEL_SIM_NODE_HPP_

#include "sim.hpp"

class ParallelSim : public SimBase
{
    public:
        ParallelSim();
        virtual ~ParallelSim() = default;

    private:

      vector<double> control_input_calculate(
          const vector<double>& state) override;

    void control_input_callback(const control_framework_interfaces::msg::ControlInput & control_input);

      control_framework_interfaces::msg::ControlInput control_input_;
      rclcpp::Subscription<control_framework_interfaces::msg::ControlInput>::SharedPtr control_input_subscriber_;
  

};
  

#endif
