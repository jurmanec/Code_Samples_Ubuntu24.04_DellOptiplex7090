#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"
#include "my_robot_interfaces/srv/reset_counter.hpp"

using namespace std::placeholders;
using ResetCounter = my_robot_interfaces::srv::ResetCounter;
using Int64 = example_interfaces::msg::Int64;

class NumberCounterNode : public rclcpp::Node {

    public:
    /** 
     * variable initialization for parent and child classes in the `member initializer list`.
     * Initializes members at the exact moment they are created. 
     * Mandatory for base class constructors.
    */
    NumberCounterNode() : Node("number_counter_node_cpp"), counter_(0) {
        /**
         * May initialize inside because we require callbackNumber.
         */
        number_subscriber_ = this->create_subscription<Int64> (
            "number", 10, std::bind(&NumberCounterNode::callbackNumber, this, _1));
        /**
         * 
         */
        reset_counter_service_ = this->create_service<ResetCounter>("reset_counter", std::bind(&NumberCounterNode::callbackResetCounter, this, _1, _2));
        
        RCLCPP_INFO(this->get_logger(), "Number counter is created!!");
    }

    private:
    // service callback
    /* Note the shared pointers instead of a reference */
    void callbackResetCounter(const ResetCounter::Request::SharedPtr request, const::ResetCounter::Response::SharedPtr response) {
        if (request->reset_value < 0) {
            response->success = false;
            response->message = "Cannot resent counter to a negative value";
        } else if (request->reset_value > counter_) {
            response->success = false;
            response->message = "Reset value must be lower than the current counter value";
        } else {
            counter_ = request->reset_value;
            RCLCPP_INFO(this->get_logger(), "Reset counter to %d", counter_);
            response->success = true;
            response->message = "Success";
        }
    }
    // increment counter by the message value, log it.
    void callbackNumber(const Int64::SharedPtr msg) {
        counter_ += msg->data;
        RCLCPP_INFO(this->get_logger(), "Counter: %d", counter_);
    }
    int counter_;
    rclcpp::Subscription<Int64>::SharedPtr number_subscriber_; // subscriber
    rclcpp::Service<ResetCounter>::SharedPtr reset_counter_service_; // service
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberCounterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}