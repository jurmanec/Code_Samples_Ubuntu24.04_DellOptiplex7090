#include "rclcpp/rclcpp.hpp"
// #include "example_interfaces/msg/int64.hpp" // interface for message
#include "my_robot_interfaces/msg/hardware_status.hpp" // interface for message

class RobotHardwareStatusPublisherNode : public rclcpp::Node  {

    public:
    // constructor
    RobotHardwareStatusPublisherNode() : Node("robot_hardware_status_node_cpp") {
        RCLCPP_INFO(this->get_logger(), "Creating %s...", this->get_name());
        hardware_status_publisher_ = this->create_publisher<my_robot_interfaces::msg::HardwareStatus>("robot_hardware_status", 10);
        hardware_status_timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&RobotHardwareStatusPublisherNode::publishNumber, this));
        RCLCPP_INFO(this->get_logger(), "%s created!!", this->get_name());
    }

    private:
    void publishNumber() {
        auto msg = my_robot_interfaces::msg::HardwareStatus();
        msg.temperature = 34.5;
        msg.version = 1;
        msg.are_motors_ready = true;
        msg.debug_message = "ready";
        hardware_status_publisher_->publish(msg);
    }
    int number_;
    /**
     * Publisher is a template class. 
     * It requires a message type to indicate the type of data it works with.
     * We use a shared pointer.
     */
    rclcpp::Publisher<my_robot_interfaces::msg::HardwareStatus>::SharedPtr hardware_status_publisher_;
    rclcpp::TimerBase::SharedPtr hardware_status_timer_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotHardwareStatusPublisherNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}