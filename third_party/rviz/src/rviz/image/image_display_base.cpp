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

#include <boost/algorithm/string/erase.hpp>
#include <boost/foreach.hpp>
#include <boost/shared_ptr.hpp>

#include "rviz/validate_floats.h"

#include "rviz/image/image_display_base.h"
#include "tiny_ros/tf/tf.h"
#include "rviz/utils/utils.h"

namespace rviz
{

ImageDisplayBase::ImageDisplayBase() :
    Display()
    , tf_filter_()
    , messages_received_(0)
    , sub_(new tinyros::Subscriber<tinyros::sensor_msgs::Image, ImageDisplayBase>("", &ImageDisplayBase::incomingMessage, this))
{
  topic_property_ = new RosTopicProperty("Image Topic", "",
                                         QString::fromStdString(tinyros::sensor_msgs::Image::getTypeStatic()),
                                         "sensor_msgs::Image topic to subscribe to.", this, SLOT( updateTopic() ));

  transport_property_ = new EnumProperty("Transport Hint", "raw", "Preferred method of sending images.", this,
                                         SLOT( updateTopic() ));

  connect(transport_property_, SIGNAL( requestOptions( EnumProperty* )), this,
          SLOT( fillTransportOptionList( EnumProperty* )));

  queue_size_property_ = new IntProperty( "Queue Size", 2,
                                          "Advanced: set the size of the incoming message queue.  Increasing this "
                                          "is useful if your incoming TF data is delayed significantly from your"
                                          " image data, but it can greatly increase memory usage if the messages are big.",
                                          this, SLOT( updateQueueSize() ));
  queue_size_property_->setMin( 1 );

  transport_property_->setStdString("raw");

  unreliable_property_ = new BoolProperty( "Unreliable", false,
                                           "Prefer UDP topic transport",
                                           this,
                                           SLOT( updateTopic() ));

}

ImageDisplayBase::~ImageDisplayBase()
{
  unsubscribe();
}

void ImageDisplayBase::onInitialize()
{
}

void ImageDisplayBase::setTopic( const QString &topic, const QString &datatype )
{
  if ( datatype.toStdString() == tinyros::sensor_msgs::Image::getTypeStatic() )
  {
    transport_property_->setStdString( "raw" );
    topic_property_->setString( topic );
  }
  else
  {
    int index = topic.lastIndexOf("/");
    if ( index == -1 )
    {
      tinyros_log_warn("ImageDisplayBase::setTopic() Invalid topic name: %s",
               topic.toStdString().c_str());
      return;
    }
    QString transport = topic.mid(index + 1);
    QString base_topic = topic.mid(0, index);

    transport_property_->setString( transport );
    topic_property_->setString( base_topic );
  }
}


void ImageDisplayBase::incomingMessage(const tinyros::sensor_msgs::Image::ConstPtr& msg)
{
  if (!msg || context_->getFrameManager()->getPause() )
  {
    return;
  }

  ++messages_received_;
  setStatus(StatusProperty::Ok, "Image", QString::number(messages_received_) + " images received");

  emitTimeSignal( msg->header.stamp );

  processMessage(msg);
}


void ImageDisplayBase::reset()
{
  Display::reset();
  if (tf_filter_)
    tf_filter_->clear();
  messages_received_ = 0;
}

void ImageDisplayBase::updateQueueSize()
{
  uint32_t size = queue_size_property_->getInt();
  if (tf_filter_)
    tf_filter_->setQueueSize(size);
}

void ImageDisplayBase::subscribe()
{
  if (!isEnabled())
  {
    return;
  }

  try
  {

    tf_filter_.reset();
    sub_->setEnabled(false);

    if (!topic_property_->getTopicStd().empty() && !transport_property_->getStdString().empty() )
    {
      if (targetFrame_.empty())
      {
        if (sub_->topic_.empty()) {
            sub_->topic_ = topic_property_->getTopicStd();
            tinyros::nh()->subscribe(*sub_);
        } else if (sub_->topic_ != topic_property_->getTopicStd()) {
          sub_->setEnabled(false);
          sub_ = new tinyros::Subscriber<tinyros::sensor_msgs::Image, ImageDisplayBase>(
            topic_property_->getTopicStd(), &ImageDisplayBase::incomingMessage, this);
          tinyros::nh()->subscribe(*sub_);
        }
        sub_->setEnabled(true);
      }
      else
      {
        tf_filter_.reset( new tinyros::tf::MessageFilter<tinyros::sensor_msgs::Image>((tinyros::tf::Transformer&)*(context_->getTFClient()), targetFrame_, (uint32_t)queue_size_property_->getInt()));
        tf_filter_->registerCallback(std::bind(&ImageDisplayBase::incomingMessage, this, std::placeholders::_1));
        tf_filter_->connectInput(topic_property_->getTopicStd());
      }
    }
    setStatus(StatusProperty::Ok, "Topic", "OK");
  }
  catch (std::exception& e)
  {
    setStatus(StatusProperty::Error, "Topic", QString("Error subscribing: ") + e.what());
  }

  messages_received_ = 0;
  setStatus(StatusProperty::Warn, "Image", "No Image received");
}

void ImageDisplayBase::unsubscribe()
{
  tf_filter_.reset();
  sub_->setEnabled(false);
}

void ImageDisplayBase::fixedFrameChanged()
{
  if (tf_filter_)
  {
    tf_filter_->setTargetFrame(fixed_frame_.toStdString());
    reset();
  }
}

void ImageDisplayBase::updateTopic()
{
  unsubscribe();
  reset();
  subscribe();
  context_->queueRender();
}

void ImageDisplayBase::fillTransportOptionList(EnumProperty* property)
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
    const std::string& topic = topic_property_->getStdString();

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

} // end namespace rviz
