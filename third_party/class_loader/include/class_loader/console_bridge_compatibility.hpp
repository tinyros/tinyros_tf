/*
 * Copyright (c) 2017, Open Source Robotics Foundation, Inc.
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
 *     * Neither the name of the Open Source Robotics Foundation, Inc. nor the names of its
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

#ifndef CLASS_LOADER__CONSOLE_BRIDGE_COMPATIBILITY_HPP_
#define CLASS_LOADER__CONSOLE_BRIDGE_COMPATIBILITY_HPP_

#include <tiny_ros/ros.h>

#ifndef CONSOLE_BRIDGE_logError
# define CONSOLE_BRIDGE_logError(fmt, ...)  \
  tinyros::mtrace(tinyros::tinyros_msgs::Log::ROSERROR, "%s(%d)" fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#ifndef CONSOLE_BRIDGE_logWarn
# define CONSOLE_BRIDGE_logWarn(fmt, ...)   \
  tinyros::mtrace(tinyros::tinyros_msgs::Log::ROSWARN, "%s(%d)" fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#ifndef CONSOLE_BRIDGE_logInform
# define CONSOLE_BRIDGE_logInform(fmt, ...) \
  tinyros::mtrace(tinyros::tinyros_msgs::Log::ROSINFO, "%s(%d)" fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#ifndef CONSOLE_BRIDGE_logDebug
# define CONSOLE_BRIDGE_logDebug(fmt, ...)  \
  tinyros::mtrace(tinyros::tinyros_msgs::Log::ROSDEBUG, "%s(%d)" fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#endif

#endif  // CLASS_LOADER__CONSOLE_BRIDGE_COMPATIBILITY_HPP_
