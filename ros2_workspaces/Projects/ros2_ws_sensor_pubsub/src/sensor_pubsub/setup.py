from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'sensor_pubsub'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*')),
    ],
    package_data={'': ['py.typed']},
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Jacob Urmanec',
    maintainer_email='jurmanec@gmail.com',
    description='sensor reading publisher',
    license='Apache-2.0',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            'talker = sensor_pubsub.sensor_reading_publisher:main',
            'listener = sensor_pubsub.sensor_reading_subscriber:main',
            'sensor2_publisher = sensor_pubsub.parameter_driven_publisher:main', # parameter driven
            'sensor2_subscriber = sensor_pubsub.parameter_driven_subscriber:main', # parameter driven
            'pub3 = sensor_pubsub.pub3:main', # realisted data generation
            'sub3 = sensor_pubsub.sub3:main', # threshold based data evaluation
            'sub4 = sensor_pubsub.sub4:main', # csv file logger, subscribes to sensor3 topic
        ],
    },
)
