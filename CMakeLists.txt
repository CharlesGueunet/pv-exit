cmake_minimum_required(VERSION 2.8.8 FATAL_ERROR)
project(exit)

if (NOT ParaView_BINARY_DIR)
  find_package(ParaView REQUIRED)
  include(${PARAVIEW_USE_FILE})
endif()

# Set a consistent MACOSX_RPATH default across all CMake versions.
# When CMake 2.8.12 is required, change this default to 1.
# When CMake 3.0.0 is required, remove this block (see CMP0042).
if(NOT DEFINED CMAKE_MACOSX_RPATH)
  set(CMAKE_MACOSX_RPATH 0)
endif()

include(ParaViewPlugins)

# Set a predefined build type
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
   message(STATUS "Setting build type to 'Release'.")
   set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
   set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

# create a paraview plugin containing server manager xml and the server
# manager classes to build
# this plugin can be loaded on the server side

add_paraview_plugin(Exit "1.0"
    SERVER_MANAGER_XML Exit.xml
    SERVER_MANAGER_SOURCES vtkExit.cxx)

 install(TARGETS Exit DESTINATION ${CMAKE_INSTALL_PREFIX})
