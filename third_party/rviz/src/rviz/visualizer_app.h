/*
 * Copyright (c) 2011, Willow Garage, Inc.
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
#ifndef RVIZ_VISUALIZER_APP_H
#define RVIZ_VISUALIZER_APP_H

#include <QApplication>
#include <QObject>

#ifndef Q_MOC_RUN  // See: https://bugreports.qt-project.org/browse/QTBUG-22829
# include <tiny_ros/ros.h>
# include <tiny_ros/std_srvs/Empty.h>
#endif

class QTimer;

namespace rviz
{

class VisualizationFrame;

class VisualizerApp: public QObject
{
Q_OBJECT
public:
  VisualizerApp();
  virtual ~VisualizerApp();

  void setApp( QApplication * app );

  /** Start everything.  Pass in command line arguments.
   * @return false on failure, true on success. */
  bool init( int argc, char** argv );

private Q_SLOTS:
  /** If ros::ok() is false, close all windows. */
  void checkContinue();

private:
  void startContinueChecker();
  void reloadShaders(const tinyros::std_srvs::Empty::Request&, tinyros::std_srvs::Empty::Response&);

  QApplication* app_;
  QTimer* continue_timer_;
  VisualizationFrame* frame_;
  tinyros::ServiceServer<tinyros::std_srvs::Empty::Request, 
      tinyros::std_srvs::Empty::Response, VisualizerApp> reload_shaders_service_;
};

} // end namespace rviz

#endif // RVIZ_VISUALIZER_APP_H
