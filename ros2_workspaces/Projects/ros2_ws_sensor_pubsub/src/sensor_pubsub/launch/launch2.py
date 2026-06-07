from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='sensor_pubsub',
            executable='pub3',
            name='pub3_from_launch_file',
            output='screen',
            emulate_tty=True,
        ),
        Node(
            package='sensor_pubsub',
            executable='sub3',
            name='sub3_from_launch_file',
            output='screen',
            emulate_tty=True,
        ),
    ])