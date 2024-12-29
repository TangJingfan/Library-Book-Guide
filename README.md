# Library-Book-Guide

## Introduction

The goal of this project is to provide high-quality book navigation within the B300 space of the main library at Shanghai Jiao Tong University. This project utilizes laser SLAM to capture terrain information of the library and places a mobile phone on a cart to receive signals from Bluetooth base stations, aligning the data to ensure reliable information for navigation.

## Laser SLAM

SLAM is based on RPlidar a1. When the car is doing SLAM, make sure all related node is turned on.

Following command should work.

```sh
cd ~/Library-Book-Guide/workspace
catkin_make
source /opt/ros/melodic/setup.bash
source devel/setup.bash
sudo chmod 666 /dev/laser
roslaunch rplidar_ros rplidar_slam.launch
```