#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp" // interface for message


using namespace std::placeholders;

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

        // param_callback_handle_ = this->add_post_set_parameters_callback(std::bind(&NumberPublisherNode::parametersCallack, this, _1));
        param_callback_handle_ = this->add_post_set_parameters_callback(std::bind(&NumberPublisherNode::parametersCallack, this, _1));

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

    void parametersCallack(const std::vector<rclcpp::Parameter>& parameters) { // recall that for references we dont copy. However with const, we also dont mutate
      for (const auto &param: parameters) {
        if (param.get_name() == "number") {
            number_ = param.as_int();
        }
      }  
    }

    int number_;
    /**
     * Publisher is a template class. 
     * It requires a message type to indicate the type of data it works with.
     * We use a shared pointer.
     */
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr number_publisher_;
    rclcpp::TimerBase::SharedPtr number_timer_;
    PostSetParametersCallbackHandle::SharedPtr param_callback_handle_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberPublisherNode>(); 
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}