#include "ros/ros.h"
#include <iostream>
#include <stdlib.h>
#include "yocto_api/yocto_api.h"
#include "yocto_api/yocto_servo.h"

int main(int argc, char** argv )
{
  ros::init(argc, argv, "euroc_servo");

  // Read node parameters
  ros::NodeHandle lnh("~");
  int pos;
  if(!lnh.getParam("pos", pos))
    pos = 0;

  std::string errmsg;
  std::string target;
  YModule *module;

  // Setup the API to use local USB devices
  if (yRegisterHub("usb", errmsg) != YAPI_SUCCESS)
  {
    ROS_ERROR_STREAM("RegisterHub error: " << errmsg);
    return 1;
  }

  YServo *servo = yFirstServo();
  if (servo == NULL)
  {
    ROS_WARN("No module connected (check USB cable)");
    return 1;
  }
  target = servo->module()->get_serialNumber();

  module = yFindModule(target);
  servo = yFindServo(target + ".servo1");

  if (servo->isOnline())
  {
    servo->move(pos, 2000);    // smooth transition (2 seconds)
  }
  else
    ROS_WARN("Module not connected (check identification and USB cable)");

  yFreeAPI();

  return 0;
}
