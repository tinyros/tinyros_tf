#ifndef _TINYROS_ROSTOPIC_SUBSCRIBERS_h
#define _TINYROS_ROSTOPIC_SUBSCRIBERS_h

#include "tiny_ros/ros.h"
#include "tiny_ros/actionlib_msgs/GoalStatus.h"
#include "tiny_ros/actionlib_msgs/GoalStatusArray.h"
#include "tiny_ros/actionlib_msgs/GoalID.h"
#include "tiny_ros/diagnostic_msgs/DiagnosticStatus.h"
#include "tiny_ros/diagnostic_msgs/DiagnosticArray.h"
#include "tiny_ros/diagnostic_msgs/KeyValue.h"
#include "tiny_ros/gazebo_msgs/LinkStates.h"
#include "tiny_ros/gazebo_msgs/ContactState.h"
#include "tiny_ros/gazebo_msgs/LinkState.h"
#include "tiny_ros/gazebo_msgs/ModelState.h"
#include "tiny_ros/gazebo_msgs/ODEPhysics.h"
#include "tiny_ros/gazebo_msgs/ContactsState.h"
#include "tiny_ros/gazebo_msgs/ODEJointProperties.h"
#include "tiny_ros/gazebo_msgs/WorldState.h"
#include "tiny_ros/gazebo_msgs/ModelStates.h"
#include "tiny_ros/geometry_msgs/PolygonStamped.h"
#include "tiny_ros/geometry_msgs/PoseWithCovariance.h"
#include "tiny_ros/geometry_msgs/WrenchStamped.h"
#include "tiny_ros/geometry_msgs/Pose.h"
#include "tiny_ros/geometry_msgs/QuaternionStamped.h"
#include "tiny_ros/geometry_msgs/Point.h"
#include "tiny_ros/geometry_msgs/PoseWithCovarianceStamped.h"
#include "tiny_ros/geometry_msgs/Transform.h"
#include "tiny_ros/geometry_msgs/TwistWithCovariance.h"
#include "tiny_ros/geometry_msgs/Quaternion.h"
#include "tiny_ros/geometry_msgs/InertiaStamped.h"
#include "tiny_ros/geometry_msgs/Accel.h"
#include "tiny_ros/geometry_msgs/Polygon.h"
#include "tiny_ros/geometry_msgs/AccelWithCovariance.h"
#include "tiny_ros/geometry_msgs/TwistStamped.h"
#include "tiny_ros/geometry_msgs/Twist.h"
#include "tiny_ros/geometry_msgs/AccelStamped.h"
#include "tiny_ros/geometry_msgs/Point32.h"
#include "tiny_ros/geometry_msgs/PointStamped.h"
#include "tiny_ros/geometry_msgs/PoseArray.h"
#include "tiny_ros/geometry_msgs/Vector3Stamped.h"
#include "tiny_ros/geometry_msgs/Wrench.h"
#include "tiny_ros/geometry_msgs/Inertia.h"
#include "tiny_ros/geometry_msgs/Vector3.h"
#include "tiny_ros/geometry_msgs/Pose2D.h"
#include "tiny_ros/geometry_msgs/PoseStamped.h"
#include "tiny_ros/geometry_msgs/TwistWithCovarianceStamped.h"
#include "tiny_ros/geometry_msgs/AccelWithCovarianceStamped.h"
#include "tiny_ros/geometry_msgs/TransformStamped.h"
#include "tiny_ros/map_msgs/ProjectedMap.h"
#include "tiny_ros/map_msgs/PointCloud2Update.h"
#include "tiny_ros/map_msgs/OccupancyGridUpdate.h"
#include "tiny_ros/map_msgs/ProjectedMapInfo.h"
#include "tiny_ros/nav_msgs/GetMapResult.h"
#include "tiny_ros/nav_msgs/GetMapActionGoal.h"
#include "tiny_ros/nav_msgs/GetMapGoal.h"
#include "tiny_ros/nav_msgs/MapMetaData.h"
#include "tiny_ros/nav_msgs/GetMapFeedback.h"
#include "tiny_ros/nav_msgs/GetMapAction.h"
#include "tiny_ros/nav_msgs/GetMapActionFeedback.h"
#include "tiny_ros/nav_msgs/GridCells.h"
#include "tiny_ros/nav_msgs/Path.h"
#include "tiny_ros/nav_msgs/GetMapActionResult.h"
#include "tiny_ros/nav_msgs/OccupancyGrid.h"
#include "tiny_ros/nav_msgs/Odometry.h"
#include "tiny_ros/rosgraph_msgs/Log.h"
#include "tiny_ros/rosgraph_msgs/TopicStatistics.h"
#include "tiny_ros/rosgraph_msgs/Clock.h"
#include "tiny_ros/sensor_msgs/MultiDOFJointState.h"
#include "tiny_ros/sensor_msgs/TimeReference.h"
#include "tiny_ros/sensor_msgs/Range.h"
#include "tiny_ros/sensor_msgs/ChannelFloat32.h"
#include "tiny_ros/sensor_msgs/CameraInfo.h"
#include "tiny_ros/sensor_msgs/JointState.h"
#include "tiny_ros/sensor_msgs/BatteryState.h"
#include "tiny_ros/sensor_msgs/Imu.h"
#include "tiny_ros/sensor_msgs/LaserScan.h"
#include "tiny_ros/sensor_msgs/PointField.h"
#include "tiny_ros/sensor_msgs/FluidPressure.h"
#include "tiny_ros/sensor_msgs/Temperature.h"
#include "tiny_ros/sensor_msgs/Illuminance.h"
#include "tiny_ros/sensor_msgs/PointCloud2.h"
#include "tiny_ros/sensor_msgs/Image.h"
#include "tiny_ros/sensor_msgs/Joy.h"
#include "tiny_ros/sensor_msgs/NavSatFix.h"
#include "tiny_ros/sensor_msgs/PointCloud.h"
#include "tiny_ros/sensor_msgs/MagneticField.h"
#include "tiny_ros/sensor_msgs/CompressedImage.h"
#include "tiny_ros/sensor_msgs/RelativeHumidity.h"
#include "tiny_ros/sensor_msgs/NavSatStatus.h"
#include "tiny_ros/sensor_msgs/JoyFeedbackArray.h"
#include "tiny_ros/sensor_msgs/RegionOfInterest.h"
#include "tiny_ros/sensor_msgs/LaserEcho.h"
#include "tiny_ros/sensor_msgs/JoyFeedback.h"
#include "tiny_ros/sensor_msgs/MultiEchoLaserScan.h"
#include "tiny_ros/shape_msgs/Mesh.h"
#include "tiny_ros/shape_msgs/Plane.h"
#include "tiny_ros/shape_msgs/SolidPrimitive.h"
#include "tiny_ros/shape_msgs/MeshTriangle.h"
#include "tiny_ros/smach_msgs/SmachContainerInitialStatusCmd.h"
#include "tiny_ros/smach_msgs/SmachContainerStructure.h"
#include "tiny_ros/smach_msgs/SmachContainerStatus.h"
#include "tiny_ros/std_msgs/Float64MultiArray.h"
#include "tiny_ros/std_msgs/String.h"
#include "tiny_ros/std_msgs/MultiArrayLayout.h"
#include "tiny_ros/std_msgs/Int8MultiArray.h"
#include "tiny_ros/std_msgs/Char.h"
#include "tiny_ros/std_msgs/UInt64MultiArray.h"
#include "tiny_ros/std_msgs/UInt8MultiArray.h"
#include "tiny_ros/std_msgs/Time.h"
#include "tiny_ros/std_msgs/UInt64.h"
#include "tiny_ros/std_msgs/Int16MultiArray.h"
#include "tiny_ros/std_msgs/UInt16.h"
#include "tiny_ros/std_msgs/Int64.h"
#include "tiny_ros/std_msgs/Float32MultiArray.h"
#include "tiny_ros/std_msgs/ColorRGBA.h"
#include "tiny_ros/std_msgs/Byte.h"
#include "tiny_ros/std_msgs/UInt32MultiArray.h"
#include "tiny_ros/std_msgs/Float64.h"
#include "tiny_ros/std_msgs/UInt8.h"
#include "tiny_ros/std_msgs/Bool.h"
#include "tiny_ros/std_msgs/Duration.h"
#include "tiny_ros/std_msgs/Int16.h"
#include "tiny_ros/std_msgs/Int32MultiArray.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/std_msgs/Float32.h"
#include "tiny_ros/std_msgs/UInt16MultiArray.h"
#include "tiny_ros/std_msgs/Int32.h"
#include "tiny_ros/std_msgs/ByteMultiArray.h"
#include "tiny_ros/std_msgs/Empty.h"
#include "tiny_ros/std_msgs/MultiArrayDimension.h"
#include "tiny_ros/std_msgs/Int8.h"
#include "tiny_ros/std_msgs/UInt32.h"
#include "tiny_ros/std_msgs/Int64MultiArray.h"
#include "tiny_ros/stereo_msgs/DisparityImage.h"
#include "tiny_ros/tf/tfMessage.h"
#include "tiny_ros/tinyros_hello/TinyrosHello.h"
#include "tiny_ros/tinyros_msgs/TopicInfo.h"
#include "tiny_ros/tinyros_msgs/SyncTime.h"
#include "tiny_ros/tinyros_msgs/Log.h"
#include "tiny_ros/trajectory_msgs/MultiDOFJointTrajectory.h"
#include "tiny_ros/trajectory_msgs/JointTrajectory.h"
#include "tiny_ros/trajectory_msgs/MultiDOFJointTrajectoryPoint.h"
#include "tiny_ros/trajectory_msgs/JointTrajectoryPoint.h"

