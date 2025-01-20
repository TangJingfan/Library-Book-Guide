#include <fstream>
#include <geometry_msgs/TransformStamped.h>
#include <iostream>
#include <ros/ros.h>
#include <tf/transform_datatypes.h>
#include <tf/transform_listener.h>

void record_position_with_time_stamp(const tf::TransformListener &listener,
                                     std::ofstream &file) {
  tf::StampedTransform transform;
  try {
    listener.lookupTransform("/map", "/base_link", ros::Time(0), transform);
    ros::Time timestamp = ros::Time::now();
    double x = transform.getOrigin().x();
    double y = transform.getOrigin().y();
    double z = transform.getOrigin().z();
    tf::Quaternion q = transform.getRotation();
    double roll, pitch, yaw;
    tf::Matrix3x3(q).getRPY(roll, pitch, yaw);

    file << timestamp.toSec() << "," << x << "," << y << "," << z << "," << yaw
         << std::endl;
  } catch (tf::TransformException &ex) {
    ROS_WARN("%s", ex.what());
  }
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "position_recorder");
  ros::NodeHandle nh;

  tf::TransformListener listener;

  std::ofstream file(
      "/home/nano/Library-Book-Guide/robot_positions/robot_positions.csv");
  file << "Timestamp,x,y,z,yaw" << std::endl;

  ros::Rate rate(10.0);

  while (ros::ok()) {
    record_position_with_time_stamp(listener, file);
    ros::spinOnce();
    rate.sleep();
  }

  file.close();
  return 0;
}