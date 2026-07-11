#ifndef TEST_NODE_HPP_
#define TEST_NODE_HPP_

#include <chrono>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "control_framework_interfaces/msg/test_msg.hpp"

class TestNode : public rclcpp::Node
{
    public:

        TestNode();
        virtual ~TestNode() = default;

    private:
        void test_callback();

        rclcpp::TimerBase::SharedPtr test_timer_;
        rclcpp::Publisher<control>::SharedPtr test_publisher_;
}

#endif