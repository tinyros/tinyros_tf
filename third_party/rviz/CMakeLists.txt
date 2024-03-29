cmake_minimum_required(VERSION 2.8.11.2)
project(tinyros_rviz)

set(LIBRARY_OUTPUT_PATH "")

if (POLICY CMP0042)
  cmake_policy(SET CMP0042 NEW)
endif()
if (POLICY CMP0054)
  cmake_policy(SET CMP0054 NEW)
endif()

find_package(Boost REQUIRED
  COMPONENTS
  filesystem
  program_options
  signals
  system
  thread
)

find_package(urdfdom_headers REQUIRED)

find_package(PkgConfig REQUIRED)

set(Poco_DIR cmake)
find_package(Poco REQUIRED COMPONENTS Foundation)

find_package(ASSIMP QUIET)
if (NOT ASSIMP_FOUND)
  pkg_check_modules(ASSIMP assimp)
endif()
if (ASSIMP_FOUND)
  if( NOT ${ASSIMP_VERSION} VERSION_LESS "2.0.1150" )
    add_definitions(-DASSIMP_UNIFIED_HEADER_NAMES)
    message(STATUS "Assimp version has unified headers")
  else()
    message(STATUS "Assimp version does not have unified headers")
  endif()
  include_directories(${ASSIMP_INCLUDE_DIRS})
  link_directories(${ASSIMP_LIBRARY_DIRS})
else()
  message(STATUS "could not find assimp (perhaps available thorugh ROS package?), so assimping assimp v2")
  set(ASSIMP_LIBRARIES assimp)
  set(ASSIMP_LIBRARY_DIRS)
  set(ASSIMP_CXX_FLAGS)
  set(ASSIMP_CFLAGS_OTHER)
  set(ASSIMP_LINK_FLAGS)
  set(ASSIMP_INCLUDE_DIRS)
endif()

pkg_check_modules(OGRE_OV OGRE OGRE-Overlay)

# Old versions of OGRE (pre 1.9) included OGRE-Overlay in the main package
# (i.e. there was no OGRE-Overlay component).  So if the above
# pkg_check_modules() failed, try looking for just OGRE.
if(NOT OGRE_OV_FOUND)
  pkg_check_modules(OGRE_OV REQUIRED OGRE)
endif(NOT OGRE_OV_FOUND)

## Find OGRE Plugin path (not necessarily platform-independent, I guess)
execute_process(COMMAND
  ${PKG_CONFIG_EXECUTABLE} --variable=plugindir OGRE
  OUTPUT_VARIABLE OGRE_PLUGIN_PATH
  OUTPUT_STRIP_TRAILING_WHITESPACE
  )
message(STATUS OGRE_PLUGIN_PATH=${OGRE_PLUGIN_PATH})

# find absolute path of ogre libraries.
# This is stored in the cache to save time on cmake re-run.
# Using absolute paths is necessary if pkg-config finds Ogre in a different
# location than the default.  This can happen when Ogre is built from source,
# or when 2 versions of Ogre are installed.  Using absolute paths ensures that
# components that link against Ogre (rviz and any packages depending on rviz)
# all find the same Ogre shared library.
if(NOT DEFINED OGRE_OV_LIBRARIES_ABS)
  unset(OGRE_OV_LIBRARIES_ABS_TMP)
  foreach(_lib ${OGRE_OV_LIBRARIES})
    set(OGRE_OV_LIB_TAG "OGRE_OV_RVIZ_LIB_${_lib}")

    find_library(${OGRE_OV_LIB_TAG}
            NAMES ${_lib}
            HINTS ${OGRE_OV_LIBRARY_DIRS}
            PATHS ${OGRE_OV_LIBRARY_DIRS}
    )

    set(OGRE_OV_LIBRARIES_ABS_TMP ${OGRE_OV_LIBRARIES_ABS_TMP} ${${OGRE_OV_LIB_TAG}})
  endforeach(_lib)

  set(OGRE_OV_LIBRARIES_ABS ${OGRE_OV_LIBRARIES_ABS_TMP}
        CACHE FILEPATH "Pathname of library ${_lib}")
endif(NOT DEFINED OGRE_OV_LIBRARIES_ABS)

if(APPLE)
  FIND_LIBRARY(Cocoa_LIBRARIES Cocoa)
  set(rviz_ADDITIONAL_LIBRARIES ${Cocoa_LIBRARIES})
endif()

find_package(OpenGL REQUIRED)

find_package(Bullet REQUIRED)

find_package(orocos_kdl REQUIRED)

