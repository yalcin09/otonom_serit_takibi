# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yalcin/otonom_araba_projesi/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yalcin/otonom_araba_projesi/build

# Include any dependencies generated for this target.
include master/CMakeFiles/serit_takip_node.dir/depend.make

# Include the progress variables for this target.
include master/CMakeFiles/serit_takip_node.dir/progress.make

# Include the compile flags for this target's objects.
include master/CMakeFiles/serit_takip_node.dir/flags.make

master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o: master/CMakeFiles/serit_takip_node.dir/flags.make
master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o: /home/yalcin/otonom_araba_projesi/src/master/src/Serit_Takip.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yalcin/otonom_araba_projesi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o"
	cd /home/yalcin/otonom_araba_projesi/build/master && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o -c /home/yalcin/otonom_araba_projesi/src/master/src/Serit_Takip.cpp

master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.i"
	cd /home/yalcin/otonom_araba_projesi/build/master && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yalcin/otonom_araba_projesi/src/master/src/Serit_Takip.cpp > CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.i

master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.s"
	cd /home/yalcin/otonom_araba_projesi/build/master && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yalcin/otonom_araba_projesi/src/master/src/Serit_Takip.cpp -o CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.s

master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o.requires:

.PHONY : master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o.requires

master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o.provides: master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o.requires
	$(MAKE) -f master/CMakeFiles/serit_takip_node.dir/build.make master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o.provides.build
.PHONY : master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o.provides

master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o.provides.build: master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o


# Object files for target serit_takip_node
serit_takip_node_OBJECTS = \
"CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o"

# External object files for target serit_takip_node
serit_takip_node_EXTERNAL_OBJECTS =

/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: master/CMakeFiles/serit_takip_node.dir/build.make
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_stitching.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_superres.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_videostab.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_aruco.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_bgsegm.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_bioinspired.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_ccalib.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_dnn_objdetect.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_dpm.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_face.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_freetype.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_fuzzy.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_hdf.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_hfs.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_img_hash.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_line_descriptor.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_optflow.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_reg.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_rgbd.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_saliency.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_stereo.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_structured_light.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_surface_matching.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_tracking.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_xfeatures2d.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_ximgproc.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_xobjdetect.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_xphoto.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /opt/ros/melodic/lib/libcv_bridge.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /opt/ros/melodic/lib/libimage_transport.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /opt/ros/melodic/lib/libmessage_filters.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /opt/ros/melodic/lib/libclass_loader.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/libPocoFoundation.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libdl.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /opt/ros/melodic/lib/libroscpp.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /opt/ros/melodic/lib/librosconsole.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /opt/ros/melodic/lib/libroslib.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /opt/ros/melodic/lib/librospack.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /opt/ros/melodic/lib/librostime.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /opt/ros/melodic/lib/libcpp_common.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_shape.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_photo.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_datasets.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_plot.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_text.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_dnn.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_ml.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_video.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_calib3d.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_features2d.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_highgui.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_videoio.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_viz.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_phase_unwrapping.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_flann.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_imgcodecs.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_objdetect.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_imgproc.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: /usr/local/lib/libopencv_core.so.3.4.1
/home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node: master/CMakeFiles/serit_takip_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yalcin/otonom_araba_projesi/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node"
	cd /home/yalcin/otonom_araba_projesi/build/master && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serit_takip_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
master/CMakeFiles/serit_takip_node.dir/build: /home/yalcin/otonom_araba_projesi/devel/lib/master/serit_takip_node

.PHONY : master/CMakeFiles/serit_takip_node.dir/build

master/CMakeFiles/serit_takip_node.dir/requires: master/CMakeFiles/serit_takip_node.dir/src/Serit_Takip.cpp.o.requires

.PHONY : master/CMakeFiles/serit_takip_node.dir/requires

master/CMakeFiles/serit_takip_node.dir/clean:
	cd /home/yalcin/otonom_araba_projesi/build/master && $(CMAKE_COMMAND) -P CMakeFiles/serit_takip_node.dir/cmake_clean.cmake
.PHONY : master/CMakeFiles/serit_takip_node.dir/clean

master/CMakeFiles/serit_takip_node.dir/depend:
	cd /home/yalcin/otonom_araba_projesi/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yalcin/otonom_araba_projesi/src /home/yalcin/otonom_araba_projesi/src/master /home/yalcin/otonom_araba_projesi/build /home/yalcin/otonom_araba_projesi/build/master /home/yalcin/otonom_araba_projesi/build/master/CMakeFiles/serit_takip_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : master/CMakeFiles/serit_takip_node.dir/depend

