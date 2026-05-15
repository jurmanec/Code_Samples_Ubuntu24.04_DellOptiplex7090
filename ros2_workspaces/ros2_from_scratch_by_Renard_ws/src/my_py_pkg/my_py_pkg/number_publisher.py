#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import Int64

"""
We have a publishers and a timer with a callback.
The timer creates an Int64 message and publishes it to the number topic.

This structure is very common in ROS2. Whenever we want to pubish data from a sensor, 
we use something similar.
"""
class NumberPublisherNode(Node): 

    def __init__(self):
        super().__init__("number_publisher_node") 
        # declare parameters --------------
        self.declare_parameter("number", 2)
        self.declare_parameter("publish_period", 1.0)
        # Get parameters --------------------------
        self.number_ = self.get_parameter("number").value
        self.timer_period_ = self.get_parameter("publish_period").value
        # queue size is the number of messages that can be retained on the topic
        # if the publish rate exceeds the consumption rate
        self.number_publisher_ = self.create_publisher(Int64, "number", 10)
        # Timer fires the callback each second
        self.number_timer_ = self.create_timer(self.timer_period_, self.publish_number)
        self.get_logger().info(self.get_name()+ " started!!")

    def publish_number(self):
        msg = Int64() # construct message instance
        msg.data = self.number_
        self.number_publisher_.publish(msg)

# note that like c++, main belongs to the file, not a class.
def main(args=None):
    rclpy.init(args=args)
    node = NumberPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()