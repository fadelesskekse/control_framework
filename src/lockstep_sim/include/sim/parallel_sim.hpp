#ifndef PARALLEL_SIM_NODE_HPP_
#define PARALLEL_SIM_NODE_HPP_

#include "sim.hpp"

class ParallelSim : public rclcpp::Node
{
    public:
        ParallelSim();
        virtual ~ParallelSim() = default;

    private:

      vector<double> control_input_calculate(
        const vector<double>& state) override;

};
  

#endif
