cmake_minimum_required(VERSION 2.6)

find_package(PkgConfig REQUIRED)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})
include_directories( ${wxWidgets_INCLUDE_DIRS} )

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})

pkg_check_modules(OGRE OGRE)
include_directories( ${OGRE_INCLUDE_DIRS} )
link_directories( ${OGRE_LIBRARY_DIRS} )

find_package(orocos_kdl REQUIRED)
find_package(Bullet REQUIRED)
find_package(Eigen 3 QUIET)
if(NOT Eigen_FOUND)
  include(${PROJECT_SOURCE_DIR}/config/FindEigen3.cmake)
  set(Eigen_INCLUDE_DIR "${EIGEN3_INCLUDE_DIR}")
endif()

find_package(urdfdom REQUIRED)
find_package(urdfdom_headers REQUIRED)
# Find version components
if(NOT urdfdom_headers_VERSION)
set(urdfdom_headers_VERSION "0.0.0")
endif()
string(REGEX REPLACE "^([0-9]+).*" "\\1" URDFDOM_HEADERS_MAJOR_VERSION "${urdfdom_headers_VERSION}")
string(REGEX REPLACE "^[0-9]+\\.([0-9]+).*" "\\1" URDFDOM_HEADERS_MINOR_VERSION "${urdfdom_headers_VERSION}")
string(REGEX REPLACE "^[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" URDFDOM_HEADERS_REVISION_VERSION "${urdfdom_headers_VERSION}")
set(generated_compat_header "${TINYROS_RVIZ_SOURCE_DIR}/src/urdf/urdfdom_compatibility.h")
configure_file(${TINYROS_RVIZ_SOURCE_DIR}/src/urdf/urdfdom_compatibility.h.in "${generated_compat_header}" @ONLY)

find_package(COLLADA_DOM 2.3 COMPONENTS 1.5)
if(COLLADA_DOM_FOUND)
  include_directories(${COLLADA_DOM_INCLUDE_DIRS})
  link_directories(${COLLADA_DOM_LIBRARY_DIRS})
endif()

include_directories(SYSTEM ${BULLET_INCLUDE_DIRS})
include_directories(${orocos_kdl_INCLUDE_DIRS})
link_directories(${orocos_kdl_LIBRARY_DIRS})
include_directories(${Eigen_INCLUDE_DIR})

include_directories(src)

add_subdirectory(src)
