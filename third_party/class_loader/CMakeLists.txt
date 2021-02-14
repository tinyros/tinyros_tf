cmake_minimum_required(VERSION 2.6)
project(class_loader)

find_package(Boost REQUIRED COMPONENTS thread system)

set(Poco_DIR cmake)
find_package(Poco REQUIRED COMPONENTS Foundation)

execute_process(
  COMMAND mkdir -p ${TINYROS_GLOBAL_INCLUDE_DESTINATION}/class_loader
  COMMAND mkdir -p ${TINYROS_GLOBAL_INCLUDE_DESTINATION}/impl
  COMMAND cp -a ${PROJECT_SOURCE_DIR}/include/class_loader/. ${TINYROS_GLOBAL_INCLUDE_DESTINATION}/class_loader
  COMMAND cp -a ${PROJECT_SOURCE_DIR}/src/. ${TINYROS_GLOBAL_INCLUDE_DESTINATION}/impl
)

