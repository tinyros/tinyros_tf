/*
 * Copyright (C) 2008, Morgan Quigley and Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
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

#ifndef TINYROS_TF_FORWARDS_H
#define TINYROS_TF_FORWARDS_H
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <thread>
#include <functional>
#include <memory>
#include <mutex>
#include <type_traits>
#include "tiny_ros/ros.h"
#include "tiny_ros/ros/time.h"
#include "tiny_ros/ros/duration.h"

namespace tinyros
{
namespace tf
{
typedef std::shared_ptr<void> VoidPtr;
typedef std::weak_ptr<void> VoidWPtr;
typedef std::shared_ptr<void const> VoidConstPtr;
typedef std::weak_ptr<void const> VoidConstWPtr;

class Header;

typedef std::vector<std::pair<std::string, std::string> > VP_string;
typedef std::vector<std::string> V_string;
typedef std::set<std::string> S_string;
typedef std::map<std::string, std::string> M_string;
typedef std::pair<std::string, std::string> StringPair;

class CallbackQueue;
class CallbackQueueInterface;
class CallbackInterface;
typedef std::shared_ptr<CallbackInterface> CallbackInterfacePtr;

/**
 * \brief Structure passed as a parameter to the callback invoked by a ros::Timer
 */
struct TimerEvent
{
  tinyros::Time last_expected;                     ///< In a perfect world, this is when the last callback should have happened
  tinyros::Time last_real;                         ///< When the last callback actually happened

  tinyros::Time current_expected;                  ///< In a perfect world, this is when the current callback should be happening
  tinyros::Time current_real;                      ///< This is when the current callback was actually called (Time::now() as of the beginning of the callback)

  struct
  {
    tinyros::Duration last_duration;           ///< How long the last callback ran for
  } profile;
};
typedef std::function<void(const TimerEvent&)> TimerCallback;

}
}

#endif
