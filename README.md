# yoctoservo_ros [![Build Status](https://travis-ci.org/fjperezgrau/yoctoservo_ros.svg?branch=master)](https://travis-ci.org/fjperezgrau/yoctoservo_ros)
ROS package for interfacing with Yocto-Servo device: http://www.yoctopuce.com/EN/products/usb-actuators/yocto-servo

Refer to their user's guide for more info: 
http://www.yoctopuce.com/EN/products/yocto-servo/doc/SERVORC1.usermanual.html

IMPORTANT NOTE: this package does not include the full YoctoLib library, it only includes the necessary files to run Yocto-Servo device properly.

The following pre-requisites are taken from the YoctoLib README:

## Linux Notes

### Libusb 1.0

In order to compile the library you have to install the version 1.0 of libusb.
Take care to use version 1.0 and not version 0.1. To install libusb 1.0 on
Ubuntu, run "sudo apt-get install libusb-1.0-0-dev".


### Configure udev access rights

In order to work properly, the Yoctopuce VirtualHub and library need write
access to all Yoctopuce devices. By default, Linux access rights for USB
device are read only for all users, except root. If you want to avoid running
VirtualHub as root, you need to add a new rule to your udev configuration.

To add a new udev rules to your Linux installation, you need to create a text
file in the directory "/etc/udev/rules.d" following the naming pattern "##-
arbitraryName.rules". Upon startup, udev will process all files in this
directory with the extension ".rules" according to there alphabetical order.
For instance, the file "51-first.rules" will be processed before  the file "50-
udev-default.rules". The file "50-udev-default.rules" is actually used to
implement the default rules of the system. Therefore, to modify the default
handling behaviour of the system, you have to create a file that start with a
number lower than 50. Note that to add a rules to your udev configuration you
have to be root.

In the sub directory udev_conf we have put two examples of rules that you can
use as reference for your rules.

Example 1: 51-yoctopuce.rules

This rule will add write access to Yoctopuce USB devices for all users. Access
rights for all other devices will be left unchanged. If this is what you want,
copy the file "51-yoctopuce_all.rules" to the directory  "/etc/udev/rules.d"
and restart your system.

    # udev rules to allow write access to all users for Yoctopuce USB devices
    SUBSYSTEM=="usb", ATTR{idVendor}=="24e0", MODE="0666"

Example 2: 51-yoctopuce_group.rules

This rule will allow write access to Yoctopuce USB devices for all users of
the group "yoctogoup". Access right for all other devices will be left
unchanged. If this is what you want, you need to copy the file "51-
yoctopuce_all.rules" to the directory  "/etc/udev/rules.d" and restart your
system.

    # udev rules to allow write access to all users of "yoctogroup" for Yoctopuce USB devices
    SUBSYSTEM=="usb", ATTR{idVendor}=="24e0", MODE="0664",  GROUP="yoctogroup"

