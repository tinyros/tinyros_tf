cmake_minimum_required(VERSION 3.0)

set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_PATHS}/bin)
set(LIBRARY_OUTPUT_PATH ${OUTPUT_PATHS}/lib)

# sudo apt-get install liborocos-kdl-dev libeigen3-dev libbullet-dev libogre-1.9-dev libqt4-dev 
find_package(Eigen3 REQUIRED)
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIRS})

find_package(Bullet REQUIRED)
include_directories(SYSTEM ${BULLET_INCLUDE_DIRS})

find_package(orocos_kdl REQUIRED)
include_directories(${orocos_kdl_INCLUDE_DIRS})
link_directories(${orocos_kdl_LIBRARY_DIRS})

find_package(Qt4 COMPONENTS QtCore QtGui QtOpenGL REQUIRED) 
include(${QT_USE_FILE}) 
add_definitions(-DQT_NO_KEYWORDS)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})

find_package(PkgConfig)
PKG_CHECK_MODULES (Ogre OGRE REQUIRED)
include_directories(${Ogre_INCLUDE_DIRS}) 
link_directories(${Ogre_LIBRARY_DIRS})

include_directories(src)

add_subdirectory(src)
