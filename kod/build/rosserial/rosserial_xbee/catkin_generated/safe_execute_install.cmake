execute_process(COMMAND "/home/yalcin/otonom_araba_projesi/build/rosserial/rosserial_xbee/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/yalcin/otonom_araba_projesi/build/rosserial/rosserial_xbee/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
