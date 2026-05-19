import rclpy
from rclpy.node import Node

class MyCusomNode(Node):
    def __init__(self):
        super().__init__('my_first_node')
        self.counter_ = 0
        self.timer_ = self.create_timer(1.0, self.print_hello)
        self.get_logger().info("Hello World")

    def print_hello(self):
        self.get_logger().info("Hello "+ str(self.counter_))
        self.counter_ += 1

def main(args=None):
    rclpy.init(args=args) # initialize ros 2 communications
    node = MyCusomNode() # create our node
    rclpy.spin(node) # make node spin
    rclpy.shutdown()

# This is pure Python
# Means if we run the program directly, function `main()` will be called. 
# with this line, we can run the program without using colcon.
# Thus, this line isn't necessary if we aren't running without colcon.
if __name__ == '__main__':
    main()

# Making the node spin
# Keeps the node alive/ blocks exedution of main
# If any callbacks are registered to the node, they can be executed.
# Blocking referes to the terminal process in which the node is started.
# Using ctrl  + C advances from line 11 to line 12.
# 