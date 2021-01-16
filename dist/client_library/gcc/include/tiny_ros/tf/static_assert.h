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
 *     * Neither the name of Willow Garage, Inc. nor the names of its
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

// Author: Josh Faust

#ifndef TINYROS_TF_STATIC_ASSERT_H
#define TINYROS_TF_STATIC_ASSERT_H

// boost's static assert provides better errors messages in the failure case when using
// in templated situations
#include "tiny_ros/ros.h"
#include <assert.h>

#ifdef WIN32
# if defined (__MINGW32__)
#  define TINYROS_ISSUE_BREAK() DebugBreak();
# else // MSVC
#  define TINYROS_ISSUE_BREAK() __debugbreak();
# endif
#elif defined(__powerpc64__)
# define TINYROS_ISSUE_BREAK() asm volatile ("tw 31,1,1");
#elif defined(__i386__) || defined(__ia64__) || defined(__x86_64__)
# define TINYROS_ISSUE_BREAK() asm("int $3");
#else
# include <stdlib.h>
# define TINYROS_ISSUE_BREAK() abort();
#endif

#define TINYROS_BREAK() \
  do { \
    tinyros_log_error("BREAKPOINT HIT\n\tfile = %s\n\tline=%d\n", __FILE__, __LINE__); \
    TINYROS_ISSUE_BREAK() \
  } while (0)

#define TINYROS_ASSERT(cond) \
  do { \
    if (!(cond)) { \
      tinyros_log_error("ASSERTION FAILED\n\tfile = %s\n\tline = %d\n\tcond = %s\n", __FILE__, __LINE__, #cond); \
      TINYROS_ISSUE_BREAK() \
    } \
  } while (0)

#define TINYROS_ASSERT_MSG(cond, ...) \
  do { \
    if (!(cond)) { \
      tinyros_log_error("ASSERTION FAILED\n\tfile = %s\n\tline = %d\n\tcond = %s\n\tmessage = ", __FILE__, __LINE__, #cond); \
      tinyros_log_error(__VA_ARGS__); \
      tinyros_log_error("\n"); \
      TINYROS_ISSUE_BREAK(); \
    } \
  } while (0)

#define TINYROS_ASSERT_CMD(cond, cmd) \
  do { \
    if (!cond) { \
      cmd; \
    } \
  } while (0)

/**
 * \def ROS_COMPILE_ASSERT(cond)
 * \brief Compile-time assert.
 *
 * Only works with compile time statements, ie:
 @verbatim
   struct A
   {
     uint32_t a;
   };
   ROS_COMPILE_ASSERT(sizeof(A) == 4);
 @endverbatim
 */
#define TINYROS_COMPILE_ASSERT(cond) static_assert(cond, "TINYROS_COMPILE_ASSERT")

/**
 * \def ROS_STATIC_ASSERT(cond)
 * \brief Compile-time assert.
 *
 * Only works with compile time statements, ie:
 @verbatim
   struct A
   {
     uint32_t a;
   };
   ROS_STATIC_ASSERT(sizeof(A) == 4);
 @endverbatim
 */
#define TINYROS_STATIC_ASSERT(cond) static_assert(cond, "TINYROS_STATIC_ASSERT")

#endif // TINYROS_TF_STATIC_ASSERT_H