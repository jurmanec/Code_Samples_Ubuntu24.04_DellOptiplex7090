from setuptools import find_packages, setup

package_name = 'turtle_controller'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jacob-urmanec',
    maintainer_email='jurmanec@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    extras_require={
        'test': [
            'pytest',
        ],
    },
    entry_points={
        'console_scripts': [
            "turtle1_controller_node_py =               turtle_controller.turtle_controller:main",
            "turtle1_controller_node_soln_py =          turtle_controller.turtle_controller_soln:main",
            "turtle1_controller_ch6_service_challenge = turtle_controller.turtle_controller_ch6_service_challenge:main",
        ],
    },
)
