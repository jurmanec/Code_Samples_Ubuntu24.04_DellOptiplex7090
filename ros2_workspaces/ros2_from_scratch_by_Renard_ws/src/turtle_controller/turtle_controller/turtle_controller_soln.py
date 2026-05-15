#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist


"""
We need to keep track of the x position of the turtle from the /turtle1/pose topic to adjust he velocity.
"""
class TurlteControllerNode(Node): 
    
    def __init__(self):
        super().__init__("turtle_controller_node_py") 
        self.get_logger().info("Starting "+self.get_name()+"...")
        self.turtle1_cmd_vel_publisher_ =  self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.turtle1_pose_subscriber_ = self.create_subscription(Pose, "turtle1/pose", self.callback_turtle1_cmd_vel, 10)
        self.get_logger().info(self.get_name()+" started!!")
    
        
    # publish velecity command to /turtle1/cmd_vel
    def callback_turtle1_cmd_vel(self, msg:Pose):
        # self.get_logger().info("Sending Twist msg to turtle1/cmd_vel...")
        cmd = Twist()
        if (msg.x < 5.5):
            cmd.linear.x = 1.0
            cmd.angular.z = 1.0
        else:
            cmd.linear.x = 2.0
            cmd.angular.z = 2.0
        self.turtle1_cmd_vel_publisher_.publish(cmd)


def main(args=None):
    rclpy.init(args=args)
    node = TurlteControllerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()