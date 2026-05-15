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
        # Note topic names don't start with '/' when passed here
        self.turtle1_cmd_vel_publisher_ =  self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        # pass publisher to the timer
        self.timer_ = self.create_timer(1.0, self.callback_turtle1_cmd_vel)
                                                #self.create_subscription(Int64, "number", self.callback_number, 10)
        self.turtle1_pose_subscriber_ = self.create_subscription(Pose, "turtle1/pose", self.callback_turtle1_pose, 10)
        self.turtle1_pos_x = 5.5
        self.get_logger().info(self.get_name()+" started!!")
    
    # track x position (assumbed to be relative to the parent node/world)
    def callback_turtle1_pose(self, msg: Pose):
        self.turtle1_pos_x = msg.x
        #self.get_logger().info("/turtle1/pose x value " + str(msg.x))
        
    # publish velecity command to /turtle1/cmd_vel
    def callback_turtle1_cmd_vel(self):
        self.get_logger().info("Sending Twist msg to turtle1/cmd_vel...")
        msg = Twist()
        # 1 for both when turtle is on the left of the screen (X < 5.5) 
        # 2 for both when turtle is on the right of the screen ( X >= 5.5 )
        # Note all values for the message had to be entered. Just intereing the linear.x and angular.z resulted in an error. 
        if (self.turtle1_pos_x < 5.5):
            msg.linear.x = 1.0
            msg.linear.y = 0.0
            msg.linear.z = 0.0
            msg.angular.x = 0.0
            msg.angular.y = 0.0
            msg.angular.z = 1.0
        else:
            msg.linear.x = 2.0
            msg.linear.y = 0.0
            msg.linear.z = 0.0
            msg.angular.x = 0.0
            msg.angular.y = 0.0
            msg.angular.z = 2.0
        self.turtle1_cmd_vel_publisher_.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = TurlteControllerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()