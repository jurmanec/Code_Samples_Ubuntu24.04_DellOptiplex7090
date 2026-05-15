cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(my_robot_interfaces REQUIRED)

# create and link executables
add_executable(test_node src/my_first_node.cpp) # name and path
add_executable(number_publisher_cpp src/number_publisher.cpp)
add_executable(robot_hardware_status_publisher_cpp src/robot_hardware_status_publisher.cpp)
add_executable(number_counter_cpp src/number_counter.cpp)
add_executable(reset_counter_client_cpp src/reset_counter_client.cpp)
add_executable(count_until_server_minimal_cpp src/count_until_server_minimal.cpp)
add_executable(count_until_client_minimal_cpp src/count_until_client_minimal.cpp)
add_executable(count_until_server_cpp src/count_until_server.cpp)
add_executable(count_until_client_cpp src/count_until_client.cpp)
ament_target_dependencies(test_node rclcpp) # link the dependencies for the executable
ament_target_dependencies(number_publisher_cpp rclcpp example_interfaces)
ament_target_dependencies(robot_hardware_status_publisher_cpp rclcpp my_robot_interfaces)
ament_target_dependencies(number_counter_cpp rclcpp example_interfaces my_robot_interfaces)
ament_target_dependencies(reset_counter_client_cpp rclcpp my_robot_interfaces)
ament_target_dependencies(count_until_server_minimal_cpp rclcpp rclcpp_action my_robot_interfaces)
ament_target_dependencies(count_until_client_minimal_cpp rclcpp rclcpp_action my_robot_interfaces)
ament_target_dependencies(count_until_server_cpp rclcpp rclcpp_action my_robot_interfaces)
ament_target_dependencies(count_until_client_cpp rclcpp rclcpp_action my_robot_interfaces)

# install the exectuable
# we don't need a new install instruction for each new executable, just add them here
install(TARGETS
  test_node
  number_publisher_cpp
  robot_hardware_status_publisher_cpp
  number_counter_cpp
  reset_counter_client_cpp
  count_until_server_minimal_cpp  
  count_until_client_minimal_cpp
  count_until_server_cpp  
  count_until_client_cpp
  DESTINATION lib/${PROJECT_NAME}/
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
