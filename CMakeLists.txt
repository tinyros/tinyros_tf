cmake_minimum_required(VERSION 2.6)

option(TINYROS_SUPPORT_WEBSOCKETS "WebSockets support? (ON/OFF)" ON)
option(TINYROS_SUPPORT_TF "Tf support? (ON/OFF)" ON)
option(TINYROS_SUPPORT_RVIZ "RVIZ support? (ON/OFF)" ON)

set(OUTPUT_PATHS ${PROJECT_SOURCE_DIR}/build/output)
set(ROSLIB_PATHS ${OUTPUT_PATHS}/client_library/gcc/include/tiny_ros)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17 -g")

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

add_subdirectory(core)
add_subdirectory(tools)
add_subdirectory(examples)
