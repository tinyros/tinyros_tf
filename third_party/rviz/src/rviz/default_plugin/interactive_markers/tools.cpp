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

#include "tools.h"

#include <tiny_ros/tf/Quaternion.h>
#include <tiny_ros/tf/Matrix3x3.h>

#include <math.h>
#include <assert.h>

#include <set>
#include <sstream>

namespace rviz
{

void autoComplete( tinyros::visualization_msgs::InteractiveMarker &msg, bool enable_autocomplete_transparency )
{
  // this is a 'delete' message. no need for action.
  if ( msg.controls.empty() )
  {
    return;
  }

  // default size
  if ( msg.scale == 0 )
  {
    msg.scale = 1;
  }

  // correct empty orientation, normalize
  if ( msg.pose.orientation.w == 0 && msg.pose.orientation.x == 0 &&
      msg.pose.orientation.y == 0 && msg.pose.orientation.z == 0 )
  {
    msg.pose.orientation.w = 1;
  }

  //normalize quaternion
  tinyros::tf::Quaternion int_marker_orientation( msg.pose.orientation.x, msg.pose.orientation.y,
      msg.pose.orientation.z, msg.pose.orientation.w );
  int_marker_orientation.normalize();
  msg.pose.orientation.x = int_marker_orientation.x();
  msg.pose.orientation.y = int_marker_orientation.y();
  msg.pose.orientation.z = int_marker_orientation.z();
  msg.pose.orientation.w = int_marker_orientation.w();

  // complete the controls
  for ( unsigned c=0; c<msg.controls.size(); c++ )
  {
    autoComplete( msg, msg.controls[c], enable_autocomplete_transparency);
  }

  uniqueifyControlNames( msg );
}

void uniqueifyControlNames( tinyros::visualization_msgs::InteractiveMarker& msg )
{
  int uniqueification_number = 0;
  std::set<std::string> names;
  for( unsigned c = 0; c < msg.controls.size(); c++ )
  {
    std::string name = msg.controls[c].name;
    while( names.find( name ) != names.end() )
    {
      std::stringstream ss;
      ss << name << "_u" << uniqueification_number++;
      name = ss.str();
    }
    msg.controls[c].name = name;
    names.insert( name );
  }
}

void autoComplete( const tinyros::visualization_msgs::InteractiveMarker &msg,
    tinyros::visualization_msgs::InteractiveMarkerControl &control, bool enable_autocomplete_transparency)
{
  // correct empty orientation
  if ( control.orientation.w == 0 && control.orientation.x == 0 &&
       control.orientation.y == 0 && control.orientation.z == 0 )
  {
    control.orientation.w = 1;
  }

  // add default control handles if there are none
  if ( control.markers.empty() )
  {
    switch ( control.interaction_mode )
    {
      case tinyros::visualization_msgs::InteractiveMarkerControl::NONE:
        break;

      case tinyros::visualization_msgs::InteractiveMarkerControl::MOVE_AXIS:
        control.markers.reserve(2);
        makeArrow( msg, control, 1.0 );
        makeArrow( msg, control, -1.0 );
        break;

      case tinyros::visualization_msgs::InteractiveMarkerControl::MOVE_PLANE:
      case tinyros::visualization_msgs::InteractiveMarkerControl::ROTATE_AXIS:
      case tinyros::visualization_msgs::InteractiveMarkerControl::MOVE_ROTATE:
        makeDisc( msg, control );
        break;

      case tinyros::visualization_msgs::InteractiveMarkerControl::BUTTON:
        break;

      case tinyros::visualization_msgs::InteractiveMarkerControl::MENU:
        makeViewFacingButton( msg, control, control.description );
        break;

      default:
        break;
    }
  }

  // get interactive marker pose for later
  tinyros::tf::Quaternion int_marker_orientation( msg.pose.orientation.x, msg.pose.orientation.y,
      msg.pose.orientation.z, msg.pose.orientation.w );
  tinyros::tf::Vector3 int_marker_position( msg.pose.position.x, msg.pose.position.y, msg.pose.position.z );

  // fill in missing pose information into the markers
  for ( unsigned m=0; m<control.markers.size(); m++ )
  {
    tinyros::visualization_msgs::Marker &marker = control.markers[m];

    if ( marker.scale.x == 0 )
    {
      marker.scale.x = 1;
    }
    if ( marker.scale.y == 0 )
    {
      marker.scale.y = 1;
    }
    if ( marker.scale.z == 0 )
    {
      marker.scale.z = 1;
    }

    marker.ns = msg.name;

    // correct empty orientation
    if ( marker.pose.orientation.w == 0 && marker.pose.orientation.x == 0 &&
        marker.pose.orientation.y == 0 && marker.pose.orientation.z == 0 )
    {
      marker.pose.orientation.w = 1;
    }

    //normalize orientation
    tinyros::tf::Quaternion marker_orientation( marker.pose.orientation.x, marker.pose.orientation.y,
        marker.pose.orientation.z, marker.pose.orientation.w );

    marker_orientation.normalize();

    marker.pose.orientation.x = marker_orientation.x();
    marker.pose.orientation.y = marker_orientation.y();
    marker.pose.orientation.z = marker_orientation.z();
    marker.pose.orientation.w = marker_orientation.w();

    static volatile unsigned id = 0;
    marker.id = id++;
    marker.ns = msg.name;

    // If transparency is disabled, set alpha to 1.0 for all semi-transparent markers
    if ( !enable_autocomplete_transparency && marker.color.a > 0.0 )
    {
      marker.color.a = 1.0;
    }
  }
}

void makeArrow( const tinyros::visualization_msgs::InteractiveMarker &msg,
    tinyros::visualization_msgs::InteractiveMarkerControl &control, float pos )
{
  tinyros::visualization_msgs::Marker marker;

  // rely on the auto-completion for the correct orientation
  marker.pose.orientation = control.orientation;

  marker.type = tinyros::visualization_msgs::Marker::ARROW;
  marker.scale.x = msg.scale * 0.15; // aleeper: changed from 0.3 due to Rviz fix
  marker.scale.y = msg.scale * 0.25; // aleeper: changed from 0.5 due to Rviz fix
  marker.scale.z = msg.scale * 0.2;

  assignDefaultColor(marker, control.orientation);

  float dist = fabs(pos);
  float dir = pos > 0 ? 1 : -1;

  float inner = 0.5 * dist;
  float outer = inner + 0.4;

  marker.points.resize(2);
  marker.points[0].x = dir * msg.scale * inner;
  marker.points[1].x = dir * msg.scale * outer;

  control.markers.push_back( marker );
}

void makeDisc( const tinyros::visualization_msgs::InteractiveMarker &msg,
    tinyros::visualization_msgs::InteractiveMarkerControl &control, float width )
{
  tinyros::visualization_msgs::Marker marker;

  // rely on the auto-completion for the correct orientation
  marker.pose.orientation = control.orientation;

  marker.type = tinyros::visualization_msgs::Marker::TRIANGLE_LIST;
  marker.scale.x = msg.scale;
  marker.scale.y = msg.scale;
  marker.scale.z = msg.scale;

  assignDefaultColor(marker, control.orientation);

  // compute points on a circle in the y-z plane
  int steps = 36;
  std::vector<tinyros::geometry_msgs::Point> circle1, circle2;
  circle1.reserve(steps);
  circle2.reserve(steps);

  tinyros::geometry_msgs::Point v1,v2;

  for ( int i=0; i<steps; i++ )
  {
    float a = float(i)/float(steps) * M_PI * 2.0;

    v1.y = 0.5 * cos(a);
    v1.z = 0.5 * sin(a);

    v2.y = (1+width) * v1.y;
    v2.z = (1+width) * v1.z;

    circle1.push_back( v1 );
    circle2.push_back( v2 );
  }

  marker.points.resize(6*steps);

  tinyros::std_msgs::ColorRGBA color;
  color.r=color.g=color.b=color.a=1;

  switch ( control.interaction_mode )
  {
    case tinyros::visualization_msgs::InteractiveMarkerControl::ROTATE_AXIS:
    {
      marker.colors.resize(2*steps);
      tinyros::std_msgs::ColorRGBA base_color = marker.color;
      for ( int i=0; i<steps; i++ )
      {
        int i1 = i;
        int i2 = (i+1) % steps;
        int i3 = (i+2) % steps;

        int p = i*6;
        int c = i*2;

        marker.points[p+0] = circle1[i1];
        marker.points[p+1] = circle2[i2];
        marker.points[p+2] = circle1[i2];

        marker.points[p+3] = circle1[i2];
        marker.points[p+4] = circle2[i2];
        marker.points[p+5] = circle2[i3];

        float t = 0.6 + 0.4 * (i%2);
        color.r = base_color.r * t;
        color.g = base_color.g * t;
        color.b = base_color.b * t;

        marker.colors[c] = color;
        marker.colors[c+1] = color;
      }
      break;
    }

    case tinyros::visualization_msgs::InteractiveMarkerControl::MOVE_ROTATE:
    {
      marker.colors.resize(2*steps);
      tinyros::std_msgs::ColorRGBA base_color = marker.color;
      for ( int i=0; i<steps-1; i+=2 )
      {
        int i1 = i;
        int i2 = (i+1) % steps;
        int i3 = (i+2) % steps;

        int p = i * 6;
        int c = i * 2;

        marker.points[p+0] = circle1[i1];
        marker.points[p+1] = circle2[i2];
        marker.points[p+2] = circle1[i2];

        marker.points[p+3] = circle1[i2];
        marker.points[p+4] = circle2[i2];
        marker.points[p+5] = circle1[i3];

        color.r = base_color.r * 0.6;
        color.g = base_color.g * 0.6;
        color.b = base_color.b * 0.6;

        marker.colors[c] = color;
        marker.colors[c+1] = color;

        p += 6;
        c += 2;

        marker.points[p+0] = circle2[i1];
        marker.points[p+1] = circle2[i2];
        marker.points[p+2] = circle1[i1];

        marker.points[p+3] = circle2[i2];
        marker.points[p+4] = circle2[i3];
        marker.points[p+5] = circle1[i3];

        marker.colors[c] = base_color;
        marker.colors[c+1] = base_color;
      }
      break;
    }

    default:
      for ( int i=0; i<steps; i++ )
      {
        int i1 = i;
        int i2 = (i+1) % steps;

        int p = i*6;

        marker.points[p+0] = circle1[i1];
        marker.points[p+1] = circle2[i1];
        marker.points[p+2] = circle1[i2];

        marker.points[p+3] = circle2[i1];
        marker.points[p+4] = circle2[i2];
        marker.points[p+5] = circle1[i2];
      }
      break;
  }

  control.markers.push_back(marker);
}

void makeViewFacingButton( const tinyros::visualization_msgs::InteractiveMarker &msg,
    tinyros::visualization_msgs::InteractiveMarkerControl &control, std::string text )
{
  control.orientation_mode = tinyros::visualization_msgs::InteractiveMarkerControl::VIEW_FACING;
  control.independent_marker_orientation = false;

  tinyros::visualization_msgs::Marker marker;

  float base_scale = 0.25 * msg.scale;
  float base_z = 1.2 * msg.scale;

  marker.type = tinyros::visualization_msgs::Marker::TEXT_VIEW_FACING;
  marker.scale.x = base_scale;
  marker.scale.y = base_scale;
  marker.scale.z = base_scale;
  marker.color.r = 1.0;
  marker.color.g = 1.0;
  marker.color.b = 1.0;
  marker.color.a = 1.0;
  marker.pose.position.x = base_scale * -0.1;
  marker.pose.position.z = base_z + base_scale * -0.1;
  marker.text = text;

  control.markers.push_back( marker );
}


void assignDefaultColor(tinyros::visualization_msgs::Marker &marker, const tinyros::geometry_msgs::Quaternion &quat )
{
  tinyros::geometry_msgs::Vector3 v;

  tinyros::tf::Quaternion bt_quat( quat.x, quat.y, quat.z, quat.w );
  tinyros::tf::Vector3 bt_x_axis = tinyros::tf::Matrix3x3(bt_quat) * tinyros::tf::Vector3(1,0,0);

  float x,y,z;
  x = fabs(bt_x_axis.x());
  y = fabs(bt_x_axis.y());
  z = fabs(bt_x_axis.z());

  float max_xy = x>y ? x : y;
  float max_yz = y>z ? y : z;
  float max_xyz = max_xy > max_yz ? max_xy : max_yz;

  marker.color.r = x / max_xyz;
  marker.color.g = y / max_xyz;
  marker.color.b = z / max_xyz;
  marker.color.a = 0.5;
}


tinyros::visualization_msgs::InteractiveMarkerControl makeTitle( const tinyros::visualization_msgs::InteractiveMarker &msg )
{
  tinyros::visualization_msgs::Marker marker;

  marker.type = tinyros::visualization_msgs::Marker::TEXT_VIEW_FACING;
  marker.scale.x = msg.scale * 0.15;
  marker.scale.y = msg.scale * 0.15;
  marker.scale.z = msg.scale * 0.15;
  marker.color.r = 1.0;
  marker.color.g = 1.0;
  marker.color.b = 1.0;
  marker.color.a = 1.0;
  marker.pose.position.z = msg.scale * 1.4;
  marker.text = msg.description;

  tinyros::visualization_msgs::InteractiveMarkerControl control;
  control.interaction_mode = tinyros::visualization_msgs::InteractiveMarkerControl::NONE;
  control.orientation_mode = tinyros::visualization_msgs::InteractiveMarkerControl::VIEW_FACING;
  control.always_visible = true;
  control.markers.push_back( marker );

  autoComplete( msg, control );

  return control;
}

}
