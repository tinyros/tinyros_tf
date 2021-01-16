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

#include "ros_image_texture.h"

#include <tiny_ros/tf/tf.h>

#include <OGRE/OgreTextureManager.h>

namespace rviz
{

ROSImageTexture::ROSImageTexture()
: new_image_(false)
, width_(0)
, height_(0)
, tf_client_(0)
, sub_(new tinyros::Subscriber<tinyros::sensor_msgs::Image, ROSImageTexture>("", &ROSImageTexture::callback, this))
{
  const static uint32_t texture_data[4] = { 0x00ffff80, 0x00ffff80, 0x00ffff80, 0x00ffff80 };
  Ogre::DataStreamPtr pixel_stream;
  pixel_stream.bind(new Ogre::MemoryDataStream( (void*)&texture_data[0], 16 ));

  static uint32_t count = 0;
  std::stringstream ss;
  ss << "ROSImageTexture" << count++;
  texture_ = Ogre::TextureManager::getSingleton().loadRawData(ss.str(), Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, pixel_stream, 2, 2, Ogre::PF_R8G8B8A8, Ogre::TEX_TYPE_2D, 0);
}

ROSImageTexture::~ROSImageTexture()
{
}

void ROSImageTexture::clear()
{
  const static uint32_t texture_data[4] = { 0x00ffff80, 0x00ffff80, 0x00ffff80, 0x00ffff80 };
  Ogre::DataStreamPtr pixel_stream;
  pixel_stream.bind(new Ogre::MemoryDataStream( (void*)&texture_data[0], 16 ));

  texture_->unload();
  texture_->loadRawData(pixel_stream, 2, 2, Ogre::PF_R8G8B8A8);

  new_image_ = false;
  current_image_.reset();

  if (tf_filter_)
  {
    tf_filter_->clear();
  }
}

void ROSImageTexture::setFrame(const std::string& frame, tinyros::tf::TransformListener* tf_client)
{
  tf_client_ = tf_client;
  frame_ = frame;
  setTopic(topic_);
}

void ROSImageTexture::setTopic(const std::string& topic)
{
  topic_ = topic;
  tf_filter_.reset();

  if (!topic.empty())
  {
    if (frame_.empty())
    {
      if (sub_->topic_.empty()) {
        sub_->topic_ = topic_;
        tinyros::nh()->subscribe(*sub_);
      } else if (sub_->topic_ != topic_) {
        sub_->setEnabled(false);
        sub_ = new tinyros::Subscriber<tinyros::sensor_msgs::Image, ROSImageTexture>(topic_, &ROSImageTexture::callback, this);
        tinyros::nh()->subscribe(*sub_);
      }
      sub_->setEnabled(true);
    }
    else
    {
      TINYROS_ASSERT(tf_client_);
      tf_filter_.reset(new tinyros::tf::MessageFilter<tinyros::sensor_msgs::Image>((tinyros::tf::Transformer&)*tf_client_, frame_, 2));
      tf_filter_->registerCallback(std::bind(&ROSImageTexture::callback, this, std::placeholders::_1));
      tf_filter_->connectInput(topic);
      tf_filter_->connectEnable(true);
    }
  }
}

const tinyros::sensor_msgs::ImageConstPtr& ROSImageTexture::getImage()
{
  std::scoped_lock lock(mutex_);

  return current_image_;
}

bool ROSImageTexture::update()
{
  tinyros::sensor_msgs::ImageConstPtr image;
  bool new_image = false;
  {
    std::scoped_lock lock(mutex_);

    image = current_image_;
    new_image = new_image_;
  }

  if (!image || !new_image)
  {
    return false;
  }

  Ogre::PixelFormat format = Ogre::PF_R8G8B8;

  if (image->encoding == tinyros::sensor_msgs::image_encodings::RGB8)
  {
    format = Ogre::PF_R8G8B8;
  }
  else if (image->encoding == tinyros::sensor_msgs::image_encodings::RGBA8)
  {
    format = Ogre::PF_R8G8B8A8;
  }
  else if (image->encoding == tinyros::sensor_msgs::image_encodings::TYPE_8UC4 ||
           image->encoding == tinyros::sensor_msgs::image_encodings::BGRA8)
  {
    format = Ogre::PF_B8G8R8A8;
  }
  else if (image->encoding == tinyros::sensor_msgs::image_encodings::TYPE_8UC3 ||
           image->encoding == tinyros::sensor_msgs::image_encodings::BGR8)
  {
    format = Ogre::PF_B8G8R8;
  }
  else if (image->encoding == tinyros::sensor_msgs::image_encodings::TYPE_8UC1 ||
           image->encoding == tinyros::sensor_msgs::image_encodings::MONO8)
  {
    format = Ogre::PF_L8;
  }
  else
  {
    tinyros_log_error("Unsupported image encoding [%s]", image->encoding.c_str());
    return false;
  }

  width_ = image->width;
  height_ = image->height;

  uint32_t size = image->height * image->step;
  Ogre::DataStreamPtr pixel_stream;
  pixel_stream.bind(new Ogre::MemoryDataStream((void*)(&image->data[0]), size));
  texture_->unload();
  texture_->loadRawData(pixel_stream, width_, height_, format);
  new_image_ = false;

  return true;
}

void ROSImageTexture::callback(const tinyros::sensor_msgs::ImageConstPtr& msg)
{
  std::scoped_lock lock(mutex_);
  current_image_ = msg;
  new_image_ = true;
}

}
