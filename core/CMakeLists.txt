cmake_minimum_required(VERSION 2.6)

set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS}/bin)
aux_source_directory(src SRC_LIST)
include_directories(include)

IF (TINYROS_SUPPORT_WEBSOCKETS)
  add_definitions("-DTINYROS_WITH_WEBSOCKETS")
  add_executable(tinyrosdds
    ${UWS_SRC_LIST}
    ${SPDLOG_SRC_LIST}
    ${ROSLIB_PATHS}/impl/time.cpp
    ${ROSLIB_PATHS}/impl/duration.cpp
    ${SRC_LIST}
  )
  
  IF (CMAKE_SYSTEM_NAME MATCHES "CYGWIN")
    target_link_libraries(tinyrosdds
      libpthread.a
      libz.a
      libuv.dll.a
      libssl.dll.a
      libcrypto.dll.a
    )
  ENDIF()

  IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_link_libraries(tinyrosdds
      libpthread.so
      libz.so
      libuv.so
      libssl.so
      libcrypto.so
    )
  ENDIF()
ELSE (TINYROS_SUPPORT_WEBSOCKETS)
  add_executable(tinyrosdds
    ${SPDLOG_SRC_LIST}
    ${ROSLIB_PATHS}/impl/time.cpp
    ${ROSLIB_PATHS}/impl/duration.cpp
    ${SRC_LIST}
  )
 
  IF (CMAKE_SYSTEM_NAME MATCHES "CYGWIN")
    target_link_libraries(tinyrosdds
      libpthread.a
    )
  ENDIF()

  IF (CMAKE_SYSTEM_NAME MATCHES "Linux")
    target_link_libraries(tinyrosdds
      libpthread.so
    )
  ENDIF()
ENDIF (TINYROS_SUPPORT_WEBSOCKETS)


