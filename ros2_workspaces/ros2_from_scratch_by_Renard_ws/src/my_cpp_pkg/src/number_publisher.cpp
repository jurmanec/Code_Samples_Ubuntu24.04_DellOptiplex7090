#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp" // interface for message

class NumberPublisherNode : public rclcpp::Node  {

    public:
    // constructor
    NumberPublisherNode() : Node("number_publisher_node_cpp") {
        RCLCPP_INFO(this->get_logger(), "Creating %s...", this->get_name());
        //number_ = 2;
        this->declare_parameter("number", 2);
        this->declare_parameter("publish_period", 1.0);
        number_ = this->get_parameter("number").as_int();
        double timer_period_ = this->get_parameter("publish_period").as_double();
        number_publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number", 10);
        number_timer_ = this->create_wall_timer(std::chrono::duration<double>(timer_period_), std::bind(&NumberPublisherNode::publishNumber, this));
        RCLCPP_INFO(this->get_logger(), "%s created!!", this->get_name());
    }

    private:
    void publishNumber() {
        auto msg = example_interfaces::msg::Int64();
        msg.data = number_;
        number_publisher_->publish(msg);
    }
    int number_;
    /**
     * Publisher is a template class. 
     * It requires a message type to indicate the type of data it works with.
     * We use a shared pointer.
     */
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr number_publisher_;
    rclcpp::TimerBase::SharedPtr number_timer_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberPublisherNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}