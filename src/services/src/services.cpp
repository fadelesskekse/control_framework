#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/trigger.hpp"

#include <memory>

void reset_to_initial_position(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
          std::shared_ptr<std_srvs::srv::Trigger::Response> response)
{

    //Set mujoco model position to initial position (maybe a ros parameter)

  RCLCPP_INFO(
  rclcpp::get_logger("rclcpp"),
  "sending back response: [%d]",
  static_cast<int>(response->success)
);
}

/*
void set_initial_position(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
          std::shared_ptr<std_srvs::srv::Trigger::Response> response)
{
    //Set mujoco model position to initial position (maybe a ros parameter)
    //Requires special srv I think where input is of size of states needed to reset. 

}

void disturbance(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
          std::shared_ptr<std_srvs::srv::Trigger::Response> response)
{
    //disturb the model with some force or moment
    //Requires special srv I think where input is of size of states needed to reset. 

}

void set_disturbance(const std::shared_ptr<std_srvs::srv::Trigger::Request> request,
          std::shared_ptr<std_srvs::srv::Trigger::Response> response)
{
    //disturb the model with some force or moment
    //Requires special srv I think where input is of size of states needed to reset. 

}
*/

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> service_node = rclcpp::Node::make_shared("service_server");

  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr service =
    service_node->create_service<std_srvs::srv::Trigger>("reset_to_initial_position", &reset_to_initial_position);

 // RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add two ints.");

  rclcpp::spin(service_node);
  rclcpp::shutdown();
}
  