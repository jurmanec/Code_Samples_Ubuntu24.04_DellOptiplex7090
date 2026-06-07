import rclpy
from rcl_interfaces.msg import ParameterDescriptor
from rcl_interfaces.msg import SetParametersResult
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
import random

from interfaces.msg import SensorReading


class SensorReadingPublisherWithParameters(Node):

    def __init__(self):
        super().__init__('sensor2_publisher')

        publish_rate_param_descriptor = ParameterDescriptor(description="""
        Type: integer
        Description: seconds between timer  
        """)
        
        self.declare_parameter(name="publish_rate", value=1, descriptor=publish_rate_param_descriptor)
        # register parameter change callback
        self.add_on_set_parameters_callback(self.on_parameter_change)

        timer_period = self.get_parameter("publish_rate").get_parameter_value().integer_value 

        self.publisher_ = self.create_publisher(SensorReading, 'sensor2', 10)
        self.timer = self.create_timer(timer_period_sec=timer_period, callback=self.timer_callback)
        self.i = 0

    def on_parameter_change(self, params):
        """This function is called when parameters change"""
        for param in params:
            if param.name == "publish_rate":
                self.get_logger().info(f"Publish interval has changed to {param.value} seconds")
                self.timer.cancel()
                self.timer = self.create_timer(param.value, self.timer_callback)
        return SetParametersResult(successful=True)

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
            minimal_publisher = SensorReadingPublisherWithParameters()

            rclpy.spin(minimal_publisher)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass


if __name__ == '__main__':
    main()