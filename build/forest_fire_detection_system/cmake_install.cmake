# Install script for directory: /home/erfan/Qiaomeng workspace/m300_ws/src/forest_fire_detection_system

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/erfan/Qiaomeng workspace/m300_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/forest_fire_detection_system/msg" TYPE FILE FILES
    "/home/erfan/Qiaomeng workspace/m300_ws/src/forest_fire_detection_system/msg/SingleFireFuse.msg"
    "/home/erfan/Qiaomeng workspace/m300_ws/src/forest_fire_detection_system/msg/SingleFireIR.msg"
    "/home/erfan/Qiaomeng workspace/m300_ws/src/forest_fire_detection_system/msg/SingleFireRGB.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/forest_fire_detection_system/srv" TYPE FILE FILES
    "/home/erfan/Qiaomeng workspace/m300_ws/src/forest_fire_detection_system/srv/SegmentSmoke.srv"
    "/home/erfan/Qiaomeng workspace/m300_ws/src/forest_fire_detection_system/srv/ToggleGrabDataDepthEstimation.srv"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/forest_fire_detection_system/cmake" TYPE FILE FILES "/home/erfan/Qiaomeng workspace/m300_ws/build/forest_fire_detection_system/catkin_generated/installspace/forest_fire_detection_system-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/erfan/Qiaomeng workspace/m300_ws/devel/include/forest_fire_detection_system")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/erfan/Qiaomeng workspace/m300_ws/devel/share/roseus/ros/forest_fire_detection_system")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/erfan/Qiaomeng workspace/m300_ws/devel/share/common-lisp/ros/forest_fire_detection_system")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/erfan/Qiaomeng workspace/m300_ws/devel/share/gennodejs/ros/forest_fire_detection_system")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/erfan/Qiaomeng workspace/m300_ws/devel/lib/python3/dist-packages/forest_fire_detection_system")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/erfan/Qiaomeng workspace/m300_ws/devel/lib/python3/dist-packages/forest_fire_detection_system")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/erfan/Qiaomeng workspace/m300_ws/build/forest_fire_detection_system/catkin_generated/installspace/forest_fire_detection_system.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/forest_fire_detection_system/cmake" TYPE FILE FILES "/home/erfan/Qiaomeng workspace/m300_ws/build/forest_fire_detection_system/catkin_generated/installspace/forest_fire_detection_system-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/forest_fire_detection_system/cmake" TYPE FILE FILES
    "/home/erfan/Qiaomeng workspace/m300_ws/build/forest_fire_detection_system/catkin_generated/installspace/forest_fire_detection_systemConfig.cmake"
    "/home/erfan/Qiaomeng workspace/m300_ws/build/forest_fire_detection_system/catkin_generated/installspace/forest_fire_detection_systemConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/forest_fire_detection_system" TYPE FILE FILES "/home/erfan/Qiaomeng workspace/m300_ws/src/forest_fire_detection_system/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/erfan/Qiaomeng workspace/m300_ws/build/forest_fire_detection_system/src/cmake_install.cmake")

endif()

