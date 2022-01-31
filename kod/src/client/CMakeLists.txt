cmake_minimum_required(VERSION 2.8.3)
project(client)


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

add_executable(video_node src/video.cpp)
target_link_libraries(video_node ${OpenCV_LIBS} ${catkin_LIBRARIES})

add_executable(arduino src/arduino_code.cpp)
target_link_libraries(arduino ${catkin_LIBRARIES})
add_dependencies(arduino otonom_araba_projesi_generate_messages_cpp)


add_executable(gelen_konum src/gelen_konum_msj.cpp)
target_link_libraries(gelen_konum ${catkin_LIBRARIES} ${OpenCV_LIBS})
add_dependencies(gelen_konum otonom_araba_projesi_generate_messages_cpp)

add_executable(arduino_o src/arduino_o.cpp)
target_link_libraries(arduino_o ${catkin_LIBRARIES} ${OpenCV_LIBS})
add_dependencies(arduino_o otonom_araba_projesi_generate_messages_cpp)
