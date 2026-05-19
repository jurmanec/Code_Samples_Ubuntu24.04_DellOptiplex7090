#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
# from example_interfaces.msg import Int64
from my_robot_interfaces.msg import HardwareStatus

"""
We have a publishers and a timer with a callback.
The timer creates an Int64 message and publishes it to the number topic.

This structure is very common in ROS2. Whenever we want to pubish data from a sensor, 
we use something similar.
"""
class RobotHardwareStatusPublisherNode(Node): 

    def __init__(self):
        super().__init__("robot_hardware_status_publisher_node") 
        # note super().init must run before we can use the logger
        self.get_logger().info("Starting "+self.get_name()+"...")
        self.number_ = 2
        # queue size is the number of messages that can be retained on the topic
        # if the publish rate exceeds the consumption rate
        self.number_publisher_ = self.create_publisher(HardwareStatus, "robot_hardware_status", 10)
        # Timer fires the callback each second
        self.number_timer_ = self.create_timer(1.0, self.publish_robot_hardware_status)
        self.get_logger().info(self.get_name()+" is started!!")

    def publish_robot_hardware_status(self):
        msg = HardwareStatus() # construct message instance
        msg.temperature = 34.5
        msg.version = 1
        msg.are_motors_ready = True
        msg.debug_message = "hardware is ready"
        self.number_publisher_.publish(msg)

# note that like c++, main belongs to the file, not a class.
def main(args=None):
    rclpy.init(args=args)
    node = RobotHardwareStatusPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()