find_package(urdfdom REQUIRED)
find_package(urdfdom_headers REQUIRED)
# Find version components
if(NOT urdfdom_headers_VERSION)
set(urdfdom_headers_VERSION "0.0.0")
endif()
string(REGEX REPLACE "^([0-9]+).*" "\\1" URDFDOM_HEADERS_MAJOR_VERSION "${urdfdom_headers_VERSION}")
string(REGEX REPLACE "^[0-9]+\\.([0-9]+).*" "\\1" URDFDOM_HEADERS_MINOR_VERSION "${urdfdom_headers_VERSION}")
string(REGEX REPLACE "^[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1" URDFDOM_HEADERS_REVISION_VERSION "${urdfdom_headers_VERSION}")
set(generated_compat_header "${PROJECT_SOURCE_DIR}/src/rviz/urdf/urdfdom_compatibility.h")
configure_file(${PROJECT_SOURCE_DIR}/src/rviz/urdf/urdfdom_compatibility.h.in "${generated_compat_header}" @ONLY)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

option(UseQt5 "UseQt5" OFF)
if (UseQt5)
  find_package(Qt5Widgets REQUIRED)
  find_package(Qt5Core REQUIRED)
  find_package(Qt5OpenGL REQUIRED)
else()
  find_package(Qt4 REQUIRED COMPONENTS QtCore QtGui QtOpenGL)
endif()

find_package(Eigen 3 QUIET)
if(NOT Eigen_FOUND)
  # Fallback to cmake_modules
  include(${PROJECT_SOURCE_DIR}/cmake/FindEigen3.cmake)
  set(EIGEN3_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR})
  set(EIGEN3_LIBRARIES ${EIGEN_LIBRARIES})  # Not strictly necessary as Eigen is head only
  # Possibly map additional variables to the EIGEN3_ prefix.
else()
  set(EIGEN3_INCLUDE_DIRS ${EIGEN3_INCLUDE_DIR})
endif()

if(NOT OGRE_OV_LIBRARIES_ABS)
  set(OGRE_OV_LIBRARIES_ABS ${OGRE_OV_LIBRARIES})
endif()

if(NOT UseQt5)
  include(${QT_USE_FILE})
endif()
add_definitions(-DQT_NO_KEYWORDS)

# Set the Qt version for use in the extras file.
if(UseQt5)
  set(rviz_QT_VERSION ${Qt5Widgets_VERSION})
else()
  set(rviz_QT_VERSION ${QTVERSION})
endif()

# This variable controls the target name of the default plugin library.
# It is used in the extras file (processed in caktin_package(...)) and the
# cmake code for the default plugin.
set(rviz_DEFAULT_PLUGIN_LIBRARY_TARGET_NAME default_plugin)

include_directories(SYSTEM
  src
  ${EIGEN3_INCLUDE_DIRS}
  ${OGRE_OV_INCLUDE_DIRS}
  ${OPENGL_INCLUDE_DIR}
  ${PYTHON_INCLUDE_PATH}
  ${urdfdom_headers_INCLUDE_DIRS}
  ${BULLET_INCLUDE_DIRS}
  ${orocos_kdl_INCLUDE_DIRS}
)

add_subdirectory(src)

execute_process(
  COMMAND mkdir -p ${TINYROS_GLOBAL_BIN_DESTINATION}/pkg_tinyros_rviz/ogre_media
  COMMAND mkdir -p ${TINYROS_GLOBAL_BIN_DESTINATION}/pkg_tinyros_rviz/icons
  COMMAND mkdir -p ${TINYROS_GLOBAL_BIN_DESTINATION}/pkg_tinyros_rviz/images
  COMMAND mkdir -p ${TINYROS_GLOBAL_BIN_DESTINATION}/pkg_tinyros_rviz/help
  COMMAND cp -a ${PROJECT_SOURCE_DIR}/ogre_media/. ${TINYROS_GLOBAL_BIN_DESTINATION}/pkg_tinyros_rviz/ogre_media
  COMMAND cp -a ${PROJECT_SOURCE_DIR}/icons/. ${TINYROS_GLOBAL_BIN_DESTINATION}/pkg_tinyros_rviz/icons
  COMMAND cp -a ${PROJECT_SOURCE_DIR}/images/. ${TINYROS_GLOBAL_BIN_DESTINATION}/pkg_tinyros_rviz/images
  COMMAND cp -a ${PROJECT_SOURCE_DIR}/default.rviz ${TINYROS_GLOBAL_BIN_DESTINATION}/pkg_tinyros_rviz
  COMMAND cp -a ${PROJECT_SOURCE_DIR}/plugin_description.xml ${TINYROS_GLOBAL_BIN_DESTINATION}/pkg_tinyros_rviz
  COMMAND cp -a ${PROJECT_SOURCE_DIR}/help/. ${TINYROS_GLOBAL_BIN_DESTINATION}/pkg_tinyros_rviz/help
)

