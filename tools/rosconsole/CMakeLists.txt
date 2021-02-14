cmake_minimum_required(VERSION 2.6)

set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS}/bin)
add_executable(tinyrosconsole
  rosconsole.cpp
  ${tinyros_lib_SRC_LIST}
  ${SPDLOG_SRC_LIST}
)

IF (CMAKE_SYSTEM_NAME MATCHES "CYGWIN")
  target_link_libraries(tinyrosconsole
    libpthread.a
  )
ENDIF()

IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
  target_link_libraries(tinyrosconsole
    libpthread.so
  )
ENDIF()

