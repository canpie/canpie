#----------------------------------------------------------------------------------------------------------------------#
# CMake file for building CANpie FD server abd tools                                                                   #
#                                                                                                                      #
#----------------------------------------------------------------------------------------------------------------------#

#-------------------------------------------------------------------------------------------------------
# specify minimum version of CMake that can be used with CMakeLists.txt file
#
cmake_minimum_required(VERSION 3.16.4 FATAL_ERROR)
cmake_policy(SET CMP0048 NEW)


message("-- Enter source/application directory ..")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/can-config)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/can-dump)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/can-error)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/can-send)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/server)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/plugins)
