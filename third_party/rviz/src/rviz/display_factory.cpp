/*
 * Copyright (c) 2012, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "rviz/display_group.h"
#include "rviz/display_factory.h"
#include "rviz/default_plugin/axes_display.h"
#include "rviz/default_plugin/depth_cloud_display.h"
#include "rviz/default_plugin/effort_display.h"
#include "rviz/default_plugin/fluid_pressure_display.h"
#include "rviz/default_plugin/grid_display.h"
#include "rviz/default_plugin/grid_cells_display.h"
#include "rviz/default_plugin/illuminance_display.h"
#include "rviz/default_plugin/image_display.h"
#include "rviz/default_plugin/interactive_marker_display.h"
#include "rviz/default_plugin/laser_scan_display.h"
#include "rviz/default_plugin/map_display.h"
#include "rviz/default_plugin/marker_display.h"
#include "rviz/default_plugin/marker_array_display.h"
#include "rviz/default_plugin/odometry_display.h"
#include "rviz/default_plugin/path_display.h"
#include "rviz/default_plugin/point_display.h"
#include "rviz/default_plugin/point_cloud_display.h"
#include "rviz/default_plugin/point_cloud2_display.h"
#include "rviz/default_plugin/polygon_display.h"
#include "rviz/default_plugin/pose_display.h"
#include "rviz/default_plugin/pose_array_display.h"
#include "rviz/default_plugin/range_display.h"
#include "rviz/default_plugin/relative_humidity_display.h"
#include "rviz/default_plugin/robot_model_display.h"
#include "rviz/default_plugin/camera_display.h"
#include "rviz/default_plugin/temperature_display.h"
#include "rviz/default_plugin/tf_display.h"
#include "rviz/default_plugin/wrench_display.h"

namespace rviz
{

static Display* newDisplayGroup() { return new DisplayGroup(); }
static Display* newAxesDisplay() { return new AxesDisplay(); }
static Display* newDepthCloudDisplay() { return new DepthCloudDisplay(); }
static Display* newEffortDisplay() { return new EffortDisplay(); }
static Display* newFluidPressureDisplay() { return new FluidPressureDisplay(); }
static Display* newGridDisplay() { return new GridDisplay(); }
static Display* newGridCellsDisplay() { return new GridCellsDisplay(); }
static Display* newIlluminanceDisplay() { return new IlluminanceDisplay(); }
static Display* newImageDisplay() { return new ImageDisplay(); }
static Display* newInteractiveMarkerDisplay() { return new InteractiveMarkerDisplay(); }
static Display* newLaserScanDisplay() { return new LaserScanDisplay(); }
static Display* newMapDisplay() { return new MapDisplay(); }
static Display* newMarkerDisplay() { return new MarkerDisplay(); }
static Display* newMarkerArrayDisplay() { return new MarkerArrayDisplay(); }
static Display* newOdometryDisplay() { return new OdometryDisplay(); }
static Display* newPathDisplay() { return new PathDisplay(); }
static Display* newPointStampedDisplay() { return new PointStampedDisplay(); }
static Display* newPointCloudDisplay() { return new PointCloudDisplay(); }
static Display* newPointCloud2Display() { return new PointCloud2Display(); }
static Display* newPolygonDisplay() { return new PolygonDisplay(); }
static Display* newPoseDisplay() { return new PoseDisplay(); }
static Display* newPoseArrayDisplay() { return new PoseArrayDisplay(); }
static Display* newRangeDisplay() { return new RangeDisplay(); }
static Display* newRelativeHumidityDisplay() { return new RelativeHumidityDisplay(); }
static Display* newRobotModelDisplay() { return new RobotModelDisplay(); }
static Display* newCameraDisplay() { return new CameraDisplay(); }
static Display* newTemperatureDisplay() { return new TemperatureDisplay(); }
static Display* newTFDisplay() { return new TFDisplay(); }
static Display* newWrenchStampedDisplay() { return new WrenchStampedDisplay(); }

DisplayFactory::DisplayFactory()
  : PluginlibFactory<Display>( TINYROS_PACKAGE_NAME, "rviz::Display" )
{
  QSet<QString> message_types;
  
  {
    message_types.clear();
    addBuiltInClass( "rviz", "Group", "A container for Displays", &newDisplayGroup, message_types);
  }

  {
    message_types.clear();
    addBuiltInClass( "rviz", "Axes", "Displays an axis at the Target Frame's origin.", &newAxesDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("sensor_msgs/Image");
    message_types.insert("sensor_msgs/CompressedImage");
    message_types.insert("theora_image_transport/Packet");
    addBuiltInClass( "rviz", "DepthCloud", "Displays point clouds based on depth maps.", &newDepthCloudDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("sensor_msgs/JointState");
    addBuiltInClass( "rviz", "Effort", "Displays from sensor_msgs/JointState/effort messages.", &newEffortDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("sensor_msgs/FluidPressure");
    addBuiltInClass( "rviz", "FluidPressure", "Displays from sensor_msgs/FluidPressure messages.", &newFluidPressureDisplay, message_types);
  }

  {
    message_types.clear();
    addBuiltInClass( "rviz", "Grid", "Displays a grid along the ground plane, centered at the origin of the target frame of reference.", &newGridDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("nav_msgs/GridCells");
    addBuiltInClass( "rviz", "GridCells", "Displays data from a nav_msgs::GridCells message as billboards.", &newGridCellsDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("sensor_msgs/Illuminance");
    addBuiltInClass( "rviz", "Illuminance", "Displays illuminance values from a sensor_msgs/Illuminance topic.", &newIlluminanceDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("sensor_msgs/Image");
    message_types.insert("sensor_msgs/CompressedImage");
    message_types.insert("theora_image_transport/Packet");
    addBuiltInClass( "rviz", "Image", "Displays an image from a sensor_msgs/Image topic, similar to image_view.", &newImageDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("visualization_msgs/InteractiveMarkerUpdate");
    addBuiltInClass( "rviz", "InteractiveMarkers", "Connects to one or more Interactive Marker servers, allowing you to interact with the provided 3D objects.", &newInteractiveMarkerDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("sensor_msgs/LaserScan");
    addBuiltInClass( "rviz", "LaserScan", "Displays the data from a sensor_msgs::LaserScan message as points in the world, drawn as points, billboards, or cubes.", &newLaserScanDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("nav_msgs/OccupancyGrid");
    addBuiltInClass( "rviz", "Map", "Displays an occupancy grid on the ground plane from a nav_msgs::OccupancyGrid.", &newMapDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("visualization_msgs/Marker");
    addBuiltInClass( "rviz", "Marker", "Displays visualization_msgs::Marker messages.", &newMarkerDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("visualization_msgs/MarkerArray");
    addBuiltInClass( "rviz", "MarkerArray", "Displays visualization_msgs::MarkerArray messages without presuming the topic name ends in \"_array\".", &newMarkerArrayDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("nav_msgs/Odometry");
    addBuiltInClass( "rviz", "Odometry", "Accumulates and displays poses from a nav_msgs::Odometry message.", &newOdometryDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("nav_msgs/Path");
    addBuiltInClass( "rviz", "Path", "Displays data from a nav_msgs::Path message as lines.", &newPathDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("geometry_msgs/PointStamped");
    addBuiltInClass( "rviz", "PointStamped", "Displays from geometry_msgs/PointStamped message.", &newPointStampedDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("sensor_msgs/PointCloud");
    addBuiltInClass( "rviz", "PointCloud", "Displays a point cloud from a sensor_msgs::PointCloud message as points in the world, drawn as points, billboards, or cubes.", &newPointCloudDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("sensor_msgs/PointCloud2");
    addBuiltInClass( "rviz", "PointCloud2", "Displays a point cloud from a sensor_msgs::PointCloud2 message as points in the world, drawn as points, billboards, or cubes.", &newPointCloud2Display, message_types);
  }

  {
    message_types.clear();
    message_types.insert("geometry_msgs/PolygonStamped");
    addBuiltInClass( "rviz", "Polygon", "Displays data from a geometry_msgs::PolygonStamped message as lines.", &newPolygonDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("geometry_msgs/PoseStamped");
    addBuiltInClass( "rviz", "Pose", "Displays a geometry_msgs::PoseStamped message.", &newPoseDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("geometry_msgs/PoseArray");
    addBuiltInClass( "rviz", "PoseArray", "Displays the poses from a geometry_msgs::PoseArray message as a cloud of arrows on the ground plane.", &newPoseArrayDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("sensor_msgs/Range");
    addBuiltInClass( "rviz", "Range", "Displays the data from sensor_msgs::Range messages as cones.", &newRangeDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("sensor_msgs/RelativeHumidity");
    addBuiltInClass( "rviz", "RelativeHumidity", "Displays the data from sensor_msgs::RelativeHumidity.", &newRelativeHumidityDisplay, message_types);
  }

  {
    message_types.clear();
    addBuiltInClass( "rviz", "RobotModel", "Displays a visual representation of a robot in the correct pose (as defined by the current TF transforms).", &newRobotModelDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("sensor_msgs/Image");
    message_types.insert("sensor_msgs/CompressedImage");
    message_types.insert("theora_image_transport/Packet");
    addBuiltInClass( "rviz", "Camera", "Displays an image from a camera, with the visualized world rendered behind it.", &newCameraDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("sensor_msgs/Temperature");
    addBuiltInClass( "rviz", "Temperature", "Displays from sensor_msgs/Temperature message.", &newTemperatureDisplay, message_types);
  }

  {
    message_types.clear();
    addBuiltInClass( "rviz", "TF", "Displays the TF transform hierarchy.", &newTFDisplay, message_types);
  }

  {
    message_types.clear();
    message_types.insert("geometry_msgs/WrenchStamped");
    addBuiltInClass( "rviz", "WrenchStamped", "Displays from geometry_msgs/WrenchStamped message.", &newWrenchStampedDisplay, message_types);
  }
}

Display* DisplayFactory::makeRaw( const QString& class_id, QString* error_return )
{
  Display* display = PluginlibFactory<Display>::makeRaw( class_id, error_return );
  if ( display )
  {
    display->setIcon( getIcon( class_id ));
  }
  return display;
}

} // end namespace rviz
