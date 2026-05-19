#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "my_robot_interfaces/action/count_until.hpp"


using CountUntil = my_robot_interfaces::action::CountUntil;
using CountUntilGoalHandle = rclcpp_action::ServerGoalHandle<CountUntil>;
// contains special objects such as _1, _2, _3, etc. used with std::bind to represent arguments that will be provided later 
// when the resulting function object is called.
using namespace std::placeholders; 

class CountUntilServerNode : public rclcpp::Node {

    public:
    CountUntilServerNode() : Node("count_until_server_node_cpp") {
        cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
        count_until_server_ = rclcpp_action::create_server<CountUntil>(
            this,
            "count_until",
            std::bind(&CountUntilServerNode::goalCallback, this, _1, _2),
            std::bind(&CountUntilServerNode::cancelCallback, this, _1),
            std::bind(&CountUntilServerNode::executeCallback, this, _1),
            rcl_action_server_get_default_options(),
            cb_group_
        );
        RCLCPP_INFO(this->get_logger(), "Action server started!!");
    }


    private:
    rclcpp_action::GoalResponse goalCallback(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const CountUntil::Goal> goal) {
        (void)uuid;
        RCLCPP_INFO(this->get_logger(), "Received goal");
        if (goal->target_number <= 0) {
            RCLCPP_WARN(this->get_logger(),"Rejecting goal, target number must be positive");
            return rclcpp_action::GoalResponse::REJECT;
        }
        RCLCPP_INFO(this->get_logger(),"Accepting the goal");
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse cancelCallback(const std::shared_ptr<CountUntilGoalHandle> goal_handle) {
        (void)goal_handle;
        RCLCPP_INFO(this->get_logger(), "Received a cancel request");
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void executeCallback(const std::shared_ptr<CountUntilGoalHandle> goal_handle) {
        int target_number = goal_handle->get_goal()->target_number;
        double delay = goal_handle->get_goal()->delay;
        auto result = std::make_shared<CountUntil::Result>();
        auto feedback = std::make_shared<CountUntil::Feedback>();
        int counter = 0;
        rclcpp::Rate loop_rate(1.0/delay);

        RCLCPP_INFO(this->get_logger(), "Executing the goal");
        for (int i = 0; i < target_number; i++) {
            if (goal_handle->is_canceling()) {
                RCLCPP_INFO(this->get_logger(),"Canceling goal");
                result->reached_number = counter;
                goal_handle->canceled(result);
                return;
            }
            counter++;
            RCLCPP_INFO(this->get_logger(), "%d", counter);
            feedback->current_number = counter;
            goal_handle->publish_feedback(feedback);
            loop_rate.sleep();
        }
        result->reached_number = counter;
        goal_handle->succeed(result);
    }
    rclcpp_action::Server<CountUntil>::SharedPtr count_until_server_;
    rclcpp::CallbackGroup::SharedPtr cb_group_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CountUntilServerNode>(); 
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}