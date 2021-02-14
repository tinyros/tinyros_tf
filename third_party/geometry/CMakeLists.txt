cmake_minimum_required(VERSION 2.6)

set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS}/bin)

execute_process(
  COMMAND mkdir -p ${ROSLIB_PATHS}/tf
  COMMAND mkdir -p ${ROSLIB_PATHS}/impl
  COMMAND cp -a ${TINYROS_TF_SOURCE_DIR}/include/tf/. ${ROSLIB_PATHS}/tf
  COMMAND cp -a ${TINYROS_TF_SOURCE_DIR}/src/tf.cpp ${ROSLIB_PATHS}/impl
)

find_package(orocos_kdl REQUIRED)
find_package(Bullet REQUIRED)
find_package(Eigen 3 QUIET)
if(NOT Eigen_FOUND)
  include(${PROJECT_SOURCE_DIR}/config/FindEigen3.cmake)
  set(Eigen_INCLUDE_DIR "${EIGEN3_INCLUDE_DIR}")
endif()

include_directories(SYSTEM ${BULLET_INCLUDE_DIRS})
include_directories(${orocos_kdl_INCLUDE_DIRS})
link_directories(${orocos_kdl_LIBRARY_DIRS})
include_directories(${Eigen_INCLUDE_DIR})

add_executable(tinyros_tf_echo
  ${tinyros_lib_SRC_LIST}
  ${tinyros_tf_SRC_LIST}
  src/tf_echo.cpp
)

add_executable(tinyros_static_transform_publisher
  ${tinyros_lib_SRC_LIST}
  ${tinyros_tf_SRC_LIST}
  src/static_transform_publisher.cpp
)

add_executable(tinyros_tf_monitor
  ${tinyros_lib_SRC_LIST}
  ${tinyros_tf_SRC_LIST}
  src/tf_monitor.cpp
)

add_executable(tinyros_tf_change_notifier
  ${tinyros_lib_SRC_LIST}
  ${tinyros_tf_SRC_LIST}
  src/change_notifier.cpp
)

add_executable(tinyros_tf_message_filter
  ${tinyros_lib_SRC_LIST}
  ${tinyros_tf_SRC_LIST}
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
