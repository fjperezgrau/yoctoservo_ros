cmake_minimum_required(VERSION 2.8.3)
project(yoctoservo_ros)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)
catkin_package(
  CATKIN_DEPENDS roscpp
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

file(GLOB yocto_sources
		"src/yocto_api/[a-zA-Z]*.cpp"
		"src/yocto_api/yapi/[a-zA-Z]*.c"
)

add_executable(yoctoservo src/yoctoservo.cpp ${yocto_sources})
target_link_libraries(yoctoservo ${catkin_LIBRARIES} usb-1.0 pthread)
