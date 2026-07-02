#include "../include/lockstep_sim/parallel_sim.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ParallelSim>());
  rclcpp::shutdown();
}