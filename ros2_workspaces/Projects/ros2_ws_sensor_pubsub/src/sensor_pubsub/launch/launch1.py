from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='sensor_pubsub',
            executable='pub3',
            name='pub3_from_lanch_file',
            output='screen',
            emulate_tty=True,
            # parameters=[
            #     {'my_parameter': 'earth'}
            # ]
        )
    ])