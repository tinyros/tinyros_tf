/*
 * Copyright (c) 2009, Willow Garage, Inc.
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
#include <QObject>

#include "depth_cloud_display.h"
#include "rviz/visualization_manager.h"
#include "rviz/properties/property.h"
#include "rviz/validate_floats.h"

#include "rviz/properties/enum_property.h"
#include "rviz/properties/float_property.h"
#include "rviz/properties/bool_property.h"
#include "rviz/properties/int_property.h"
#include "rviz/frame_manager.h"

#include <tiny_ros/tf/transform_listener.h>

#include <boost/bind.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/foreach.hpp>
#include <boost/shared_ptr.hpp>

#include <OgreSceneNode.h>
#include <OgreSceneManager.h>

#include <image_transport/camera_common.h>
#include <image_transport/subscriber_plugin.h>
#include <image_transport/subscriber_filter.h>

#include "utils/image_encodings.h"

#include "depth_cloud_mld.h"

#include <sstream>
#include <string>
#include <math.h>

namespace enc = sensor_msgs::image_encodings;

namespace rviz
{

DepthCloudDisplay::DepthCloudDisplay()
  : rviz::Display()
  , messages_received_(0)
  , cam_info_sub_(new tinyros::Subscriber<tinyros::sensor_msgs::CameraInfo, DepthCloudDisplay>("", &DepthCloudDisplay::caminfoCallback, this))
  , queue_size_(5)
  , ml_depth_data_(new MultiLayerDepth())
  , angular_thres_(0.5f)
  , trans_thres_(0.01f)

{

  // Depth map properties
  QRegExp depth_filter("depth");
  depth_filter.setCaseSensitivity(Qt::CaseInsensitive);

  topic_filter_property_ = new Property("Topic Filter",
                                        true,
                                        "List only topics with names that relate to depth and color images",
                                        this,
                                        SLOT (updateTopicFilter() ));

  depth_topic_property_ = new RosFilteredTopicProperty("Depth Map Topic",
                                                       "",
                                                       QString::fromStdString(ros::message_traits::datatype<sensor_msgs::Image>()),
                                                       "sensor_msgs::Image topic to subscribe to.",
                                                       depth_filter,
                                                       this,
                                                       SLOT( updateTopic() ));

  depth_transport_property_ = new EnumProperty("Depth Map Transport Hint", "raw", "Preferred method of sending images.", this, SLOT( updateTopic() ));

  connect(depth_transport_property_, SIGNAL( requestOptions( EnumProperty* )), this,  SLOT( fillTransportOptionList( EnumProperty* )));

  depth_transport_property_->setStdString("raw");

  // color image properties
  QRegExp color_filter("color|rgb|bgr|gray|mono");
  color_filter.setCaseSensitivity(Qt::CaseInsensitive);

  color_topic_property_ = new RosFilteredTopicProperty("Color Image Topic",
                                                       "",
                                                       QString::fromStdString(ros::message_traits::datatype<sensor_msgs::Image>()),
                                                       "sensor_msgs::Image topic to subscribe to.",
                                                       color_filter,
                                                       this,
                                                       SLOT( updateTopic() ));

  color_transport_property_ = new EnumProperty("Color Transport Hint", "raw", "Preferred method of sending images.", this, SLOT( updateTopic() ));


  connect(color_transport_property_, SIGNAL( requestOptions( EnumProperty* )), this, SLOT( fillTransportOptionList( EnumProperty* )));

  color_transport_property_->setStdString("raw");

  // Queue size property
  queue_size_property_ = new IntProperty( "Queue Size", queue_size_,
                                          "Advanced: set the size of the incoming message queue.  Increasing this "
                                          "is useful if your incoming TF data is delayed significantly from your"
                                          " image data, but it can greatly increase memory usage if the messages are big.",
                                          this,
                                          SLOT( updateQueueSize() ));
  queue_size_property_->setMin( 1 );

  use_auto_size_property_ = new BoolProperty( "Auto Size",
                                              true,
                                              "Automatically scale each point based on its depth value and the camera parameters.",
                                              this,
                                              SLOT( updateUseAutoSize() ),
                                              this );

  auto_size_factor_property_ = new FloatProperty( "Auto Size Factor", 1,
                                                  "Scaling factor to be applied to the auto size.",
                                                  use_auto_size_property_,
                                                  SLOT( updateAutoSizeFactor() ),
                                                  this );
  auto_size_factor_property_->setMin( 0.0001 );

  use_occlusion_compensation_property_ = new BoolProperty( "Occlusion Compensation",
                                                           false,
                                                           "Keep points alive after they have been occluded by a closer point. Points are removed after a timeout or when the camera frame moves.",
                                                           this,
                                                           SLOT( updateUseOcclusionCompensation() ),
                                                           this );

  occlusion_shadow_timeout_property_ = new FloatProperty( "Occlusion Time-Out",
                                                          30.0f,
                                                          "Amount of seconds before removing occluded points from the depth cloud",
                                                          use_occlusion_compensation_property_,
                                                          SLOT( updateOcclusionTimeOut() ),
                                                          this );

}

void DepthCloudDisplay::onInitialize()
{
  // Instantiate PointCloudCommon class for displaying point clouds
  pointcloud_common_ = new PointCloudCommon(this);

  updateUseAutoSize();
  updateUseOcclusionCompensation();

  // Scan for available transport plugins
  scanForTransportSubscriberPlugins();

  pointcloud_common_->initialize(context_, scene_node_);
  pointcloud_common_->xyz_transformer_property_->hide();
}

DepthCloudDisplay::~DepthCloudDisplay()
{
  if ( initialized() )
  {
    unsubscribe();
    delete pointcloud_common_;
  }

  if (ml_depth_data_)
  {
    delete ml_depth_data_;
  }
}

void DepthCloudDisplay::setTopic( const QString &topic, const QString &datatype )
{
  // Copied from ImageDisplayBase::setTopic()
  if ( datatype == tinyros::sensor_msgs::Image::getTypeStatic() )
  {
    depth_transport_property_->setStdString( "raw" );
    depth_topic_property_->setString( topic );
  }
  else
  {
    int index = topic.lastIndexOf("/");
    if ( index == -1 )
    {
      tinyros_log_warn("DepthCloudDisplay::setTopic() Invalid topic name: %s",
               topic.toStdString().c_str());
      return;
    }
    QString transport = topic.mid(index + 1);
    QString base_topic = topic.mid(0, index);

    depth_transport_property_->setString( transport );
    depth_topic_property_->setString( base_topic );
  }
}

void DepthCloudDisplay::updateQueueSize()
{
  queue_size_ = queue_size_property_->getInt();
}

void DepthCloudDisplay::updateUseAutoSize()
{
  bool use_auto_size = use_auto_size_property_->getBool();
  pointcloud_common_->point_world_size_property_->setReadOnly( use_auto_size );
  pointcloud_common_->setAutoSize( use_auto_size );
  auto_size_factor_property_->setHidden(!use_auto_size);
  if (use_auto_size)
      use_auto_size_property_->expand();
}

void DepthCloudDisplay::updateAutoSizeFactor()
{
}

void DepthCloudDisplay::updateTopicFilter()
{
  bool enabled = topic_filter_property_->getValue().toBool();
  depth_topic_property_->enableFilter(enabled);
  color_topic_property_->enableFilter(enabled);
}

void DepthCloudDisplay::updateUseOcclusionCompensation()
{
  bool use_occlusion_compensation = use_occlusion_compensation_property_->getBool();
  occlusion_shadow_timeout_property_->setHidden(!use_occlusion_compensation);

  if (use_occlusion_compensation)
  {
    updateOcclusionTimeOut();
    ml_depth_data_->enableOcclusionCompensation(true);
    use_occlusion_compensation_property_->expand();
  } else
  {
    ml_depth_data_->enableOcclusionCompensation(false);
  }
}

void DepthCloudDisplay::updateOcclusionTimeOut()
{
  float occlusion_timeout = occlusion_shadow_timeout_property_->getFloat();
  ml_depth_data_->setShadowTimeOut(occlusion_timeout);
}

void DepthCloudDisplay::onEnable()
{
  subscribe();
}

void DepthCloudDisplay::onDisable()
{
  unsubscribe();

  ml_depth_data_->reset();

  clear();
}

void DepthCloudDisplay::subscribe()
{
  if ( !isEnabled() )
  {
    return;
  }

  try
  {
    depthcolor_tf_filter_.reset();
    depthmap_tf_filter_.reset();

    std::string depthmap_topic = depth_topic_property_->getTopicStd();
    std::string color_topic = color_topic_property_->getTopicStd();

    std::string depthmap_transport = depth_transport_property_->getStdString();
    std::string color_transport = color_transport_property_->getStdString();

    if (!depthmap_topic.empty() && !depthmap_transport.empty()) {
      depthmap_tf_filter_.reset(
          new tinyros::tf::MessageFilter<tinyros::sensor_msgs::Image>(*context_->getTFClient(), fixed_frame_.toStdString(), queue_size_));
      depthcolor_tf_filter_.reset(
          new tinyros::tf::MessageFilter<tinyros::sensor_msgs::Image>(*context_->getTFClient(), fixed_frame_.toStdString(), queue_size_));

      // subscribe to CameraInfo  topic
      std::string info_topic = rviz::utils::getCameraInfoTopic(depthmap_topic);
      if (cam_info_sub_->topic_ != info_topic) {
        if (cam_info_sub_->topic_.empty()) {
          cam_info_sub_->topic_ = info_topic;
        } else {
          cam_info_sub_->setEnable(false);
          cam_info_sub_ = new tinyros::Subscriber<tinyros::sensor_msgs::CameraInfo, DepthCloudDisplay>(
            info_topic, &DepthCloudDisplay::caminfoCallback, this);
        }
        tinyros::nh()->subscribe(*cam_info_sub_);
      } 
      cam_info_sub_->setEnable(true);

      if (!color_topic.empty() && !color_transport.empty()) {
        sync_depth_color_ = true;
        depthcolor_tf_filter_->registerCallback(std::bind(&DepthCloudDisplay::processMessageRGB, this, std::placeholders::_1));
        depthcolor_tf_filter_->connectInput(color_topic);
        pointcloud_common_->color_transformer_property_->setValue("RGB8");
      } else {
        sync_depth_color_ = false;
      }
      depthmap_tf_filter_->registerCallback(std::bind(&DepthCloudDisplay::processMessage, this, std::placeholders::_1));
      depthmap_tf_filter_->connectInput(depthmap_topic);

    }
  }
  catch (std::exception& e)
  {
    setStatus( StatusProperty::Error, "Message", QString("Error subscribing: ") + e.what() );
  }
}

void DepthCloudDisplay::caminfoCallback( tinyros::sensor_msgs::CameraInfoConstPtr msg )
{
  boost::mutex::scoped_lock lock(cam_info_mutex_);
  cam_info_ = msg;
 }

void DepthCloudDisplay::unsubscribe()
{
  clear();

  try
  {
    // reset all filters
    sync_depth_color_ = false;
    depthmap_tf_filter_.reset();
    depthcolor_tf_filter_.reset();
    cam_info_sub_->setEnable(false);
  }
  catch (std::exception& e)
  {
    setStatus( StatusProperty::Error, "Message", QString("Error unsubscribing: ") + e.what() );
  }
}


void DepthCloudDisplay::clear()
{

  boost::mutex::scoped_lock lock(mutex_);

  pointcloud_common_->reset();
}


void DepthCloudDisplay::update(float wall_dt, float ros_dt)
{

  boost::mutex::scoped_lock lock(mutex_);

  pointcloud_common_->update(wall_dt, ros_dt);
}


void DepthCloudDisplay::reset()
{
  clear();
  messages_received_ = 0;
  setStatus( StatusProperty::Ok, "Depth Map", "0 depth maps received" );
  setStatus( StatusProperty::Ok, "Message", "Ok" );
}

void DepthCloudDisplay::processMessageRGB(tinyros::sensor_msgs::ImageConstPtr rgb_msg)
{
  if (sync_depth_color_) {
    boost::mutex::scoped_lock lock(sync_mutex_);
    current_rgb_ = rgb_msg;
    processMessage(current_depth_, current_rgb_);
  } else {
    processMessage(sensor_msgs::ImageConstPtr(), rgb_msg);
  }
}

void DepthCloudDisplay::processMessage(tinyros::sensor_msgs::ImageConstPtr depth_msg)
{
  if (sync_depth_color_) {
    boost::mutex::scoped_lock lock(sync_mutex_);
    current_depth_ = depth_msg;
    processMessage(current_depth_, current_rgb_);
  } else {
    processMessage(depth_msg, sensor_msgs::ImageConstPtr());
  }
}

void DepthCloudDisplay::processMessage(tinyros::sensor_msgs::ImageConstPtr depth_msg,
                                       tinyros::sensor_msgs::ImageConstPtr rgb_msg)
{
  if (context_->getFrameManager()->getPause() )
  {
    return;
  }

  std::ostringstream s;

  ++messages_received_;
  setStatus( StatusProperty::Ok, "Depth Map", QString::number(messages_received_) + " depth maps received");
  setStatus( StatusProperty::Ok, "Message", "Ok" );

  sensor_msgs::CameraInfo::ConstPtr cam_info;
  {
    boost::mutex::scoped_lock lock(cam_info_mutex_);
    cam_info = cam_info_;
  }

  if ( !cam_info || !depth_msg )
  {
    return;
  }

  s.str("");
  s << depth_msg->width << " x " << depth_msg->height;
  setStatusStd( StatusProperty::Ok, "Depth Image Size", s.str() );

  if (rgb_msg)
  {
    s.str("");
    s << rgb_msg->width << " x " << rgb_msg->height;
    setStatusStd( StatusProperty::Ok, "Image Size", s.str() );

    if (depth_msg->header.frame_id != rgb_msg->header.frame_id)
    {
      std::stringstream errorMsg;
      errorMsg << "Depth image frame id [" << depth_msg->header.frame_id.c_str()
           << "] doesn't match color image frame id [" << rgb_msg->header.frame_id.c_str() << "]";
      setStatusStd( StatusProperty::Warn, "Message", errorMsg.str() );
    }
  }

  if ( use_auto_size_property_->getBool() )
  {
    float f = cam_info->K[0];
    float bx = cam_info->binning_x > 0 ? cam_info->binning_x : 1.0;
    float s = auto_size_factor_property_->getFloat();
    pointcloud_common_->point_world_size_property_->setFloat( s / f * bx );
  }

  bool use_occlusion_compensation = use_occlusion_compensation_property_->getBool();

  if (use_occlusion_compensation)
  {
    // reset depth cloud display if camera moves
    Ogre::Quaternion orientation;
    Ogre::Vector3 position;

    if (!context_->getFrameManager()->getTransform(depth_msg->header, position, orientation))
    {
      setStatus(
          StatusProperty::Error,
          "Message",
          QString("Failed to transform from frame [") + depth_msg->header.frame_id.c_str() + QString("] to frame [")
              + context_->getFrameManager()->getFixedFrame().c_str() + QString("]"));
      return;
    }
    else
    {
      Ogre::Radian angle;
      Ogre::Vector3 axis;

      (current_orientation_.Inverse() * orientation).ToAngleAxis(angle, axis);

      float angle_deg = angle.valueDegrees();
      if (angle_deg >= 180.0f)
        angle_deg -= 180.0f;
      if (angle_deg < -180.0f)
        angle_deg += 180.0f;

      if (trans_thres_ == 0.0 || angular_thres_ == 0.0 ||
          (position - current_position_).length() > trans_thres_
          || angle_deg > angular_thres_)
      {
        // camera orientation/position changed
        current_position_ = position;
        current_orientation_ = orientation;

        // reset multi-layered depth image
        ml_depth_data_->reset();
      }
    }
  }

  try
  {
    tinyros::sensor_msgs::PointCloud2Ptr cloud_msg = ml_depth_data_->generatePointCloudFromDepth(depth_msg, rgb_msg, cam_info);

    if ( !cloud_msg.get() )
    {
      throw MultiLayerDepthException("generatePointCloudFromDepth() returned zero.");
    }
    cloud_msg->header = depth_msg->header;

    // add point cloud message to pointcloud_common to be visualized
    pointcloud_common_->addMessage(cloud_msg);
  }
  catch (MultiLayerDepthException& e)
  {
    setStatus(StatusProperty::Error, "Message", QString("Error updating depth cloud: ") + e.what());
  }
}


void DepthCloudDisplay::scanForTransportSubscriberPlugins()
{
  
}

void DepthCloudDisplay::updateTopic()
{
  unsubscribe();
  reset();
  subscribe();
  context_->queueRender();
}

void DepthCloudDisplay::fillTransportOptionList(EnumProperty* property)
{
  property->clearOptions();

  std::vector<std::string> choices;

  choices.push_back("raw");

  // Loop over all current ROS topic names
  rviz::utils::V_TopicInfo topics;
  rviz::utils::getTopics(topics);
  rviz::utils::V_TopicInfo::iterator it = topics.begin();
  rviz::utils::V_TopicInfo::iterator end = topics.end();
  for (; it != end; ++it)
  {
    // If the beginning of this topic name is the same as topic_,
    // and the whole string is not the same,
    // and the next character is /
    // and there are no further slashes from there to the end,
    // then consider this a possible transport topic.
    const rviz::utils::TopicInfo& ti = *it;
    const std::string& topic_name = ti.name;
    const std::string& topic = depth_topic_property_->getStdString();

    if (topic_name.find(topic) == 0 && topic_name != topic && topic_name[topic.size()] == '/'
        && topic_name.find('/', topic.size() + 1) == std::string::npos)
    {
      std::string transport_type = topic_name.substr(topic.size() + 1);

      // If the transport type string found above is in the set of
      // supported transport type plugins, add it to the list.
      if (transport_plugin_types_.find(transport_type) != transport_plugin_types_.end())
      {
        choices.push_back(transport_type);
      }
    }
  }

  for (size_t i = 0; i < choices.size(); i++)
  {
    property->addOptionStd(choices[i]);
  }
}

void DepthCloudDisplay::fixedFrameChanged()
{
  Display::reset();
}

} // namespace rviz

