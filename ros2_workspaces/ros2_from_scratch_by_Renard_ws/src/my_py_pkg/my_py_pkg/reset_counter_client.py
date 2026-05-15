#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_robot_interfaces.srv import ResetCounter

"""
We use .call_async() and register a callback to the returned future so that the node continues to spin
when handling a given request.

Running this client simply calls the service.
"""
class ResetCounterClientNode(Node):
    def __init__(self):
        super().__init__("reset_counter_client_node_py")
        self.client_ = self.create_client(ResetCounter, "reset_counter")

    def call_reset_counter(self, value):
        # Cause client to wait for service to be registerd as up and running
        while not self.client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for servcice...")
        # Create request object from the ResetCounter interface 
        request = ResetCounter.Request()
        request.reset_value = value
        future = self.client_.call_async(request) # Send request with .call_async
        future.add_done_callback(self.callback_reset_counter_response) # Register a callback to the returned future

    def callback_reset_counter_response(self, future):
        response = future.result()
        self.get_logger().info("Success flag: " + str(response.success))
        self.get_logger().info("Message: " + str(response.message))

def main(args=None):
    rclpy.init(args=args)
    node = ResetCounterClientNode()
    node.call_reset_counter(20) # call the service with a value of 20.
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()