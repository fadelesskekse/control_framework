#include "../include/test_package/test_node.hpp"

TestNode::TestNode() : Node("test_node")
{
        //Create pubs/subs
      test_timer_ = this->create_wall_timer(
      1ms, std::bind(&TestNode::test_callback, this));

      test_publisher_ = this->create_publisher<control_framework_interfaces::msg::TestMsg>("test_topic", 10); //Need custom msg

      this->declare_parameter("msg_n",1);

      msg_n_ = this->get_parameter("msg_n").as_int();
      

}
    

void TestNode::test_callback(){

  control_framework_interfaces::msg::TestMsg test_msg;


  for(int i = 0; i < msg_n_; i++){
    test_msg.test_msg.push_back(1.0);
  }

   test_publisher_->publish(test_msg);



}

