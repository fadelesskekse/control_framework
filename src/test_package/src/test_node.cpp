#include "../include/test_package/test_node.hpp"

TestNode::TestNode() : Node("test_node")
{
        //Create pubs/subs
      test_timer_ = this->create_wall_timer(
      1ms, std::bind(&TestNode::test_callback, this));

      test_publisher_ = this->create_publisher<control_framework_interfaces::msg::TestMsg>("test_topic", 10); //Need custom msg


}
    

void TestNode::test_callback(){

}