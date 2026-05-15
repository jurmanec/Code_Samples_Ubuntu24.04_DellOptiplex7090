#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist
from turtlesim.srv import SetPen # SetPen service interface
from my_robot_interfaces.srv import ToggleActivateTurtle # Service interface to activate/deactivate the turtle


"""
We need to keep track of the x position of the turtle from the /turtle1/pose topic to adjust he velocity.
"""
class TurlteControllerNode(Node): 
    
    def __init__(self):
        super().__init__("turtle_controller_node_py") 
        self.get_logger().info("Starting "+self.get_name()+"...")
        self.turtle1_cmd_vel_publisher_ =  self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.turtle1_pose_subscriber_ = self.create_subscription(Pose, "turtle1/pose", self.callback_pose, 10)
        self.set_pen_client_ = self.create_client(SetPen, "turtle1/set_pen") # set pen client
        # track x position
        self.last_x_ = 0
        self.first_x_fetched_ = False
        # track turtle activation status
        self.turtle_is_active_ = True
        self.create_service(ToggleActivateTurtle, "toggle_activate_turtle", self.callback_toggle_activate_turtle)
        # announce creation
        self.get_logger().info(self.get_name()+" started!!")

    def callback_toggle_activate_turtle(self, request:ToggleActivateTurtle.Request, response:ToggleActivateTurtle.Response):
        if self.turtle_is_active_:
            self.turtle_is_active_ = False
            response.message = "Turtle toggled to inactive!!"
        else:
            self.turtle_is_active_ = True
            response.message = "Turtle toggled to active!!"
        response.success = True
        return response;
        
    # pose subscriber callback 
    # publishes velecity command to /turtle1/cmd_vel
    def callback_pose(self, msg:Pose):
        if self.turtle_is_active_:
            cmd = Twist()
            if (msg.x < 5.5):
                cmd.linear.x = 1.0
                cmd.angular.z = 1.0
            else:
                cmd.linear.x = 2.0
                cmd.angular.z = 2.0
            # only publish velocity command if turtle is set to active by the ToggleActivateTurtle service
            self.turtle1_cmd_vel_publisher_.publish(cmd)
            
            # check if the turtle has switched sides of the screen. If yes, update the pen. TODO: refactor this logic out to its own function.
            if not self.first_x_fetched_:
                self.last_x_ = msg.x
                self.first_x_fetched_ = True
            else:
                # from left to right side of screen
                if self.last_x_ < 5.5 and msg.x >= 5.5:
                    self.call_set_pen(red_value=255,blue_value=0, width=3)
                # from right to left side of screen
                elif self.last_x_ >=5.5 and msg.x < 5.5:
                    self.call_set_pen(red_value=0, blue_value=255, width=3)
                self.last_x_ = msg.x # update self.last_x_

    # 
    def call_set_pen(self, red_value, blue_value, width):
        while not self.set_pen_client_.wait_for_service(1.0):
            self.get_logger().warn("Waiting for service...")    
        request =  SetPen.Request()
        request.r = red_value
        request.b = blue_value
        request.width = width
        future = self.set_pen_client_.call_async(request)
        future.add_done_callback(self.callback_set_pen_response)
       

    def callback_set_pen_response(self, future):
        response = future.result()
        self.get_logger().info("Response from turtle1/set_pen received!!")
        


def main(args=None):
    rclpy.init(args=args)
    node = TurlteControllerNode()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()