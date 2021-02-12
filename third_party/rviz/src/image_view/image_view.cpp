/*
 * Copyright (c) 2008, Willow Garage, Inc.
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


#include <QtGlobal>
#include <QTimer>

#include "rviz/ogre_helpers/qt_ogre_render_window.h"
#include "rviz/ogre_helpers/initialization.h"
#include "rviz/image/ros_image_texture.h"

#include "tiny_ros/ros.h"
#include "tiny_ros/package.h"

#include <OgreRoot.h>
#include <OgreRenderWindow.h>
#include <OgreSceneManager.h>
#include <OgreViewport.h>
#include <OgreRectangle2D.h>
#include <OgreMaterial.h>
#include <OgreMaterialManager.h>
#include <OgreTextureUnitState.h>
#include <OgreSharedPtr.h>
#include <OgreTechnique.h>
#include <OgreSceneNode.h>

#include "image_view.h"

#include <exception>

using namespace rviz;

ImageView::ImageView( QWidget* parent )
  : QtOgreRenderWindow( parent )
  , texture_sub_("/image", &ImageView::textureCallback, this)
{
  setAutoRender(false);
  scene_manager_ = ogre_root_->createSceneManager( Ogre::ST_GENERIC, "TestSceneManager" );
}

ImageView::~ImageView()
{
  delete texture_;
}

void ImageView::showEvent( QShowEvent* event )
{
  QtOgreRenderWindow::showEvent( event );

  V_string paths;
  paths.push_back(tinyros::package::getPath() + "tinyros_rviz/ogre_media/textures");
  initializeResources(paths);

  setCamera( scene_manager_->createCamera( "Camera" ));

  std::string resolved_image = "/image";

  std::stringstream title;
  title << "rviz Image Viewer [" << resolved_image << "]";
  setWindowTitle( QString::fromStdString( title.str() ));

  texture_ = new ROSImageTexture();

  try
  {
    texture_->clear();
    tinyros::nh()->subscribe(texture_sub_);
  }
  catch (std::exception& e)
  {
    tinyros_log_error("%s", (std::string("Error subscribing: ") + e.what()).c_str());
  }

  Ogre::MaterialPtr material =
    Ogre::MaterialManager::getSingleton().create( "Material",
                                                  Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME );
  material->setCullingMode(Ogre::CULL_NONE);
  material->getTechnique(0)->getPass(0)->setDepthWriteEnabled(true);
  material->getTechnique(0)->setLightingEnabled(false);
  Ogre::TextureUnitState* tu = material->getTechnique(0)->getPass(0)->createTextureUnitState();
  tu->setTextureName(texture_->getTexture()->getName());
  tu->setTextureFiltering( Ogre::TFO_NONE );

  Ogre::Rectangle2D* rect = new Ogre::Rectangle2D(true);
  rect->setCorners(-1.0f, 1.0f, 1.0f, -1.0f);
  rect->setMaterial(material->getName());
  rect->setRenderQueueGroup(Ogre::RENDER_QUEUE_OVERLAY - 1);
  Ogre::AxisAlignedBox aabb;
  aabb.setInfinite();
  rect->setBoundingBox(aabb);

  Ogre::SceneNode* node = scene_manager_->getRootSceneNode()->createChildSceneNode();
  node->attachObject(rect);
  node->setVisible(true);

  QTimer* timer = new QTimer( this );
  connect( timer, SIGNAL( timeout() ), this, SLOT( onTimer() ));
  timer->start( 33 );
}

void ImageView::onTimer()
{
  static bool first = true;
  try
  {
    if( texture_->update() )
    {
      if( first )
      {
        first = false;

        resize( texture_->getWidth(), texture_->getHeight() );
      }
    }

    ogre_root_->renderOneFrame();
  }
  catch( UnsupportedImageEncoding& e )
  {
    tinyros_log_error("%s", e.what());
  }

  if( !tinyros::nh()->ok() )
  {
    close();
  }
}

void ImageView::textureCallback(const sensor_msgs::Image::ConstPtr& msg)
{
  if (texture_) {
    texture_->addMessage(msg);
  }
}
