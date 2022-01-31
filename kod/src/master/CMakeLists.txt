cmake_minimum_required(VERSION 2.8.3)
project(master)


find_package(catkin REQUIRED COMPONENTS
  rospy
  genmsg
  roscpp
  std_msgs
  cv_bridge
  sensor_msgs
  geometry_msgs
  image_transport
)

generate_messages(
  DEPENDENCIES
  std_msgs
)


find_package(OpenCV REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES goruntu_isleme
#  CATKIN_DEPENDS cv_bridge image_transport roscpp std_msgs
#  DEPENDS system_lib
)


include_directories(
 include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(serit_takip_node src/Serit_Takip.cpp)
target_link_libraries(serit_takip_node ${OpenCV_LIBS} ${catkin_LIBRARIES})

add_executable(strip_node src/strip_node.cpp)
target_link_libraries(strip_node ${OpenCV_LIBS} ${catkin_LIBRARIES})

add_executable(Strip_node src/Strip_Node.cpp)
target_link_libraries(Strip_node ${OpenCV_LIBS} ${catkin_LIBRARIES})
add_dependencies(Strip_node otonom_araba_projesi_generate_messages_cpp)

add_executable(control src/control.cpp)
target_link_libraries(control ${OpenCV_LIBS} ${catkin_LIBRARIES})
add_dependencies(control otonom_araba_projesi_generate_messages_cpp)

add_executable(konum_msj src/konum_msj.cpp)
target_link_libraries(konum_msj ${OpenCV_LIBS} ${catkin_LIBRARIES})
add_dependencies(konum_msj otonom_araba_projesi_generate_messages_cpp)
