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
   
#include "rviz/view_controller_factory.h"
#include "rviz/utils/utils.h"
#include "rviz/default_plugin/view_controllers/orbit_view_controller.h"
#include "rviz/default_plugin/view_controllers/xy_orbit_view_controller.h"
#include "rviz/default_plugin/view_controllers/third_person_follower_view_controller.h"
#include "rviz/default_plugin/view_controllers/fps_view_controller.h"
#include "rviz/default_plugin/view_controllers/fixed_orientation_ortho_view_controller.h"

namespace rviz
{

static ViewController* newOrbitViewController() { return new OrbitViewController(); }
static ViewController* newXYOrbitViewController() { return new XYOrbitViewController(); }
static ViewController* newThirdPersonFollowerViewController() { return new ThirdPersonFollowerViewController(); }
static ViewController* newFPSViewController() { return new FPSViewController(); }
static ViewController* newFixedOrientationOrthoViewController() { return new FixedOrientationOrthoViewController(); }


ViewControllerFactory::ViewControllerFactory()
  : PluginlibFactory<ViewController>( TINYROS_PACKAGE_NAME, "rviz::ViewController" )
{
  addBuiltInClass( "rviz", "Orbit", "Makes it easy to move around a given point in space, looking at it from any angle.", &newOrbitViewController );
  addBuiltInClass( "rviz", "XYOrbit", "Makes it easy to move around a given point on the XY plane, looking at it from any angle.", &newXYOrbitViewController );
  addBuiltInClass( "rviz", "ThirdPersonFollower", "Follow a target frame and turn the viewing direction with the yaw of the target frame.", &newThirdPersonFollowerViewController );
  addBuiltInClass( "rviz", "FPS", "Control the camera like in a First Person Shooter game: drag left to look left, etc.", &newFPSViewController );
  addBuiltInClass( "rviz", "TopDownOrtho", "Orthographic projection, seen from the top.", &newFixedOrientationOrthoViewController );
}

} // end namespace rviz
