cmake_minimum_required(VERSION 2.6)

set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS}/bin)

execute_process(
  COMMAND mkdir -p ${ROSLIB_PATHS}/tf
  COMMAND cp -a ${TINYROS_TF_SOURCE_DIR}/include/tf/. ${ROSLIB_PATHS}/tf
)

# sudo apt-get install liborocos-kdl-dev libeigen3-dev libbullet-dev
find_package(orocos_kdl REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Bullet REQUIRED)

include_directories(SYSTEM ${EIGEN3_INCLUDE_DIRS})
include_directories(SYSTEM ${BULLET_INCLUDE_DIRS})
include_directories(${orocos_kdl_INCLUDE_DIRS})
link_directories(${orocos_kdl_LIBRARY_DIRS})

add_executable(tinyros_tf_echo
	${ROSLIB_PATHS}/ros.cpp
	${ROSLIB_PATHS}/time.cpp
	${ROSLIB_PATHS}/duration.cpp
	${ROSLIB_PATHS}/log.cpp
	src/tf_echo.cpp
)

add_executable(tinyros_static_transform_publisher
	${ROSLIB_PATHS}/ros.cpp
	${ROSLIB_PATHS}/time.cpp
	${ROSLIB_PATHS}/duration.cpp
	${ROSLIB_PATHS}/log.cpp
	src/static_transform_publisher.cpp
)

add_executable(tinyros_tf_monitor
	${ROSLIB_PATHS}/ros.cpp
	${ROSLIB_PATHS}/time.cpp
	${ROSLIB_PATHS}/duration.cpp
	${ROSLIB_PATHS}/log.cpp
	src/tf_monitor.cpp
)

add_executable(tinyros_tf_change_notifier
	${ROSLIB_PATHS}/ros.cpp
	${ROSLIB_PATHS}/time.cpp
	${ROSLIB_PATHS}/duration.cpp
	${ROSLIB_PATHS}/log.cpp
	src/change_notifier.cpp
)

add_executable(tinyros_tf_message_filter
	${ROSLIB_PATHS}/ros.cpp
	${ROSLIB_PATHS}/time.cpp
	${ROSLIB_PATHS}/duration.cpp
	${ROSLIB_PATHS}/log.cpp
	src/tf_message_filter.cpp
)

IF (CMAKE_SYSTEM_NAME MATCHES "CYGWIN")
target_link_libraries(tinyros_tf_echo
  libpthread.a
  ${orocos_kdl_LIBRARIES}
)
target_link_libraries(tinyros_static_transform_publisher
  libpthread.a
  ${orocos_kdl_LIBRARIES}
)
target_link_libraries(tinyros_tf_monitor
  libpthread.a
  ${orocos_kdl_LIBRARIES}
)
target_link_libraries(tinyros_tf_change_notifier
  libpthread.a
  ${orocos_kdl_LIBRARIES}
)
target_link_libraries(tinyros_tf_message_filter
  libpthread.a
  ${orocos_kdl_LIBRARIES}
)
ENDIF()

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
target_link_libraries(tinyros_tf_echo
  libpthread.so
  ${orocos_kdl_LIBRARIES}
)
target_link_libraries(tinyros_static_transform_publisher
  libpthread.so
  ${orocos_kdl_LIBRARIES}
)
target_link_libraries(tinyros_tf_monitor
  libpthread.so
  ${orocos_kdl_LIBRARIES}
)
target_link_libraries(tinyros_tf_change_notifier
  libpthread.so
  ${orocos_kdl_LIBRARIES}
)
target_link_libraries(tinyros_tf_message_filter
  libpthread.so
  ${orocos_kdl_LIBRARIES}
)
ENDIF()
