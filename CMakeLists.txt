cmake_minimum_required(VERSION 2.6)

# sudo apt-get install libuv1-dev libssl-dev zlib1g-dev
option(TINYROS_SUPPORT_WEBSOCKETS "WebSockets support? (ON/OFF)" ON)

# sudo apt-get install liborocos-kdl-dev libeigen3-dev libbullet-dev
option(TINYROS_SUPPORT_TF "Tf support? (ON/OFF)" ON)

option(TINYROS_SUPPORT_RVIZ "RVIZ support? (ON/OFF)" OFF)

# Ubuntu 14.04 support c++17:
# 1. sudo add-apt-repository ppa:ubuntu-toolchain-r/test
# 2. sudo apt-get update
# 3. sudo apt-get install g++-7
# 4. cd /usr/bin 
# 5. sudo ln -s /usr/bin/gcc-7  gcc
# 6. sudo ln -s /usr/bin/g++-7  g++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17 -O3")
set(OUTPUT_PATHS ${PROJECT_SOURCE_DIR}/build/output)
set(ROSLIB_PATHS ${OUTPUT_PATHS}/client_library/gcc/include/tiny_ros)

add_definitions(-DSPDLOG_COMPILED_LIB)

aux_source_directory(${PROJECT_SOURCE_DIR}/third_party/spdlog/src SPDLOG_SRC_LIST)

aux_source_directory(${PROJECT_SOURCE_DIR}/third_party/uWebSockets UWS_SRC_LIST)

include_directories(
  ${OUTPUT_PATHS}/client_library/gcc/include
  ${PROJECT_SOURCE_DIR}/third_party/spdlog/include
  ${PROJECT_SOURCE_DIR}/third_party/uWebSockets
)

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
