#!/usr/bin/env python3
import rclpy
import time
from rclpy.node import Node
 # Recall that we can create subscriptions, servers and clients on self for Node. No so for ActionServer. We must import the following.
 # Action Server: The action server object belongs to the node. Gets ref to node, action interface, server name, and callbacks.
 # Goal
from rclpy.action import ActionServer, GoalResponse, CancelResponse
from rclpy.action.server import ServerGoalHandle
from my_robot_interfaces.action import CountUntil
from rclpy.executors import MultiThreadedExecutor
from rclpy.callback_groups import ReentrantCallbackGroup


class CountUntilServerNode(Node):
    def __init__(self):
        super().__init__("count_util_server")
        # When creating the action server, we pass a reference to the node (self).
        self.count_util_server_ = ActionServer(
            self,
            CountUntil,
            "count_until",
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
            execute_callback=self.execute_callback,
            callback_group=ReentrantCallbackGroup())
        self.get_logger().info("Action server started!!")

    """
    Receive action request.
    Takes CountUntil.Goal request and returns GoalResponse ACCEPT or REJECT.
    ValidateS the target_number. 
    """
    def goal_callback(self, goal_request:CountUntil.Goal): # Action Interface -> Goal (Its the goal request)
        self.get_logger().info("Received goal")
        if goal_request.target_number <= 0:
            self.get_logger().info("Rejecting the goal, target number must be positive")
            return GoalResponse.REJECT
        self.get_logger().info("Accepting the goal")
        return GoalResponse.ACCEPT
    
    # this must change the state of the goal (goal_handle) to canceled.
    def cancel_callback(self, goal_handle: ServerGoalHandle):
        self.get_logger().info("Received a cancel request")
        return CancelResponse.ACCEPT
    
    # handle the goal
    def execute_callback(self, goal_handle: ServerGoalHandle):
        target_number = goal_handle.request.target_number
        delay = goal_handle.request.delay
        result = CountUntil.Result() # result to populate, Action Interface -> Result (Its the final result)
        feedback = CountUntil.Feedback()
        counter = 0

        self.get_logger().info("Executing the goal")
        for i in range(target_number):
            if goal_handle.is_cancel_requested:
                self.get_logger().info("Canceling the goal")
                goal_handle.canceled()
                result.reached_number = counter
                return result
            counter += 1
            self.get_logger().info(str(counter))
            feedback.current_number = counter
            goal_handle.publish_feedback(feedback)
            time.sleep(delay)

        # Final state on the goal. During exeuction the state is executing.
        # Other possible final states are aborted and cancelled.
        goal_handle.succeed()
        result.reached_number = counter
        return result # return result part of interface

def main(args=None):
    rclpy.init(args=args)
    node = CountUntilServerNode() 
    rclpy.spin(node, MultiThreadedExecutor())
    rclpy.shutdown()


if __name__ == "__main__":
    main()