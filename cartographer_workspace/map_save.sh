#!/bin/bash

source install_isolated/setup.bash
rosservice call /finish_trajectory 0
rosservice call /write_state "{filename: '/home/nano/Library-Book-Guide/workspace/src/map/map_info/B300.pbstream'}"
rosrun cartographer_ros cartographer_pbstream_to_ros_map -map_filestem=/home/nano/Library-Book-Guide/workspace/src/map/map_info/B300 -pbstream_filename=/home/nano/Library-Book-Guide/workspace/src/map/map_info/B300.pbstream -resolution=0.05
