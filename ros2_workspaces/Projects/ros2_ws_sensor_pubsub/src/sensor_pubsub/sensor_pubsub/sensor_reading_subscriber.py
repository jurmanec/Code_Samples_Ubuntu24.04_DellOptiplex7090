import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node

# from std_msgs.msg import String
from interfaces.msg import SensorReading


class SensorReadingSubscriber(Node):

    def __init__(self):
        super().__init__('sensor_reading_subscriber')
        self.subscription = self.create_subscription(
            SensorReading,
            'sensor_reading_topic',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info(f'{msg}')
        vibration = msg.vibration
        self.log_vibration_anomaly(vibration)
    
    """Checks for vibration anomaly. Logs message if found
    """
    def log_vibration_anomaly(self, vibration: float):
        if vibration > 1:
            self.get_logger().warning(f"Anomalous vibration >>> {vibration}")


def main(args=None):
    try:
        with rclpy.init(args=args):
            minimal_subscriber = SensorReadingSubscriber()

            rclpy.spin(minimal_subscriber)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass


if __name__ == '__main__':
    main()