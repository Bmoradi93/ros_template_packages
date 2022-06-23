cmake_minimum_required(VERSION 3.0.2)
project(read_camera)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  image_transport
  # opencv2
  cv_bridge
)
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES read_camera
#  CATKIN_DEPENDS roscpp rospy std_msgs cv_bridge image_transport
#  DEPENDS system_lib
)

find_package(OpenCV REQUIRED)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(read_cam src/read_cam.cpp src/camera_modules.cpp)
target_link_libraries(read_cam ${catkin_LIBRARIES})

install(
  DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)