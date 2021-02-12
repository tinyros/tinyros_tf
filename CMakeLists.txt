cmake_minimum_required(VERSION 2.6)

# sudo apt-get install libuv1-dev libssl-dev zlib1g-dev
option(TINYROS_SUPPORT_WEBSOCKETS "WebSockets support? (ON/OFF)" ON)

# sudo apt-get install liborocos-kdl-dev libeigen3-dev libbullet-dev
option(TINYROS_SUPPORT_TF "Tf support? (ON/OFF)" ON)

# sudo apt-get install liborocos-kdl-dev libeigen3-dev libbullet-dev
# sudo apt-get install liburdfdom-headers-dev liburdfdom-dev
# sudo apt-get install libtinyxml-dev libwxbase2.8-dev collada-dom-dev
option(TINYROS_SUPPORT_RVIZ "RVIZ support? (ON/OFF)" OFF)

aux_source_directory(${PROJECT_SOURCE_DIR}/third_party/spdlog/src SPDLOG_SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/third_party/uWebSockets UWS_SRC_LIST)
set(OUTPUT_PATHS ${PROJECT_SOURCE_DIR}/build/output)
set(ROSLIB_PATHS ${OUTPUT_PATHS}/client_library/cpp/include/tiny_ros)
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS}/bin)
set(LIBRARY_OUTPUT_PATH ${OUTPUT_PATHS}/bin)
set(TINYROS_GLOBAL_BIN_DESTINATION ${OUTPUT_PATHS}/bin)
set(TINYROS_GLOBAL_LIB_DESTINATION ${OUTPUT_PATHS}/bin)
set(TINYROS_GLOBAL_LIBEXEC_DESTINATION ${OUTPUT_PATHS}/bin)
set(TINYROS_GLOBAL_INCLUDE_DESTINATION ${OUTPUT_PATHS}/client_library/cpp/include/tiny_ros)
set(tinyros_lib_INCLUDE_DIRS ${OUTPUT_PATHS}/client_library/cpp/include)

set(tinyros_lib_SRC_LIST
  ${ROSLIB_PATHS}/log.cpp
  ${ROSLIB_PATHS}/ros.cpp
  ${ROSLIB_PATHS}/time.cpp
  ${ROSLIB_PATHS}/duration.cpp
)

set(class_loader_SRC_LIST
  ${ROSLIB_PATHS}/class_loader.cpp
  ${ROSLIB_PATHS}/class_loader_core.cpp
  ${ROSLIB_PATHS}/meta_object.cpp
  ${ROSLIB_PATHS}/multi_library_class_loader.cpp
)

add_definitions(-DSPDLOG_COMPILED_LIB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -O3")

include_directories(
  ${tinyros_lib_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/third_party/spdlog/include
  ${PROJECT_SOURCE_DIR}/third_party/uWebSockets
)

add_subdirectory(third_party/class_loader)
add_subdirectory(third_party/pluginlib)

IF (TINYROS_SUPPORT_TF)
  set(TINYROS_TF_SOURCE_DIR ${PROJECT_SOURCE_DIR}/third_party/geometry)
  add_subdirectory(third_party/geometry)
ENDIF (TINYROS_SUPPORT_TF)

IF (TINYROS_SUPPORT_RVIZ)
  set(TINYROS_RVIZ_SOURCE_DIR ${PROJECT_SOURCE_DIR}/third_party/rviz)
  add_subdirectory(third_party/rviz)
ENDIF (TINYROS_SUPPORT_RVIZ)

add_subdirectory(core)
add_subdirectory(tools)
add_subdirectory(examples)

