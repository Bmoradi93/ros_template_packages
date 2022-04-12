cmake_minimum_required(VERSION 3.0.2)
project(cpp_oop)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES cpp_oop
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(number_counter src/number_counter.cpp src/NumberCounter.cpp)
target_link_libraries(number_counter ${catkin_LIBRARIES})

install(
  DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
)
# add_dependencies(number_counter cpp_oop_generate_messages_cpp)