namespace tinyros
{
template<typename MsgT>
class EchoSubscriber: public tinyros::Subscriber_
{
public:
  MsgT msg;
  virtual void callback(unsigned char* data)
  {
    MsgT tmsg;
    tmsg.deserialize(data);
    spdlog::get("logger")->info("{0}[{1}]->>{2}", topic_, getMsgType(), tmsg.echo());
  }
  virtual std::string getMsgType()
  {
    return this->msg.getType();
  }
  virtual std::string getMsgMD5()
  {
    return this->msg.getMD5();
  }
  virtual int getEndpointType()
  {
    return tinyros_msgs::TopicInfo::ID_SUBSCRIBER;
  }
};

static std::map<std::string, tinyros::Subscriber_*> rostopic_subscribers = {
    {"actionlib_msgs/GoalStatus", new EchoSubscriber<tinyros::actionlib_msgs::GoalStatus>()},
    {"actionlib_msgs/GoalStatusArray", new EchoSubscriber<tinyros::actionlib_msgs::GoalStatusArray>()},
    {"actionlib_msgs/GoalID", new EchoSubscriber<tinyros::actionlib_msgs::GoalID>()},
    {"diagnostic_msgs/DiagnosticStatus", new EchoSubscriber<tinyros::diagnostic_msgs::DiagnosticStatus>()},
    {"diagnostic_msgs/DiagnosticArray", new EchoSubscriber<tinyros::diagnostic_msgs::DiagnosticArray>()},
    {"diagnostic_msgs/KeyValue", new EchoSubscriber<tinyros::diagnostic_msgs::KeyValue>()},
    {"gazebo_msgs/LinkStates", new EchoSubscriber<tinyros::gazebo_msgs::LinkStates>()},
    {"gazebo_msgs/ContactState", new EchoSubscriber<tinyros::gazebo_msgs::ContactState>()},
    {"gazebo_msgs/LinkState", new EchoSubscriber<tinyros::gazebo_msgs::LinkState>()},
    {"gazebo_msgs/ModelState", new EchoSubscriber<tinyros::gazebo_msgs::ModelState>()},
    {"gazebo_msgs/ODEPhysics", new EchoSubscriber<tinyros::gazebo_msgs::ODEPhysics>()},
    {"gazebo_msgs/ContactsState", new EchoSubscriber<tinyros::gazebo_msgs::ContactsState>()},
    {"gazebo_msgs/ODEJointProperties", new EchoSubscriber<tinyros::gazebo_msgs::ODEJointProperties>()},
    {"gazebo_msgs/WorldState", new EchoSubscriber<tinyros::gazebo_msgs::WorldState>()},
    {"gazebo_msgs/ModelStates", new EchoSubscriber<tinyros::gazebo_msgs::ModelStates>()},
    {"geometry_msgs/PolygonStamped", new EchoSubscriber<tinyros::geometry_msgs::PolygonStamped>()},
    {"geometry_msgs/PoseWithCovariance", new EchoSubscriber<tinyros::geometry_msgs::PoseWithCovariance>()},
    {"geometry_msgs/WrenchStamped", new EchoSubscriber<tinyros::geometry_msgs::WrenchStamped>()},
    {"geometry_msgs/Pose", new EchoSubscriber<tinyros::geometry_msgs::Pose>()},
    {"geometry_msgs/QuaternionStamped", new EchoSubscriber<tinyros::geometry_msgs::QuaternionStamped>()},
    {"geometry_msgs/Point", new EchoSubscriber<tinyros::geometry_msgs::Point>()},
    {"geometry_msgs/PoseWithCovarianceStamped", new EchoSubscriber<tinyros::geometry_msgs::PoseWithCovarianceStamped>()},
    {"geometry_msgs/Transform", new EchoSubscriber<tinyros::geometry_msgs::Transform>()},
    {"geometry_msgs/TwistWithCovariance", new EchoSubscriber<tinyros::geometry_msgs::TwistWithCovariance>()},
    {"geometry_msgs/Quaternion", new EchoSubscriber<tinyros::geometry_msgs::Quaternion>()},
    {"geometry_msgs/InertiaStamped", new EchoSubscriber<tinyros::geometry_msgs::InertiaStamped>()},
    {"geometry_msgs/Accel", new EchoSubscriber<tinyros::geometry_msgs::Accel>()},
    {"geometry_msgs/Polygon", new EchoSubscriber<tinyros::geometry_msgs::Polygon>()},
    {"geometry_msgs/AccelWithCovariance", new EchoSubscriber<tinyros::geometry_msgs::AccelWithCovariance>()},
    {"geometry_msgs/TwistStamped", new EchoSubscriber<tinyros::geometry_msgs::TwistStamped>()},
    {"geometry_msgs/Twist", new EchoSubscriber<tinyros::geometry_msgs::Twist>()},
    {"geometry_msgs/AccelStamped", new EchoSubscriber<tinyros::geometry_msgs::AccelStamped>()},
    {"geometry_msgs/Point32", new EchoSubscriber<tinyros::geometry_msgs::Point32>()},
    {"geometry_msgs/PointStamped", new EchoSubscriber<tinyros::geometry_msgs::PointStamped>()},
    {"geometry_msgs/PoseArray", new EchoSubscriber<tinyros::geometry_msgs::PoseArray>()},
    {"geometry_msgs/Vector3Stamped", new EchoSubscriber<tinyros::geometry_msgs::Vector3Stamped>()},
    {"geometry_msgs/Wrench", new EchoSubscriber<tinyros::geometry_msgs::Wrench>()},
    {"geometry_msgs/Inertia", new EchoSubscriber<tinyros::geometry_msgs::Inertia>()},
    {"geometry_msgs/Vector3", new EchoSubscriber<tinyros::geometry_msgs::Vector3>()},
    {"geometry_msgs/Pose2D", new EchoSubscriber<tinyros::geometry_msgs::Pose2D>()},
    {"geometry_msgs/PoseStamped", new EchoSubscriber<tinyros::geometry_msgs::PoseStamped>()},
    {"geometry_msgs/TwistWithCovarianceStamped", new EchoSubscriber<tinyros::geometry_msgs::TwistWithCovarianceStamped>()},
    {"geometry_msgs/AccelWithCovarianceStamped", new EchoSubscriber<tinyros::geometry_msgs::AccelWithCovarianceStamped>()},
    {"geometry_msgs/TransformStamped", new EchoSubscriber<tinyros::geometry_msgs::TransformStamped>()},
    {"map_msgs/ProjectedMap", new EchoSubscriber<tinyros::map_msgs::ProjectedMap>()},
    {"map_msgs/PointCloud2Update", new EchoSubscriber<tinyros::map_msgs::PointCloud2Update>()},
    {"map_msgs/OccupancyGridUpdate", new EchoSubscriber<tinyros::map_msgs::OccupancyGridUpdate>()},
    {"map_msgs/ProjectedMapInfo", new EchoSubscriber<tinyros::map_msgs::ProjectedMapInfo>()},
    {"nav_msgs/GetMapResult", new EchoSubscriber<tinyros::nav_msgs::GetMapResult>()},
    {"nav_msgs/GetMapActionGoal", new EchoSubscriber<tinyros::nav_msgs::GetMapActionGoal>()},
    {"nav_msgs/GetMapGoal", new EchoSubscriber<tinyros::nav_msgs::GetMapGoal>()},
    {"nav_msgs/MapMetaData", new EchoSubscriber<tinyros::nav_msgs::MapMetaData>()},
    {"nav_msgs/GetMapFeedback", new EchoSubscriber<tinyros::nav_msgs::GetMapFeedback>()},
    {"nav_msgs/GetMapAction", new EchoSubscriber<tinyros::nav_msgs::GetMapAction>()},
    {"nav_msgs/GetMapActionFeedback", new EchoSubscriber<tinyros::nav_msgs::GetMapActionFeedback>()},
    {"nav_msgs/GridCells", new EchoSubscriber<tinyros::nav_msgs::GridCells>()},
    {"nav_msgs/Path", new EchoSubscriber<tinyros::nav_msgs::Path>()},
    {"nav_msgs/GetMapActionResult", new EchoSubscriber<tinyros::nav_msgs::GetMapActionResult>()},
    {"nav_msgs/OccupancyGrid", new EchoSubscriber<tinyros::nav_msgs::OccupancyGrid>()},
    {"nav_msgs/Odometry", new EchoSubscriber<tinyros::nav_msgs::Odometry>()},
    {"rosgraph_msgs/Log", new EchoSubscriber<tinyros::rosgraph_msgs::Log>()},
    {"rosgraph_msgs/TopicStatistics", new EchoSubscriber<tinyros::rosgraph_msgs::TopicStatistics>()},
    {"rosgraph_msgs/Clock", new EchoSubscriber<tinyros::rosgraph_msgs::Clock>()},
    {"sensor_msgs/MultiDOFJointState", new EchoSubscriber<tinyros::sensor_msgs::MultiDOFJointState>()},
    {"sensor_msgs/TimeReference", new EchoSubscriber<tinyros::sensor_msgs::TimeReference>()},
    {"sensor_msgs/Range", new EchoSubscriber<tinyros::sensor_msgs::Range>()},
    {"sensor_msgs/ChannelFloat32", new EchoSubscriber<tinyros::sensor_msgs::ChannelFloat32>()},
    {"sensor_msgs/CameraInfo", new EchoSubscriber<tinyros::sensor_msgs::CameraInfo>()},
    {"sensor_msgs/JointState", new EchoSubscriber<tinyros::sensor_msgs::JointState>()},
    {"sensor_msgs/BatteryState", new EchoSubscriber<tinyros::sensor_msgs::BatteryState>()},
    {"sensor_msgs/Imu", new EchoSubscriber<tinyros::sensor_msgs::Imu>()},
    {"sensor_msgs/LaserScan", new EchoSubscriber<tinyros::sensor_msgs::LaserScan>()},
    {"sensor_msgs/PointField", new EchoSubscriber<tinyros::sensor_msgs::PointField>()},
    {"sensor_msgs/FluidPressure", new EchoSubscriber<tinyros::sensor_msgs::FluidPressure>()},
    {"sensor_msgs/Temperature", new EchoSubscriber<tinyros::sensor_msgs::Temperature>()},
    {"sensor_msgs/Illuminance", new EchoSubscriber<tinyros::sensor_msgs::Illuminance>()},
    {"sensor_msgs/PointCloud2", new EchoSubscriber<tinyros::sensor_msgs::PointCloud2>()},
    {"sensor_msgs/Image", new EchoSubscriber<tinyros::sensor_msgs::Image>()},
    {"sensor_msgs/Joy", new EchoSubscriber<tinyros::sensor_msgs::Joy>()},
    {"sensor_msgs/NavSatFix", new EchoSubscriber<tinyros::sensor_msgs::NavSatFix>()},
    {"sensor_msgs/PointCloud", new EchoSubscriber<tinyros::sensor_msgs::PointCloud>()},
    {"sensor_msgs/MagneticField", new EchoSubscriber<tinyros::sensor_msgs::MagneticField>()},
    {"sensor_msgs/CompressedImage", new EchoSubscriber<tinyros::sensor_msgs::CompressedImage>()},
    {"sensor_msgs/RelativeHumidity", new EchoSubscriber<tinyros::sensor_msgs::RelativeHumidity>()},
    {"sensor_msgs/NavSatStatus", new EchoSubscriber<tinyros::sensor_msgs::NavSatStatus>()},
    {"sensor_msgs/JoyFeedbackArray", new EchoSubscriber<tinyros::sensor_msgs::JoyFeedbackArray>()},
    {"sensor_msgs/RegionOfInterest", new EchoSubscriber<tinyros::sensor_msgs::RegionOfInterest>()},
    {"sensor_msgs/LaserEcho", new EchoSubscriber<tinyros::sensor_msgs::LaserEcho>()},
    {"sensor_msgs/JoyFeedback", new EchoSubscriber<tinyros::sensor_msgs::JoyFeedback>()},
    {"sensor_msgs/MultiEchoLaserScan", new EchoSubscriber<tinyros::sensor_msgs::MultiEchoLaserScan>()},
    {"shape_msgs/Mesh", new EchoSubscriber<tinyros::shape_msgs::Mesh>()},
    {"shape_msgs/Plane", new EchoSubscriber<tinyros::shape_msgs::Plane>()},
    {"shape_msgs/SolidPrimitive", new EchoSubscriber<tinyros::shape_msgs::SolidPrimitive>()},
    {"shape_msgs/MeshTriangle", new EchoSubscriber<tinyros::shape_msgs::MeshTriangle>()},
    {"smach_msgs/SmachContainerInitialStatusCmd", new EchoSubscriber<tinyros::smach_msgs::SmachContainerInitialStatusCmd>()},
    {"smach_msgs/SmachContainerStructure", new EchoSubscriber<tinyros::smach_msgs::SmachContainerStructure>()},
    {"smach_msgs/SmachContainerStatus", new EchoSubscriber<tinyros::smach_msgs::SmachContainerStatus>()},
    {"std_msgs/Float64MultiArray", new EchoSubscriber<tinyros::std_msgs::Float64MultiArray>()},
    {"std_msgs/String", new EchoSubscriber<tinyros::std_msgs::String>()},
    {"std_msgs/MultiArrayLayout", new EchoSubscriber<tinyros::std_msgs::MultiArrayLayout>()},
    {"std_msgs/Int8MultiArray", new EchoSubscriber<tinyros::std_msgs::Int8MultiArray>()},
    {"std_msgs/Char", new EchoSubscriber<tinyros::std_msgs::Char>()},
    {"std_msgs/UInt64MultiArray", new EchoSubscriber<tinyros::std_msgs::UInt64MultiArray>()},
    {"std_msgs/UInt8MultiArray", new EchoSubscriber<tinyros::std_msgs::UInt8MultiArray>()},
    {"std_msgs/Time", new EchoSubscriber<tinyros::std_msgs::Time>()},
    {"std_msgs/UInt64", new EchoSubscriber<tinyros::std_msgs::UInt64>()},
    {"std_msgs/Int16MultiArray", new EchoSubscriber<tinyros::std_msgs::Int16MultiArray>()},
    {"std_msgs/UInt16", new EchoSubscriber<tinyros::std_msgs::UInt16>()},
    {"std_msgs/Int64", new EchoSubscriber<tinyros::std_msgs::Int64>()},
    {"std_msgs/Float32MultiArray", new EchoSubscriber<tinyros::std_msgs::Float32MultiArray>()},
    {"std_msgs/ColorRGBA", new EchoSubscriber<tinyros::std_msgs::ColorRGBA>()},
    {"std_msgs/Byte", new EchoSubscriber<tinyros::std_msgs::Byte>()},
    {"std_msgs/UInt32MultiArray", new EchoSubscriber<tinyros::std_msgs::UInt32MultiArray>()},
    {"std_msgs/Float64", new EchoSubscriber<tinyros::std_msgs::Float64>()},
    {"std_msgs/UInt8", new EchoSubscriber<tinyros::std_msgs::UInt8>()},
    {"std_msgs/Bool", new EchoSubscriber<tinyros::std_msgs::Bool>()},
    {"std_msgs/Duration", new EchoSubscriber<tinyros::std_msgs::Duration>()},
    {"std_msgs/Int16", new EchoSubscriber<tinyros::std_msgs::Int16>()},
    {"std_msgs/Int32MultiArray", new EchoSubscriber<tinyros::std_msgs::Int32MultiArray>()},
    {"std_msgs/Header", new EchoSubscriber<tinyros::std_msgs::Header>()},
    {"std_msgs/Float32", new EchoSubscriber<tinyros::std_msgs::Float32>()},
    {"std_msgs/UInt16MultiArray", new EchoSubscriber<tinyros::std_msgs::UInt16MultiArray>()},
    {"std_msgs/Int32", new EchoSubscriber<tinyros::std_msgs::Int32>()},
    {"std_msgs/ByteMultiArray", new EchoSubscriber<tinyros::std_msgs::ByteMultiArray>()},
    {"std_msgs/Empty", new EchoSubscriber<tinyros::std_msgs::Empty>()},
    {"std_msgs/MultiArrayDimension", new EchoSubscriber<tinyros::std_msgs::MultiArrayDimension>()},
    {"std_msgs/Int8", new EchoSubscriber<tinyros::std_msgs::Int8>()},
    {"std_msgs/UInt32", new EchoSubscriber<tinyros::std_msgs::UInt32>()},
    {"std_msgs/Int64MultiArray", new EchoSubscriber<tinyros::std_msgs::Int64MultiArray>()},
    {"stereo_msgs/DisparityImage", new EchoSubscriber<tinyros::stereo_msgs::DisparityImage>()},
    {"tf/tfMessage", new EchoSubscriber<tinyros::tf::tfMessage>()},
    {"tinyros_hello/TinyrosHello", new EchoSubscriber<tinyros::tinyros_hello::TinyrosHello>()},
    {"tinyros_msgs/TopicInfo", new EchoSubscriber<tinyros::tinyros_msgs::TopicInfo>()},
    {"tinyros_msgs/SyncTime", new EchoSubscriber<tinyros::tinyros_msgs::SyncTime>()},
    {"tinyros_msgs/Log", new EchoSubscriber<tinyros::tinyros_msgs::Log>()},
    {"trajectory_msgs/MultiDOFJointTrajectory", new EchoSubscriber<tinyros::trajectory_msgs::MultiDOFJointTrajectory>()},
    {"trajectory_msgs/JointTrajectory", new EchoSubscriber<tinyros::trajectory_msgs::JointTrajectory>()},
    {"trajectory_msgs/MultiDOFJointTrajectoryPoint", new EchoSubscriber<tinyros::trajectory_msgs::MultiDOFJointTrajectoryPoint>()},
    {"trajectory_msgs/JointTrajectoryPoint", new EchoSubscriber<tinyros::trajectory_msgs::JointTrajectoryPoint>()},
};

}
#endif

