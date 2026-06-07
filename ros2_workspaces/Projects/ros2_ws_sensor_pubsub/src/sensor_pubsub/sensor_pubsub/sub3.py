import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from rcl_interfaces.msg import SetParametersResult
from interfaces.msg import SensorReading
from enum import Enum
from dataclasses import dataclass

class ConditionStatus(Enum):
    CRITICAL = "CRITICAL"
    WARNING = "WARNING"
    NORMAL = "NORMAL"

@dataclass
class SensorReadingThresholds:
    """Encapsulation of configurable thresholds"""
    vibr_crit: float
    vibr_warn: float
    temp_crit: float
    temp_warn: float

class Subscriber3(Node):

    def __init__(self):
        super().__init__('sensor3_subscriber')
        # default thresholds
        self.declare_parameter(name="vibr_crit_threshold", value=5.0)
        self.declare_parameter(name="vibr_warn_threshold", value=2.5)
        self.declare_parameter(name="temp_crit_threshold", value=55.0)
        self.declare_parameter(name="temp_warn_threshold", value=40.0)
        self.thresholds = SensorReadingThresholds(
            vibr_crit=self.get_parameter("vibr_crit_threshold").get_parameter_value().double_value,
            vibr_warn=self.get_parameter("vibr_warn_threshold").get_parameter_value().double_value,
            temp_crit=self.get_parameter("temp_crit_threshold").get_parameter_value().double_value,
            temp_warn=self.get_parameter("temp_warn_threshold").get_parameter_value().double_value
        )    
        # register callback to listen for parameter value changes
        self.add_on_set_parameters_callback(self.on_parameter_change)
        self.__reader = SensorReader()

        self.subscription = self.create_subscription(
            SensorReading,
            'sensor3',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def on_parameter_change(self, params):
        """Called when parameters change"""
        self.get_logger().info("Parameter change...")
        thresholds = self.thresholds
        for param in params:
            if param.name == "vibr_crit_threshold":
                thresholds.vibr_crit = param.value
            if param.name == "vibr_warn_threshold":
                thresholds.vibr_warn = param.value
            if param.name == "temp_crit_threshold":
                thresholds.temp_crit = param.value
            if param.name == "temp_warn_threshold":
                thresholds.temp_warn = param.value
            self.get_logger().info(f"{param.name} updated to {param.value}")
        return SetParametersResult(successful=True)

    def listener_callback(self, msg):
        """ Called when new data published to the sensor2 topic.
            Logs each sensor reading.
            Logs critical and warning messages.
        """
        self.get_logger().info(f'temp={msg.temperature:.2f}, vibr={msg.vibration:.2f}, status={msg.status}')
        # TODO logic here to handle off-line or other senor not-ready / malfunction messages
        # Check for anomalies (WARNING|CRITICAL condition status) 
        status, messages = self.__reader.read(msg, self.thresholds)
        if status is not ConditionStatus.NORMAL:
            if status is  ConditionStatus.CRITICAL:
                self.get_logger().error(f"{status.value}: {messages}")
            else:
                self.get_logger().warn(f"{status.value}: {messages}")
            self.__reader.reset()

class SensorReader():
    """ Services the handler node. 
        Evaluates sensor reading msg data against the listener node's configruable threshold properites for WARNING and CRITICAL sensor readings.
        Returns status and any critical or warning messages.
    """
    def __init__(self): 
        self.reset()

    def reset(self):
        self.status = ConditionStatus.NORMAL
        self.__temp_status = ConditionStatus.NORMAL
        self.__vibr_status = ConditionStatus.NORMAL
        self.messages = []

    def read(self, msg, thresholds: SensorReadingThresholds):
        self.__compute_overall_condition_status(thresholds, msg)
        return self.status, self.messages

    def __compute_overall_condition_status(self, thresholds, msg):
        """Computes overall condition status based on thresholds WARNING|CRITICAL. 
        Mutatates status string and list of messages regarding any exceeded thresholds.
        """
        if msg.vibration > thresholds.vibr_crit or msg.temperature > thresholds.temp_crit:
            self.status = ConditionStatus.CRITICAL  
            if msg.vibration > thresholds.vibr_crit: 
                self.__vibr_status = ConditionStatus.CRITICAL
                self.messages.append(f"Vibration {msg.vibration:.2f} exeeds CRTICAL threshold of {thresholds.vibr_crit}")
            if msg.temperature > thresholds.temp_crit :
                self.__temp_status = ConditionStatus.CRITICAL
                self.messages.append(f"Temperature {msg.temperature:.2f} exeeds CRITICAL threshold of {thresholds.temp_crit}")  
        if msg.vibration > thresholds.vibr_warn or msg.temperature > thresholds.temp_warn:
            if self.status is not ConditionStatus.CRITICAL:
                self.status = ConditionStatus.WARNING 
            if msg.vibration > thresholds.vibr_warn and self.__vibr_status is not ConditionStatus.CRITICAL:         
                self.messages.append(f"Vibration {msg.vibration:.2f} exeeds WARNING threshold of {thresholds.vibr_warn}")
            if msg.temperature > thresholds.temp_warn and self.__temp_status is not ConditionStatus.CRITICAL:
                self.messages.append(f"Temperature {msg.temperature:.2f} exeeds WARNING threshold of {thresholds.temp_warn}") 


def main(args=None):
    try:
        with rclpy.init(args=args):
            minimal_subscriber = Subscriber3()

            rclpy.spin(minimal_subscriber)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass

if __name__ == '__main__':
    main()