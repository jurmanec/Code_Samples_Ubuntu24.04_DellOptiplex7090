import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from interfaces.msg import SensorReading
from dataclasses import dataclass
from pathlib import Path
import csv


class Subscriber4(Node):# Subscriber 3 w/ logging to a file
    """Listen to sensor topic 3. Log to disk in CSV format"""
    def __init__(self):
        super().__init__('sensor3_file_logger')
        self.log_writer = CSVFileLogger()
        self.subscription = self.create_subscription(
            SensorReading,
            'sensor3',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, msg):
        self.get_logger().info(f'temp={msg.temperature:.2f}, vibr={msg.vibration:.2f}, status={msg.status}')
        self.log_writer.write_row(self.get_clock(), msg)

    def destroy_node(self):
        self.log_writer.log_file_close()
        super().destroy_node()

class CSVFileLogger():
    """Encapsulate file creation and line wrting"""
    def __init__(self):
        self.log_file = Path("sensor_log.csv").open("w", newline="") # open log file
        self.csv_writer = csv.writer(self.log_file)
        self.csv_writer.writerow(['timestamp','vibration','temperature','status'])

    def write_row(self, clock, msg):
        timestamp = clock.now().to_msg()
        ts_str = f"{timestamp.sec}.{timestamp.nanosec:09d}"
        self.csv_writer.writerow([
            ts_str,
            msg.vibration,
            msg.temperature,
            msg.status
        ])
        self.log_file.flush() # write to disk immediately
    
    def log_file_close(self):
        self.log_file.close()
 
def main(args=None):
    try:
        with rclpy.init(args=args):
            minimal_subscriber = Subscriber4()

            rclpy.spin(minimal_subscriber)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass

if __name__ == '__main__':
    main()