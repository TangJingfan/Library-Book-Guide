# Library-Book-Guide

## Introduction

The goal of this project is to provide high-quality book navigation within the B300 space of the main library at Shanghai Jiao Tong University. This project utilizes laser SLAM to capture terrain information of the library and places a mobile phone on a cart to receive signals from Bluetooth base stations, aligning the data to ensure reliable information for navigation.

## Laser SLAM

SLAM is based on RPLIDAR A1. When the cart is performing SLAM, ensure all related nodes are activated.

- **Hector SLAM** is used in this project. Follow these steps to configure and run Laser SLAM:

```bash
cd ~/Autonomous-Ball-Pick-up-Car/workspace
catkin_make
source /opt/ros/melodic/setup.bash
source devel/setup.bash
sudo chmod 666 /dev/laser
roslaunch rplidar_ros rplidar_slam.launch
```

- **Cartographer** is also applied for better performance. When using Cartographer, three terminal windows are required:

```bash
# Terminal 1
cd ~/Autonomous-Ball-Pick-up-Car/workspace
catkin_make
source /opt/ros/melodic/setup.bash
source devel/setup.bash
sudo chmod 666 /dev/laser
roslaunch rplidar_ros rplidar.launch

# Terminal 2
cd ~/Autonomous-Ball-Pick-up-Car/cartographer_workspace
./carto_slam.sh

# Terminal 3
cd ~/Autonomous-Ball-Pick-up-Car/cartographer_workspace
./map_save.sh

# Once the map is successfully saved, quit all terminals.
```

## Keyboard Control

The chassis is controlled by an `ESP32-S3` board. To control movement using a keyboard, follow these steps:

1. Burn `controlled_move.ino` into the `ESP32-S3` board.
2. Open the serial monitor and set the baud rate to 115200.
3. Use the following keys to control movement:
   - `w`: Move forward
   - `a`: Turn left
   - `s`: Move backward
   - `d`: Turn right
   - `x`: Stop

## Navigation

A customized local planner is applied for the navigation stack. Follow these steps:

```bash
roslaunch point_to_point_nav point_to_point_nav.launch

# Use 2D pose estimate to calibrate the initial position.

# Use 2D Nav Goal to set the destination.
```

## Trajectory Tracking

To integrate with the phone, the position of the cart is recorded with a timestamp. Follow these steps:

```bash
roslaunch point_to_point_nav nav_with_position_record.launch
```

This will log the position data into a CSV file, allowing synchronization with other devices or systems.

