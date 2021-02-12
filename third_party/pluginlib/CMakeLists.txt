cmake_minimum_required(VERSION 2.6)
project(pluginlib)
set(TinyXML_DIR cmake)
set(Poco_DIR cmake)
find_package(Boost REQUIRED COMPONENTS filesystem system thread)
find_package(TinyXML REQUIRED)
find_package(Poco REQUIRED COMPONENTS Foundation)

include_directories(${Boost_INCLUDE_DIRS} ${TinyXML_INCLUDE_DIRS})

add_executable(tinyros_plugin_tool src/plugin_tool.cpp  ${tinyros_lib_SRC_LIST} ${class_loader_SRC_LIST})
target_link_libraries(tinyros_plugin_tool ${Boost_LIBRARIES} ${TinyXML_LIBRARIES} ${Poco_LIBRARIES} )

execute_process(
  COMMAND mkdir -p ${TINYROS_GLOBAL_INCLUDE_DESTINATION}/pluginlib
  COMMAND cp -a ${PROJECT_SOURCE_DIR}/include/pluginlib/. ${TINYROS_GLOBAL_INCLUDE_DESTINATION}/pluginlib
)
