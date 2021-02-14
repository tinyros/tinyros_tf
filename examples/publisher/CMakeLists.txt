cmake_minimum_required(VERSION 2.6)

set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS}/bin)
add_executable(ExamplePublisher
  ExamplePublisher.cpp
  ${tinyros_lib_SRC_LIST}
  ${tinyros_param_SRC_LIST}
  ${tinyros_package_SRC_LIST}
)

IF (CMAKE_SYSTEM_NAME MATCHES "CYGWIN")
  target_link_libraries(ExamplePublisher
    libpthread.a
  )
ENDIF()

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
  target_link_libraries(ExamplePublisher
    libpthread.so
    libyaml-cpp.so
  )
ENDIF()

