cmake_minimum_required(VERSION 3.0.2)
project(laser_to_arduino)


add_compile_options(-std=c++11)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  serial
)


catkin_package()


include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable(${PROJECT_NAME} src/laser_to_arduino.cpp)


target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)
