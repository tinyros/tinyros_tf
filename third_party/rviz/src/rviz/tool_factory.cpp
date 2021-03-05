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
   
#include "rviz/utils/utils.h"
#include "rviz/tool_factory.h"
#include "rviz/default_plugin/tools/point_tool.h"
#include "rviz/default_plugin/tools/focus_tool.h"
#include "rviz/default_plugin/tools/measure_tool.h"
#include "rviz/default_plugin/tools/move_tool.h"
#include "rviz/default_plugin/tools/selection_tool.h"
#include "rviz/default_plugin/tools/goal_tool.h"
#include "rviz/default_plugin/tools/initial_pose_tool.h"
#include "rviz/default_plugin/tools/interaction_tool.h"

namespace rviz
{

static Tool* newPointTool() { return new PointTool(); }
static Tool* newFocusTool() { return new FocusTool(); }
static Tool* newMeasureTool() { return new MeasureTool(); }
static Tool* newMoveTool() { return new MoveTool(); }
static Tool* newSelectionTool() { return new SelectionTool(); }
static Tool* newGoalTool() { return new GoalTool(); }
static Tool* newInitialPoseTool() { return new InitialPoseTool(); }
static Tool* newInteractionTool() { return new InteractionTool(); }

ToolFactory::ToolFactory()
  : PluginlibFactory<Tool>( TINYROS_PACKAGE_NAME, "rviz::Tool" )
{
  addBuiltInClass( "rviz", "PublishPoint", "Allows you to click on a point and publish it as a PointStamped message.", &newPointTool );
  addBuiltInClass( "rviz", "FocusCamera", "Click onto any object to focus the camera there.", &newFocusTool );
  addBuiltInClass( "rviz", "Measure", "Click onto two locations to measure their distance.", &newMeasureTool );
  addBuiltInClass( "rviz", "MoveCamera", "Drag the mouse with left, middle, or right buttons to change your viewpoint.", &newMoveTool );
  addBuiltInClass( "rviz", "Select", "Drag with the left button to select objects in the 3D scene. Hold the Alt key to change viewpoint as in the Move tool.", &newSelectionTool );
  addBuiltInClass( "rviz", "SetGoal", "Publish a goal pose for the robot.  After one use, reverts to default tool.", &newGoalTool );
  addBuiltInClass( "rviz", "SetInitialPose", "Publish an initial pose for the robot.  After one use, reverts to default tool.", &newInitialPoseTool );
  addBuiltInClass( "rviz", "Interact", "Interact with interactive markers.  Mouse actions not on interactive markers fall back to moving the camera.", &newInteractionTool );
}

} // end namespace rviz
