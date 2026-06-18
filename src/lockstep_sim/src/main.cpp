
#include <chrono>

#include "../include/lockstep_sim/lockstep_sim.hpp"
#include "rclcpp/executor.hpp"
#include "../include/lockstep_sim/utilities.hpp"


using std::chrono::seconds;
using utilities::ThreadPriority;
using utilities::configure_thread;
using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
 // rclcpp::spin(std::make_shared<LockStepSim>());
  //rclcpp::shutdown();
  
  rclcpp::executors::SingleThreadedExecutor sim_executor;
  auto sim_node = std::make_shared<LockStepSim>();
  sim_executor.add_node(sim_node);

  rclcpp::Logger logger = sim_node->get_logger();
  
  // Create a thread for each of the two executors ...
  auto sim_thread = std::thread(
    [&]() {
      sim_executor.spin();
    });

  const int CPU_ZERO = 0;
  bool ret = configure_thread(sim_thread, ThreadPriority::HIGH, CPU_ZERO);
  if (!ret) {
    RCLCPP_WARN(logger, "Failed to configure high priority thread, are you root?");
  }

  //const std::chrono::seconds EXPERIMENT_DURATION = 10s;
  //RCLCPP_INFO_STREAM(
   // logger, "Running experiment from now on for " << EXPERIMENT_DURATION.count() << " seconds ...");
  //std::this_thread::sleep_for(EXPERIMENT_DURATION);
  sim_thread.join();
  rclcpp::shutdown();
  
  
  return 0;
}