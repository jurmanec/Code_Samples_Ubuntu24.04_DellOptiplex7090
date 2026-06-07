import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
import random

from interfaces.msg import SensorReading


class SensorReadingPublisher(Node):

    def __init__(self):
        super().__init__('sensor_reading_publisher')
        self.publisher_ = self.create_publisher(SensorReading, 'sensor_reading_topic', 10)
        timer_period = 1  # seconds between tasks
        self.timer = self.create_timer(timer_period, self.timer_callback)
        self.i = 0

    def timer_callback(self):
        # mock data
        normal_vibration = random.gauss(0, 1)
        # create message
        msg = SensorReading()   
        msg.temperature = 65.0
        msg.vibration = normal_vibration
        msg.status = "OK"  
        # publish                                                                           
        self.publisher_.publish(msg)
        self.get_logger().info(f'Reading index: {self.i}, data:{msg}') 
        self.i += 1

def main(args=None):
    try:
        with rclpy.init(args=args):
            minimal_publisher = SensorReadingPublisher()

            rclpy.spin(minimal_publisher)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass


if __name__ == '__main__':
    main()