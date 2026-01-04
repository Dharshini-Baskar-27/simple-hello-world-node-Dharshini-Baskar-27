#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

/*
 * HelloNode class
 */
class HelloNode : public rclcpp::Node
{
public:
  HelloNode()
  : Node("hello_world_node")
  {
    // Create a timer that runs every 1 second
    timer_ = this->create_wall_timer(
      1000ms,
      std::bind(&HelloNode::timer_callback, this)
    );
  }

private:
  // Timer callback function
  void timer_callback()
  {
    RCLCPP_INFO(this->get_logger(), "Hello, World!");
  }

  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<HelloNode>());
  rclcpp::shutdown();
  return 0;
}
