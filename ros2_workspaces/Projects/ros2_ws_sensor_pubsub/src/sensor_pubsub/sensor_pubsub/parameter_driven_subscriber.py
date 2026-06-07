import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from rcl_interfaces.msg import SetParametersResult

from interfaces.msg import SensorReading


class ParameterDrivenSubscriber(Node):


    def __init__(self):
        super().__init__('sensor2_subscriber')
        self.declare_parameter(name="vibration_threshold", value=1.0)
        self.vibration_threshold = self.get_parameter("vibration_threshold").get_parameter_value().double_value

        # register callback to listen for parameter value changes
        self.add_on_set_parameters_callback(self.on_parameter_change)

        self.subscription = self.create_subscription(
            SensorReading,
            'sensor2',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def on_parameter_change(self, params):
        """Called when parameters change"""
        self.get_logger().info("Parameter change...")
        for param in params:
            if param.name == "vibration_threshold":
                self.get_logger().info(f"Vibration threshold updated to {param.value}")
                self.vibration_threshold = param.value
        return SetParametersResult(successful=True)

    def listener_callback(self, msg):
        """Called when new data published to the sensor2 topic"""
        self.get_logger().info(f'{msg}')
        vibration = msg.vibration
        self.log_vibration_anomaly(vibration)
    
    def log_vibration_anomaly(self, msg_vibration: float):
        """Checks for vibration anomaly. Logs message if found"""
        if msg_vibration > self.vibration_threshold:
            self.get_logger().warning(f"Anomalous vibration >>> {msg_vibration}")

def main(args=None):
    try:
        with rclpy.init(args=args):
            minimal_subscriber = ParameterDrivenSubscriber()

            rclpy.spin(minimal_subscriber)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass

if __name__ == '__main__':
    main()