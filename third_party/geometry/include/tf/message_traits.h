/*
 * Copyright (C) 2009, Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Willow Garage, Inc. nor the names of its
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

#ifndef TINYROS_TF_MESSAGE_TRAITS_H
#define TINYROS_TF_MESSAGE_TRAITS_H
#include <string>
#include <type_traits>
#include "tiny_ros/ros.h"
#include "tiny_ros/tf/message_forward.h"

namespace std
{
  template <bool B, class T = void>
  struct disable_if_c {
    typedef T type;
  };
  
  template <class T>
  struct disable_if_c<true, T> {};
  
  template <class Cond, class T = void>
  struct disable_if : public disable_if_c<Cond::value, T> {};

  template <bool, typename T=void>
  struct enable_if1 {
  };
   
  template <typename T>
  struct enable_if1<true, T> {
  using type = T;
};
}

namespace tinyros
{
namespace tf
{
namespace message_traits
{
/**
 * \brief Specialize to provide the md5sum for a message
 */
template<typename M>
struct MD5Sum
{
  static const char* value()
  {
    return M::getMD5Static().c_str();
  }

  static const char* value(const M& m)
  {
    return m.getMD5().c_str();
  }
};

/**
 * \brief Specialize to provide the datatype for a message
 */
template<typename M>
struct DataType
{
  static const char* value()
  {
    return M::getTypeStatic().c_str();
  }

  static const char* value(const M& m)
  {
    return m.getType().c_str();
  }
};

/**
 * \brief Specialize to provide the definition for a message
 */
template<typename M>
struct Definition
{
  static const char* value()
  {
    return M::getDefinitionStatic().c_str();
  }

  static const char* value(const M& m)
  {
    return m.getDefinition().c_str();
  }
};

/**
 * \brief Header trait.  In the default implementation pointer()
 * returns &m.header if HasHeader<M>::value is true, otherwise returns NULL
 */
template<typename M>
struct Header
{
  static tinyros::std_msgs::Header* pointer(M& m) { return (M::hasHeader() ? &m.header : 0); }
  static tinyros::std_msgs::Header const* pointer(const M& m) { return (M::hasHeader() ? &m.header : 0); }
};

/**
 * \brief FrameId trait.  In the default implementation pointer()
 * returns &m.header.frame_id if HasHeader<M>::value is true, otherwise returns NULL.  value()
 * does not exist, and causes a compile error
 */
template<typename M>
struct FrameId
{
  static std::string* pointer(M& m) { return (M::hasHeader() ? &m.header.frame_id : 0); }
  static std::string const* pointer(const M& m) { return (M::hasHeader() ? &m.header.frame_id : 0); }
  static std::string value(const M& m) { return (M::hasHeader() ? m.header.frame_id : ""); }
};

/**
 * \brief TimeStamp trait.  In the default implementation pointer()
 * returns &m.header.stamp if HasHeader<M>::value is true, otherwise returns NULL.  value()
 * does not exist, and causes a compile error
 */
template<typename M>
struct TimeStamp
{
  static tinyros::Time* pointer(typename std::remove_const<M>::type &m) { return (M::hasHeader() ? &m.header.stamp : 0); }
  static tinyros::Time const* pointer(const M& m) { return (M::hasHeader() ? &m.header.stamp : 0); }
  static tinyros::Time value(const M& m) { return (M::hasHeader() ? m.header.stamp : tinyros::Time()); }
};

template<typename M> struct HasHeader
{
  static bool value() { return M::hasHeader(); }
};

} 
} 
}

#endif
