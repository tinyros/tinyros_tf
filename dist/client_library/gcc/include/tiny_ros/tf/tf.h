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

/** \author Tully Foote */

#ifndef TINYROS_TF_H
#define TINYROS_TF_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <algorithm>
#include "tiny_ros/ros.h"
#include "tiny_ros/tf/exceptions.h"
#include "tiny_ros/tf/time_cache.h"
#include "tiny_ros/tf/signals.h"
#include "tiny_ros/geometry_msgs/TwistStamped.h"

namespace tinyros
{
namespace tf
{
struct TimeAndFrameIDFrameComparator
{
  TimeAndFrameIDFrameComparator(CompactFrameID id)
  : id(id)
  {}

  bool operator()(const P_TimeAndFrameID& rhs) const
  {
    return rhs.second == id;
  }

  CompactFrameID id;
};

enum WalkEnding
{
  Identity,
  TargetParentOfSource,
  SourceParentOfTarget,
  FullPath,
};

struct CanTransformAccum
{
  CompactFrameID gather(TimeCache* cache, tinyros::Time time, std::string* error_string)
  {
    return cache->getParent(time, error_string);
  }

  void accum(bool source)
  {
  }

  void finalize(WalkEnding end, tinyros::Time _time)
  {
  }

  TransformStorage st;
};

struct TransformAccum
{
  TransformAccum()
  : source_to_top_quat(0.0, 0.0, 0.0, 1.0)
  , source_to_top_vec(0.0, 0.0, 0.0)
  , target_to_top_quat(0.0, 0.0, 0.0, 1.0)
  , target_to_top_vec(0.0, 0.0, 0.0)
  , result_quat(0.0, 0.0, 0.0, 1.0)
  , result_vec(0.0, 0.0, 0.0)
  {
  }

  CompactFrameID gather(TimeCache* cache, tinyros::Time time, std::string* error_string)
  {
    if (!cache->getData(time, st, error_string))
    {
      return 0;
    }

    return st.frame_id_;
  }

  void accum(bool source)
  {
    if (source)
    {
      source_to_top_vec = quatRotate(st.rotation_, source_to_top_vec) + st.translation_;
      source_to_top_quat = st.rotation_ * source_to_top_quat;
    }
    else
    {
      target_to_top_vec = quatRotate(st.rotation_, target_to_top_vec) + st.translation_;
      target_to_top_quat = st.rotation_ * target_to_top_quat;
    }
  }

  void finalize(WalkEnding end, tinyros::Time _time)
  {
    switch (end)
    {
    case Identity:
      break;
    case TargetParentOfSource:
      result_vec = source_to_top_vec;
      result_quat = source_to_top_quat;
      break;
    case SourceParentOfTarget:
      {
        tf::Quaternion inv_target_quat = target_to_top_quat.inverse();
        tf::Vector3 inv_target_vec = quatRotate(inv_target_quat, -target_to_top_vec);
        result_vec = inv_target_vec;
        result_quat = inv_target_quat;
        break;
      }
    case FullPath:
      {
        tf::Quaternion inv_target_quat = target_to_top_quat.inverse();
        tf::Vector3 inv_target_vec = quatRotate(inv_target_quat, -target_to_top_vec);

     	result_vec = quatRotate(inv_target_quat, source_to_top_vec) + inv_target_vec;
        result_quat = inv_target_quat * source_to_top_quat;
      }
      break;
    };

    time = _time;
  }

  TransformStorage st;
  tinyros::Time time;
  tinyros::tf::Quaternion source_to_top_quat;
  tinyros::tf::Vector3 source_to_top_vec;
  tinyros::tf::Quaternion target_to_top_quat;
  tinyros::tf::Vector3 target_to_top_vec;

  tinyros::tf::Quaternion result_quat;
  tinyros::tf::Vector3 result_vec;
};


/** \brief resolve tf names */
std::string resolve(const std::string& prefix, const std::string& frame_name)
{
  //  printf ("resolveping prefix:%s with frame_name:%s\n", prefix.c_str(), frame_name.c_str());
  if (frame_name.size() > 0)
    if (frame_name[0] == '/')
    {
      return frame_name;
    }
  if (prefix.size() > 0)
  {
    if (prefix[0] == '/')
    {
      std::string composite = prefix;
      composite.append("/");
      composite.append(frame_name);
      return composite;
    }
    else
    {
      std::string composite;
      composite = "/";
      composite.append(prefix);
      composite.append("/");
      composite.append(frame_name);
      return composite;
    }

  }
  else
 {
    std::string composite;
    composite = "/";
    composite.append(frame_name);
    return composite;
  }
}

std::string assert_resolved(const std::string& prefix, const std::string& frame_id)
{
  return tinyros::tf::resolve(prefix, frame_id);
}

enum ErrorValues { NO_ERROR = 0, LOOKUP_ERROR, CONNECTIVITY_ERROR, EXTRAPOLATION_ERROR};

/** \brief An internal representation of transform chains
 *
 * This struct is how the list of transforms are stored before being passed to computeTransformFromList. */
typedef struct
{
  std::vector<TransformStorage > inverseTransforms;
  std::vector<TransformStorage > forwardTransforms;
} TransformLists;

/** \brief Throw InvalidArgument if quaternion is malformed */
inline void assertQuaternionValid(const tf::Quaternion & q)
{
  if(std::fabs(q.x()*q.x() + q.y()*q.y() + q.z()*q.z() + q.w()*q.w() - 1) > 0.01)
  {
    std::stringstream ss;
    ss << "Quaternion malformed, magnitude: " << q.x()*q.x() + q.y()*q.y() + q.z()*q.z() + q.w()*q.w() << " should be 1.0" <<std::endl;
    throw tinyros::tf::InvalidArgument(ss.str());
  }  //  TINYROS_ASSERT(std::fabs(q.x()*q.x() + q.y()*q.y() + q.z*q.z() + q.w()*q.w() - 1 < 0.01));
}

/** \brief Throw InvalidArgument if quaternion is malformed */
inline void assertQuaternionValid(const geometry_msgs::Quaternion & q)
{
  if(std::fabs(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w - 1) > 0.01)
  {
    std::stringstream ss;
    ss << "Quaternion malformed, magnitude: " << q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w << " should be 1.0" <<std::endl;
    throw tinyros::tf::InvalidArgument(ss.str());
  }  //  TINYROS_ASSERT(std::fabs(q.x()*q.x() + q.y()*q.y() + q.z*q.z() + q.w()*q.w() - 1 < 0.01));
}

/** \brief A Class which provides coordinate transforms between any two frames in a system.
 *
 * This class provides a simple interface to allow recording and lookup of
 * relationships between arbitrary frames of the system.
 *
 * libTF assumes that there is a tree of coordinate frame transforms which define the relationship between all coordinate frames.
 * For example your typical robot would have a transform from global to real world.  And then from base to hand, and from base to head.
 * But Base to Hand really is composed of base to shoulder to elbow to wrist to hand.
 * libTF is designed to take care of all the intermediate steps for you.
 *
 * Internal Representation
 * libTF will store frames with the parameters necessary for generating the transform into that frame from it's parent and a reference to the parent frame.
 * Frames are designated using an std::string
 * 0 is a frame without a parent (the top of a tree)
 * The positions of frames over time must be pushed in.
 *
 * All function calls which pass frame ids can potentially throw the exception tf::LookupException
 */
class Transformer
{
public:
  /************* Constants ***********************/
  static const unsigned int MAX_GRAPH_DEPTH = 100UL;   //!< The maximum number of time to recurse before assuming the tree has a loop.
  static const double DEFAULT_CACHE_TIME;  //!< 10.0 is the default amount of time to cache data in seconds, set in cpp file. 
  static const int64_t DEFAULT_MAX_EXTRAPOLATION_DISTANCE = 0ULL; //!< The default amount of time to extrapolate


  /** Constructor
   * \param interpolating Whether to interpolate, if this is false the closest value will be returned
   * \param cache_time How long to keep a history of transforms in nanoseconds
   *
   */
  Transformer(bool interpolating = true,
              tinyros::Duration cache_time_ = tinyros::Duration(DEFAULT_CACHE_TIME))
  : cache_time(cache_time)
  , interpolating (interpolating)
  , using_dedicated_thread_(false)
  , fall_back_to_wall_time_(false) {
    max_extrapolation_distance_.fromNSec(DEFAULT_MAX_EXTRAPOLATION_DISTANCE);
    frameIDs_["NO_PARENT"] = 0;
    frames_.push_back(NULL);// new TimeCache(interpolating, cache_time, max_extrapolation_distance));//unused but needed for iteration over all elements
    frameIDs_reverse.push_back("NO_PARENT");
    return;
  }
  virtual ~Transformer(void)
  {
    /* deallocate all frames */
    std::scoped_lock lock(frame_mutex_);
    for (std::vector<TimeCache*>::iterator  cache_it = frames_.begin(); cache_it != frames_.end(); ++cache_it)
    {
      delete (*cache_it);
    }
  }

  /** \brief Clear all data */
  void clear()
  {
    std::scoped_lock lock(frame_mutex_);
    if ( frames_.size() > 1 )
    {
      for (std::vector< TimeCache*>::iterator  cache_it = frames_.begin() + 1; cache_it != frames_.end(); ++cache_it)
      {
        (*cache_it)->clearList();
      }
    }
  }

  /** \brief Add transform information to the tf data structure
   * \param transform The transform to store
   * \param authority The source of the information for this transform
   * returns true unless an error occured
   */
  bool setTransform(const StampedTransform& transform, const std::string & authority = "default_authority")
  {

    StampedTransform mapped_transform((tinyros::tf::Transform)transform, transform.stamp_, transform.frame_id_, transform.child_frame_id_);
    mapped_transform.child_frame_id_ = assert_resolved(tf_prefix_, transform.child_frame_id_);
    mapped_transform.frame_id_ = assert_resolved(tf_prefix_, transform.frame_id_);

   
    bool error_exists = false;
    if (mapped_transform.child_frame_id_ == mapped_transform.frame_id_)
    {
      tinyros_log_error("TF_SELF_TRANSFORM: Ignoring transform from authority \"%s\" with frame_id and child_frame_id  \"%s\" because they are the same",  authority.c_str(), mapped_transform.child_frame_id_.c_str());
      error_exists = true;
    }

    if (mapped_transform.child_frame_id_ == "/")//empty frame id will be mapped to "/"
    {
      tinyros_log_error("TF_NO_CHILD_FRAME_ID: Ignoring transform from authority \"%s\" because child_frame_id not set ", authority.c_str());
      error_exists = true;
    }

    if (mapped_transform.frame_id_ == "/")//empty parent id will be mapped to "/"
    {
      tinyros_log_error("TF_NO_FRAME_ID: Ignoring transform with child_frame_id \"%s\"  from authority \"%s\" because frame_id not set", mapped_transform.child_frame_id_.c_str(), authority.c_str());
      error_exists = true;
    }

    if (std::isnan(mapped_transform.getOrigin().x()) || std::isnan(mapped_transform.getOrigin().y()) 
      || std::isnan(mapped_transform.getOrigin().z())|| std::isnan(mapped_transform.getRotation().x()) 
      || std::isnan(mapped_transform.getRotation().y()) || std::isnan(mapped_transform.getRotation().z()) 
      || std::isnan(mapped_transform.getRotation().w()))
    {
      tinyros_log_error("TF_NAN_INPUT: Ignoring transform for child_frame_id \"%s\" from authority \"%s\" because of a nan value in the transform (%f %f %f) (%f %f %f %f)",
                mapped_transform.child_frame_id_.c_str(), authority.c_str(),
                mapped_transform.getOrigin().x(), mapped_transform.getOrigin().y(), mapped_transform.getOrigin().z(),
                mapped_transform.getRotation().x(), mapped_transform.getRotation().y(), mapped_transform.getRotation().z(), mapped_transform.getRotation().w()
                );
      error_exists = true;
    }

    if (error_exists)
      return false;

    {
      std::scoped_lock lock(frame_mutex_);
      CompactFrameID frame_number = lookupOrInsertFrameNumber(mapped_transform.child_frame_id_);
      TimeCache* frame = getFrame(frame_number);
      if (frame == NULL)
      {
      	frames_[frame_number] = new TimeCache(cache_time);
      	frame = frames_[frame_number];
      }

      if (frame->insertData(TransformStorage(mapped_transform, lookupOrInsertFrameNumber(mapped_transform.frame_id_), frame_number)))
      {
        frame_authority_[frame_number] = authority;
      }
      else
      {
        tinyros_log_warn("TF_OLD_DATA ignoring data from the past for frame %s at time %g according to authority %s\nPossible reasons are listed at ", mapped_transform.child_frame_id_.c_str(), mapped_transform.stamp_.toSec(), authority.c_str());
        return false;
      }
    }

    {
      std::scoped_lock lock(transforms_changed_mutex_);
      transforms_changed_.emit();
    }

    return true;
  }

  /*********** Accessors *************/

  /** \brief Get the transform between two frames by frame ID.
   * \param target_frame The frame to which data should be transformed
   * \param source_frame The frame where the data originated
   * \param time The time at which the value of the transform is desired. (0 will get the latest)
   * \param transform The transform reference to fill.  
   *
   * Possible exceptions tf::LookupException, tf::ConnectivityException,
   * tf::MaxDepthException, tf::ExtrapolationException
   */
  void lookupTransform(const std::string& target_frame, const std::string& source_frame,
                     const tinyros::Time& time, StampedTransform& transform) const
  {
  	  std::string mapped_tgt = assert_resolved(tf_prefix_, target_frame);
  	  std::string mapped_src = assert_resolved(tf_prefix_, source_frame);

  	  if (mapped_tgt == mapped_src) {
  		  transform.setIdentity();
  		  transform.child_frame_id_ = mapped_src;
  		  transform.frame_id_       = mapped_tgt;
  		  transform.stamp_          = now();
  		  return;
  	  }

  	  std::scoped_lock lock(frame_mutex_);

  	  CompactFrameID target_id = lookupFrameNumber(mapped_tgt);
  	  CompactFrameID source_id = lookupFrameNumber(mapped_src);

  	  std::string error_string;
  	  TransformAccum accum;
  	  int retval = walkToTopParent(accum, time, target_id, source_id, &error_string);
  	  if (retval != NO_ERROR)
  	  {
  	    switch (retval)
  	    {
  	    case CONNECTIVITY_ERROR:
  	      throw ConnectivityException(error_string);
  	    case EXTRAPOLATION_ERROR:
  	      throw ExtrapolationException(error_string);
  	    case LOOKUP_ERROR:
  	      throw LookupException(error_string);
  	    default:
  	      tinyros_log_error("Unknown error code: %d", retval);
  	      TINYROS_BREAK();
  	    }
  	  }

  	  transform.setOrigin(accum.result_vec);
  	  transform.setRotation(accum.result_quat);
  	  transform.child_frame_id_ = mapped_src;
  	  transform.frame_id_       = mapped_tgt;
  	  transform.stamp_          = accum.time;
  }
  
  /** \brief Get the transform between two frames by frame ID assuming fixed frame.
   * \param target_frame The frame to which data should be transformed
   * \param target_time The time to which the data should be transformed. (0 will get the latest)
   * \param source_frame The frame where the data originated
   * \param source_time The time at which the source_frame should be evaluated. (0 will get the latest)
   * \param fixed_frame The frame in which to assume the transform is constant in time. 
   * \param transform The transform reference to fill.  
   *
   * Possible exceptions tf::LookupException, tf::ConnectivityException,
   * tf::MaxDepthException, tf::ExtrapolationException
   */
  void lookupTransform(const std::string& target_frame,const tinyros::Time& target_time,
                       const std::string& source_frame, const tinyros::Time& source_time, 
                       const std::string& fixed_frame, StampedTransform& transform) const
  {
    tinyros::tf::StampedTransform temp1, temp2;
    lookupTransform(fixed_frame, source_frame, source_time, temp1);
    lookupTransform(target_frame, fixed_frame, target_time, temp2);
    transform.setData( temp2 * temp1);
    transform.stamp_ = temp2.stamp_;
    transform.frame_id_ = target_frame;
    transform.child_frame_id_ = source_frame;
  }

  /** \brief Lookup the twist of the tracking_frame with respect to the observation frame in the reference_frame using the reference point
   * \param tracking_frame The frame to track
   * \param observation_frame The frame from which to measure the twist
   * \param reference_frame The reference frame in which to express the twist
   * \param reference_point The reference point with which to express the twist
   * \param reference_point_frame The frame_id in which the reference point is expressed
   * \param time The time at which to get the velocity
   * \param duration The period over which to average
   * \param twist The twist output
   * 
   * This will compute the average velocity on the interval 
   * (time - duration/2, time+duration/2). If that is too close to the most
   * recent reading, in which case it will shift the interval up to
   * duration/2 to prevent extrapolation.  Possible exceptions
   * tf::LookupException, tf::ConnectivityException,
   * tf::MaxDepthException, tf::ExtrapolationException
   * 
   * New in geometry 1.1
   */

  void lookupTwist(const std::string& tracking_frame, const std::string& observation_frame, const std::string& reference_frame,
                   const tinyros::tf::Point & reference_point, const std::string& reference_point_frame, 
                   const tinyros::Time& time, const tinyros::Duration& averaging_interval, 
                   tinyros::geometry_msgs::Twist& twist) const
  {
    tinyros::Time latest_time, target_time;
    getLatestCommonTime(observation_frame, tracking_frame, latest_time, NULL); ///\TODO check time on reference point too

    if (tinyros::Time() == time)
      target_time = latest_time;
    else
      target_time = time;

    tinyros::Time end_time = std::min(target_time + averaging_interval *0.5 , latest_time);
    
    tinyros::Time start_time = std::max(tinyros::Time().fromSec(.00001) + averaging_interval, end_time) - averaging_interval;  // don't collide with zero
    tinyros::Duration corrected_averaging_interval = end_time - start_time; //correct for the possiblity that start time was truncated above.
    StampedTransform start, end;
    lookupTransform(observation_frame, tracking_frame, start_time, start);
    lookupTransform(observation_frame, tracking_frame, end_time, end);


    tinyros::tf::Matrix3x3 temp = start.getBasis().inverse() * end.getBasis();
    tinyros::tf::Quaternion quat_temp;
    temp.getRotation(quat_temp);
    tinyros::tf::Vector3 o = start.getBasis() * quat_temp.getAxis();
    tfScalar ang = quat_temp.getAngle();
    
    double delta_x = end.getOrigin().getX() - start.getOrigin().getX();
    double delta_y = end.getOrigin().getY() - start.getOrigin().getY();
    double delta_z = end.getOrigin().getZ() - start.getOrigin().getZ();


    tinyros::tf::Vector3 twist_vel ((delta_x)/corrected_averaging_interval.toSec(), 
                         (delta_y)/corrected_averaging_interval.toSec(),
                         (delta_z)/corrected_averaging_interval.toSec());
    tinyros::tf::Vector3 twist_rot = o * (ang / corrected_averaging_interval.toSec());


    // This is a twist w/ reference frame in observation_frame  and reference point is in the tracking_frame at the origin (at start_time)


    //correct for the position of the reference frame
    tinyros::tf::StampedTransform inverse;
    lookupTransform(reference_frame,tracking_frame,  target_time, inverse);
    tinyros::tf::Vector3 out_rot = inverse.getBasis() * twist_rot;
    tinyros::tf::Vector3 out_vel = inverse.getBasis()* twist_vel + inverse.getOrigin().cross(out_rot);


    //Rereference the twist about a new reference point
    // Start by computing the original reference point in the reference frame:
    tinyros::tf::Stamped<tinyros::tf::Point> rp_orig(tinyros::tf::Point(0,0,0), target_time, tracking_frame);
    transformPoint(reference_frame, rp_orig, rp_orig);
    // convert the requrested reference point into the right frame
    tinyros::tf::Stamped<tinyros::tf::Point> rp_desired(reference_point, target_time, reference_point_frame);
    transformPoint(reference_frame, rp_desired, rp_desired);
    // compute the delta
    tinyros::tf::Point delta = rp_desired - rp_orig;
    // Correct for the change in reference point 
    out_vel = out_vel + out_rot * delta;
    // out_rot unchanged   

    /*
      printf("KDL: Rotation %f %f %f, Translation:%f %f %f\n", 
           out_rot.x(),out_rot.y(),out_rot.z(),
           out_vel.x(),out_vel.y(),out_vel.z());
    */   

    twist.linear.x =  out_vel.x();
    twist.linear.y =  out_vel.y();
    twist.linear.z =  out_vel.z();
    twist.angular.x =  out_rot.x();
    twist.angular.y =  out_rot.y();
    twist.angular.z =  out_rot.z();
  }

  /** \brief lookup the twist of the tracking frame with respect to the observational frame 
   * 
   * This is a simplified version of
   * lookupTwist with it assumed that the reference point is the
   * origin of the tracking frame, and the reference frame is the
   * observation frame.  
   * 
   * New in geometry 1.1
   */

  void lookupTwist(const std::string& tracking_frame, const std::string& observation_frame, 
                   const tinyros::Time& time, const tinyros::Duration& averaging_interval,
                   tinyros::geometry_msgs::Twist& twist) const
  {
    lookupTwist(tracking_frame, observation_frame, observation_frame, tinyros::tf::Point(0,0,0), tracking_frame, time, averaging_interval, twist);
  }

  /** \brief Block until a transform is possible or it times out
   * \param target_frame The frame into which to transform
   * \param source_frame The frame from which to transform
   * \param time The time at which to transform
   * \param timeout How long to block before failing
   * \param polling_sleep_duration How often to retest if failed
   * \param error_msg A pointer to a string which will be filled with why the transform failed, if not NULL
   */
  bool waitForTransform(const std::string& target_frame, const std::string& source_frame,
                        const tinyros::Time& time, const tinyros::Duration& timeout, 
                        const tinyros::Duration& polling_sleep_duration = tinyros::Duration(0.01), std::string* error_msg = NULL) const
  {
    tinyros::Time start_time = now();
    std::string mapped_tgt = assert_resolved(tf_prefix_, target_frame);
    std::string mapped_src = assert_resolved(tf_prefix_, source_frame);
  
    while (ok() && now() >= start_time && (now() - start_time) < timeout)
    {
      if (frameExists(mapped_tgt) && frameExists(mapped_src) && (canTransform(mapped_tgt, mapped_src, time, error_msg)))
        return true;
  
      usleep(polling_sleep_duration.sec * 1000000 + polling_sleep_duration.nsec / 1000);
    }
    return false;
  }
  
  /** \brief Test if a transform is possible
   * \param target_frame The frame into which to transform
   * \param source_frame The frame from which to transform
   * \param time The time at which to transform
   * \param error_msg A pointer to a string which will be filled with why the transform failed, if not NULL
   */
  bool canTransform(const std::string& target_frame, const std::string& source_frame,
                    const tinyros::Time& time,
                    std::string* error_msg = NULL) const
  {
  	std::string mapped_tgt = assert_resolved(tf_prefix_, target_frame);
  	std::string mapped_src = assert_resolved(tf_prefix_, source_frame);

  	if (mapped_tgt == mapped_src)
  		return true;

  	std::scoped_lock lock(frame_mutex_);

    if (!frameExists(mapped_tgt) || !frameExists(mapped_src))
  	  return false;

    CompactFrameID target_id = lookupFrameNumber(mapped_tgt);
    CompactFrameID source_id = lookupFrameNumber(mapped_src);

    return canTransformNoLock(target_id, source_id, time, error_msg);
  }

  /** \brief Test if a transform is possible
   * \param target_frame The frame into which to transform
   * \param target_time The time into which to transform
   * \param source_frame The frame from which to transform
   * \param source_time The time from which to transform
   * \param fixed_frame The frame in which to treat the transform as constant in time
   * \param error_msg A pointer to a string which will be filled with why the transform failed, if not NULL
   */
  bool canTransform(const std::string& target_frame, const tinyros::Time& target_time,
                    const std::string& source_frame, const tinyros::Time& source_time,
                    const std::string& fixed_frame,
                    std::string* error_msg = NULL) const
  {
    return canTransform(target_frame, fixed_frame, target_time) && canTransform(fixed_frame, source_frame, source_time, error_msg);
  }

  /** \brief Block until a transform is possible or it times out
   * \param target_frame The frame into which to transform
   * \param target_time The time into which to transform
   * \param source_frame The frame from which to transform
   * \param source_time The time from which to transform
   * \param fixed_frame The frame in which to treat the transform as constant in time
   * \param timeout How long to block before failing
   * \param polling_sleep_duration How often to retest if failed
   * \param error_msg A pointer to a string which will be filled with why the transform failed, if not NULL
   */
  bool waitForTransform(const std::string& target_frame, const tinyros::Time& target_time,
                    const std::string& source_frame, const tinyros::Time& source_time, const std::string& fixed_frame,
                    const tinyros::Duration& timeout, const tinyros::Duration& polling_sleep_duration = tinyros::Duration(0.01),
                    std::string* error_msg = NULL) const
  {
    return waitForTransform(target_frame, fixed_frame, target_time, timeout, polling_sleep_duration, error_msg) && waitForTransform(fixed_frame, source_frame, source_time, timeout, polling_sleep_duration, error_msg);
  }

  /**@brief Return the latest rostime which is common across the spanning set
   * zero if fails to cross */
  int getLatestCommonTime(const std::string &source_frame, const std::string &target_frame, 
                    tinyros::Time& time, std::string* error_string) const
  {
	  std::string mapped_tgt = assert_resolved(tf_prefix_, target_frame);
	  std::string mapped_src = assert_resolved(tf_prefix_, source_frame);

	  if (!frameExists(mapped_tgt) || !frameExists(mapped_src)) {
		  time = tinyros::Time();
		  return LOOKUP_ERROR;
	  }

	  CompactFrameID source_id = lookupFrameNumber(mapped_src);
	  CompactFrameID target_id = lookupFrameNumber(mapped_tgt);
	  return getLatestCommonTime(source_id, target_id, time, error_string);
  }

  /** \brief Transform a Stamped Quaternion into the target frame
   * This can throw anything a lookupTransform can throw as well as tf::InvalidArgument. */
  void transformQuaternion(const std::string& target_frame, const Stamped<tinyros::tf::Quaternion>& stamped_in,
                      Stamped<tinyros::tf::Quaternion>& stamped_out) const
  {
    tinyros::tf::assertQuaternionValid(stamped_in);

    StampedTransform transform;
    lookupTransform(target_frame, stamped_in.frame_id_, stamped_in.stamp_, transform);

    stamped_out.setData( transform * stamped_in);
    stamped_out.stamp_ = transform.stamp_;
    stamped_out.frame_id_ = target_frame;
  }
  
  /** \brief Transform a Stamped Vector3 into the target frame 
   * This can throw anything a lookupTransform can throw as well as tf::InvalidArgument.*/
  void transformVector(const std::string& target_frame, const Stamped<tinyros::tf::Vector3>& stamped_in,
                        Stamped<tinyros::tf::Vector3>& stamped_out) const
  {
    StampedTransform transform;
    lookupTransform(target_frame, stamped_in.frame_id_, stamped_in.stamp_, transform);

    /** \todo may not be most efficient */
    tinyros::tf::Vector3 end = stamped_in;
    tinyros::tf::Vector3 origin = tf::Vector3(0,0,0);
    tinyros::tf::Vector3 output = (transform * end) - (transform * origin);
    stamped_out.setData( output);

    stamped_out.stamp_ = transform.stamp_;
    stamped_out.frame_id_ = target_frame;
  }
  
  /** \brief Transform a Stamped Point into the target frame 
   * This can throw anything a lookupTransform can throw as well as tf::InvalidArgument.*/
  void transformPoint(const std::string& target_frame, const Stamped<tinyros::tf::Point>& stamped_in, 
                          Stamped<tinyros::tf::Point>& stamped_out) const
  {
    StampedTransform transform;
    lookupTransform(target_frame, stamped_in.frame_id_, stamped_in.stamp_, transform);
  
    stamped_out.setData(transform * stamped_in);
    stamped_out.stamp_ = transform.stamp_;
    stamped_out.frame_id_ = target_frame;
  }
  
  /** \brief Transform a Stamped Pose into the target frame 
   * This can throw anything a lookupTransform can throw as well as tf::InvalidArgument.*/
  void transformPose(const std::string& target_frame, const Stamped<tinyros::tf::Pose>& stamped_in, Stamped<tinyros::tf::Pose>& stamped_out) const
  {
    StampedTransform transform;
    lookupTransform(target_frame, stamped_in.frame_id_, stamped_in.stamp_, transform);

    stamped_out.setData(transform * stamped_in);
    stamped_out.stamp_ = transform.stamp_;
    stamped_out.frame_id_ = target_frame;
  }

  /** \brief Transform a Stamped Quaternion into the target frame 
   * This can throw anything a lookupTransform can throw as well as tf::InvalidArgument.*/
  void transformQuaternion(const std::string& target_frame, const tinyros::Time& target_time,
                           const Stamped<tinyros::tf::Quaternion>& stamped_in,
                           const std::string& fixed_frame,
                           Stamped<tinyros::tf::Quaternion>& stamped_out) const
  {
    tinyros::tf::assertQuaternionValid(stamped_in);
    StampedTransform transform;
    lookupTransform(target_frame, target_time,
                    stamped_in.frame_id_,stamped_in.stamp_,
                    fixed_frame, transform);

    stamped_out.setData( transform * stamped_in);
    stamped_out.stamp_ = transform.stamp_;
    stamped_out.frame_id_ = target_frame;
  }
  
  /** \brief Transform a Stamped Vector3 into the target frame 
   * This can throw anything a lookupTransform can throw as well as tf::InvalidArgument.*/
  void transformVector(const std::string& target_frame, const tinyros::Time& target_time,
                       const Stamped<tinyros::tf::Vector3>& stamped_in,
                       const std::string& fixed_frame,
                       Stamped<tinyros::tf::Vector3>& stamped_out) const
  {
    StampedTransform transform;
    lookupTransform(target_frame, target_time,
                    stamped_in.frame_id_,stamped_in.stamp_,
                    fixed_frame, transform);

    /** \todo may not be most efficient */
    tinyros::tf::Vector3 end = stamped_in;
    tinyros::tf::Vector3 origin = tf::Vector3(0,0,0);
    tinyros::tf::Vector3 output = (transform * end) - (transform * origin);
    stamped_out.setData( output);

    stamped_out.stamp_ = transform.stamp_;
    stamped_out.frame_id_ = target_frame;
  }
  
  /** \brief Transform a Stamped Point into the target frame
   * This can throw anything a lookupTransform can throw as well as tf::InvalidArgument.*/
  void transformPoint(const std::string& target_frame, const tinyros::Time& target_time,
                      const Stamped<tinyros::tf::Point>& stamped_in,
                      const std::string& fixed_frame,
                      Stamped<tinyros::tf::Point>& stamped_out) const
  {
    StampedTransform transform;
    lookupTransform(target_frame, target_time,
                    stamped_in.frame_id_,stamped_in.stamp_,
                    fixed_frame, transform);

    stamped_out.setData(transform * stamped_in);
    stamped_out.stamp_ = transform.stamp_;
    stamped_out.frame_id_ = target_frame;
  }
  
  /** \brief Transform a Stamped Pose into the target frame
   * This can throw anything a lookupTransform can throw as well as tf::InvalidArgument.*/
  void transformPose(const std::string& target_frame, const tinyros::Time& target_time,
                     const Stamped<tinyros::tf::Pose>& stamped_in,
                     const std::string& fixed_frame,
                     Stamped<tinyros::tf::Pose>& stamped_out) const
  {
    StampedTransform transform;
    lookupTransform(target_frame, target_time,
                    stamped_in.frame_id_,stamped_in.stamp_,
                    fixed_frame, transform);

    stamped_out.setData(transform * stamped_in);
    stamped_out.stamp_ = transform.stamp_;
    stamped_out.frame_id_ = target_frame;
  }

  /** \brief Debugging function that will print the spanning chain of transforms.
   * Possible exceptions tf::LookupException, tf::ConnectivityException,
   * tf::MaxDepthException
   */
  //std::string chainAsString(const std::string & target_frame, ros::Time target_time, const std::string & source_frame, ros::Time source_time, const std::string & fixed_frame) const;

  /** \brief Debugging function that will print the spanning chain of transforms.
   * Possible exceptions tf::LookupException, tf::ConnectivityException,
   * tf::MaxDepthException
   */
  void chainAsVector(const std::string & target_frame, tinyros::Time target_time, const std::string & source_frame, 
                  tinyros::Time source_time, const std::string & fixed_frame, std::vector<std::string>& output) const
  {
    std::string error_string;

    output.clear(); //empty vector

    std::stringstream mstream;
    std::scoped_lock lock(frame_mutex_);

    TransformStorage temp;

    ///regular transforms
    for (unsigned int counter = 1; counter < frames_.size(); counter ++)
    {
      TimeCache* frame_ptr = getFrame(CompactFrameID(counter));
      if (frame_ptr == NULL)
        continue;
      CompactFrameID frame_id_num;
      if (frame_ptr->getData(tinyros::Time(), temp))
          frame_id_num = temp.frame_id_;
        else
        {
          frame_id_num = 0;
        }
        output.push_back(frameIDs_reverse[frame_id_num]);
    }
  }

  /** \brief A way to see what frames have been cached
   * Useful for debugging
   */
  std::string allFramesAsString() const
  {
    std::stringstream mstream;
    std::scoped_lock lock(frame_mutex_);

    TransformStorage temp;

    ///regular transforms
    for (unsigned int counter = 1; counter < frames_.size(); counter ++)
    {
      TimeCache* frame_ptr = getFrame(CompactFrameID(counter));
      if (frame_ptr == NULL)
        continue;
      CompactFrameID frame_id_num;
      if(  frame_ptr->getData(tinyros::Time(), temp))
        frame_id_num = temp.frame_id_;
      else
      {
        frame_id_num = 0;
      }
      mstream << "Frame "<< frameIDs_reverse[counter] << " exists with parent " << frameIDs_reverse[frame_id_num] << "." <<std::endl;
    }

    return mstream.str();
  }

  /** \brief A way to see what frames have been cached
   * Useful for debugging
   */
  std::string allFramesAsDot() const
  {
    std::stringstream mstream;
    mstream << "digraph G {" << std::endl;
    std::scoped_lock lock(frame_mutex_);

    TransformStorage temp;

    tinyros::Time current_time = now();

    if (frames_.size() ==1)
      mstream <<"\"no tf data recieved\"";

    mstream.precision(3);
    mstream.setf(std::ios::fixed,std::ios::floatfield);
      
     //  for (std::vector< TimeCache*>::iterator  it = frames_.begin(); it != frames_.end(); ++it)
    for (unsigned int counter = 1; counter < frames_.size(); counter ++)//one referenced for 0 is no frame
    {
      unsigned int frame_id_num;
      if(  getFrame(counter)->getData(tinyros::Time(), temp))
        frame_id_num = temp.frame_id_;
      else
      {
        frame_id_num = 0;
      }
      if (frame_id_num != 0)
      {
        std::string authority = "no recorded authority";
        std::map<unsigned int, std::string>::const_iterator it = frame_authority_.find(counter);
        if (it != frame_authority_.end())
          authority = it->second;

        double rate = getFrame(counter)->getListLength() / std::max((getFrame(counter)->getLatestTimestamp().toSec() -
                                                                     getFrame(counter)->getOldestTimestamp().toSec() ), 0.0001);

        mstream << std::fixed; //fixed point notation
        mstream.precision(3); //3 decimal places
        mstream << "\"" << frameIDs_reverse[frame_id_num] << "\"" << " -> "
                << "\"" << frameIDs_reverse[counter] << "\"" << "[label=\""
          //<< "Time: " << current_time.toSec() << "\\n"
                << "Broadcaster: " << authority << "\\n"
                << "Average rate: " << rate << " Hz\\n"
                << "Most recent transform: " << (current_time - getFrame(counter)->getLatestTimestamp()).toSec() << " sec old \\n"
          //    << "(time: " << getFrame(counter)->getLatestTimestamp().toSec() << ")\\n"
          //    << "Oldest transform: " << (current_time - getFrame(counter)->getOldestTimestamp()).toSec() << " sec old \\n"
          //    << "(time: " << (getFrame(counter)->getOldestTimestamp()).toSec() << ")\\n"
                << "Buffer length: " << (getFrame(counter)->getLatestTimestamp()-getFrame(counter)->getOldestTimestamp()).toSec() << " sec\\n"
                <<"\"];" <<std::endl;
      }
    }
    
    for (unsigned int counter = 1; counter < frames_.size(); counter ++)//one referenced for 0 is no frame
    {
      unsigned int frame_id_num;
      if(  getFrame(counter)->getData(tinyros::Time(), temp))
        frame_id_num = temp.frame_id_;
      else
        {
  	frame_id_num = 0;
        }

      if(frameIDs_reverse[frame_id_num]=="NO_PARENT")
      {
        mstream << "edge [style=invis];" <<std::endl;
        mstream << " subgraph cluster_legend { style=bold; color=black; label =\"view_frames Result\";\n"
                << "\"Recorded at time: " << current_time.toSec() << "\"[ shape=plaintext ] ;\n "
  	      << "}" << "->" << "\"" << frameIDs_reverse[counter]<<"\";" <<std::endl;
      }
    }
    mstream << "}";
    return mstream.str();
  }

  /** \brief A way to get a std::vector of available frame ids */
  void getFrameStrings(std::vector<std::string>& vec) const
  {
    vec.clear();

    std::scoped_lock lock(frame_mutex_);

    TransformStorage temp;

    //  for (std::vector< TimeCache*>::iterator  it = frames_.begin(); it != frames_.end(); ++it)
    for (unsigned int counter = 1; counter < frames_.size(); counter ++)
    {
      vec.push_back(frameIDs_reverse[counter]);
    }
    return;
  }

  /**@brief Fill the parent of a frame.
   * @param frame_id The frame id of the frame in question
   * @param parent The reference to the string to fill the parent
   * Returns true unless "NO_PARENT" */
  bool getParent(const std::string& frame_id, tinyros::Time time, std::string& parent) const
  {
    std::string mapped_frame_id = assert_resolved(tf_prefix_, frame_id);
    tinyros::tf::TimeCache* cache;
    try
    {
      cache = getFrame(lookupFrameNumber(mapped_frame_id));
    }
    catch  (tinyros::tf::LookupException &ex)
    {
      tinyros_log_error("Transformer::getParent: %s",ex.what());
      return false;
    }

    TransformStorage temp;
    if (! cache->getData(time, temp)) {
      tinyros_log_debug("Transformer::getParent: No data for parent of %s", mapped_frame_id.c_str());
      return false;
    }
    if (temp.frame_id_ == 0) {
      tinyros_log_debug("Transformer::getParent: No parent for %s", mapped_frame_id.c_str());
      return false;
    }

    parent = lookupFrameString(temp.frame_id_);
    return true;
  };

  /**@brief Check if a frame exists in the tree
   * @param frame_id_str The frame id in question  */
  bool frameExists(const std::string& frame_id_str) const
  {
    std::scoped_lock lock(frame_mutex_);
    std::string frame_id_resolveped = assert_resolved(tf_prefix_, frame_id_str);
    
    return frameIDs_.count(frame_id_resolveped);
  }

  /**@brief Set the distance which tf is allow to extrapolate
   * \param distance How far to extrapolate before throwing an exception
   * default is zero */
  void setExtrapolationLimit(const tinyros::Duration& distance)
  {
    max_extrapolation_distance_ = distance;
  }

  /**@brief Get the duration over which this transformer will cache */
  tinyros::Duration getCacheLength() { return cache_time;}

  /**
   * \brief Add a callback that happens when a new transform has arrived
   *
   * \param callback The callback, of the form void func();
   * \return A boost::signals::connection object that can be used to remove this
   * listener
   */
  int addTransformsChangedListener(std::function<void(void)> callback)
  {
    std::scoped_lock lock(transforms_changed_mutex_);
    return transforms_changed_.connect(callback);
  }
  
  void removeTransformsChangedListener(int c) 
  {
    std::scoped_lock lock(transforms_changed_mutex_);
    transforms_changed_.disconnect(c);
  }
  

  /** 
   * \brief Get the tf_prefix this is running with
   */
  std::string getTFPrefix() const { return tf_prefix_;}

  //Declare that it is safe to call waitForTransform
  void setUsingDedicatedThread(bool value) { using_dedicated_thread_ = value;}
  // Get the state of using_dedicated_thread_
  bool isUsingDedicatedThread() { return using_dedicated_thread_;}

protected:

  /** \brief The internal storage class for ReferenceTransform.
   *
   * An instance of this class is created for each frame in the system.
   * This class natively handles the relationship between frames.
   *
   * The derived class Pose3DCache provides a buffered history of positions
   * with interpolation.
   *
   */


  /******************** Internal Storage ****************/

  /** \brief A map from string frame ids to CompactFrameID */
  typedef std::unordered_map<std::string, CompactFrameID> M_StringToCompactFrameID;
  M_StringToCompactFrameID frameIDs_;
  /** \brief A map from CompactFrameID frame_id_numbers to string for debugging and output */
  std::vector<std::string> frameIDs_reverse;
  /** \brief A map to lookup the most recent authority for a given frame */
  std::map<CompactFrameID, std::string> frame_authority_;

  /// How long to cache transform history
  tinyros::Duration cache_time_;

  /** \brief The pointers to potential frames that the tree can be made of.
   * The frames will be dynamically allocated at run time when set the first time. */
  std::vector<TimeCache*> frames_;

  /** \brief A mutex to protect testing and allocating new frames on the above vector. */
  mutable std::recursive_mutex frame_mutex_;

  /// How long to cache transform history
  tinyros::Duration cache_time;

  /// whether or not to interpolate or extrapolate
  bool interpolating;

  /// whether or not to allow extrapolation
  tinyros::Duration max_extrapolation_distance_;


  /// transform prefix to apply as necessary
  std::string tf_prefix_;

  typedef tinyros::tf::Signal<> TransformsChangedSignal;
  /// Signal which is fired whenever new transform data has arrived, from the thread the data arrived in
  TransformsChangedSignal transforms_changed_;
  std::mutex transforms_changed_mutex_;

  //Whether it is safe to use waitForTransform.  This is basically stating that tf is multithreaded.  
  bool using_dedicated_thread_;
  
 public:
  // A flag to allow falling back to wall time
  bool fall_back_to_wall_time_;
  
 protected:
  /** Hack method to work around #4150 */
  tinyros::Time now() const { 
    return tinyros::Time::now();
  }

  // Allows broadcaster to check ok() before wait for transform
  // Always returns true in base class 
  virtual bool ok() const { return true; }
   
  /************************* Internal Functions ****************************/

  /** \brief An accessor to get a frame, which will throw an exception if the frame is no there.
   * \param frame_number The frameID of the desired Reference Frame
   *
   * This is an internal function which will get the pointer to the frame associated with the frame id
   * Possible Exception: tf::LookupException
   */
  TimeCache* getFrame(unsigned int frame_id) const
  {
    if (frame_id == 0) /// @todo check larger values too
      return NULL;
    else
      return frames_[frame_id];
  }

  /// String to number for frame lookup with dynamic allocation of new frames
  CompactFrameID lookupFrameNumber(const std::string& frameid_str) const
  {
    unsigned int retval = 0;
    std::scoped_lock(frame_mutex_);
    M_StringToCompactFrameID::const_iterator map_it = frameIDs_.find(frameid_str);
    if (map_it == frameIDs_.end())
    {
      std::stringstream ss;
      ss << "Frame id " << frameid_str << " does not exist! Frames (" << frameIDs_.size() << "): " << allFramesAsString();
      throw tinyros::tf::LookupException(ss.str());
    }
    else
      retval = map_it->second;
    return retval;
  }

  /// String to number for frame lookup with dynamic allocation of new frames
  CompactFrameID lookupOrInsertFrameNumber(const std::string& frameid_str)
  {
    unsigned int retval = 0;
    std::scoped_lock(frame_mutex_);
    M_StringToCompactFrameID::iterator map_it = frameIDs_.find(frameid_str);
    if (map_it == frameIDs_.end())
    {
      retval = frames_.size();
      frameIDs_[frameid_str] = retval;
      frames_.push_back( new TimeCache(cache_time));
      frameIDs_reverse.push_back(frameid_str);
    }
    else
      retval = frameIDs_[frameid_str];
    return retval;
  }
  
  ///Number to string frame lookup may throw LookupException if number invalid
  std::string lookupFrameString(unsigned int frame_id_num) const
  {
    if (frame_id_num >= frameIDs_reverse.size())
    {
      std::stringstream ss;
      ss << "Reverse lookup of frame id " << frame_id_num << " failed!";
      throw LookupException(ss.str());
    }
    else
      return frameIDs_reverse[frame_id_num];

  }

  /*
  bool test_extrapolation_one_value(const ros::Time& target_time, const TransformStorage& tr, std::string* error_string) const;
  bool test_extrapolation_past(const ros::Time& target_time, const TransformStorage& tr, std::string* error_string) const;
  bool test_extrapolation_future(const ros::Time& target_time, const TransformStorage& tr, std::string* error_string) const;
  bool test_extrapolation(const ros::Time& target_time, const TransformLists& t_lists, std::string * error_string) const;
	*/

 private:
  /**@brief Return the latest rostime which is common across the spanning set
   * zero if fails to cross */
  int getLatestCommonTime(CompactFrameID target_id, CompactFrameID source_id, tinyros::Time & time, std::string * error_string) const
  {
    if (source_id == target_id)
    {
      //Set time to latest timestamp of frameid in case of target and source frame id are the same
      time = now();
      return NO_ERROR;
    }

    std::vector<P_TimeAndFrameID> lct_cache;

    // Walk the tree to its root from the source frame, accumulating the list of parent/time as well as the latest time
    // in the target is a direct parent
    CompactFrameID frame = source_id;
    P_TimeAndFrameID temp;
    uint32_t depth = 0;
    tinyros::Time common_time = tinyros::Time(std::numeric_limits<uint32_t>::max(), 999999999);
    while (frame != 0)
    {
      TimeCache* cache = getFrame(frame);

      if (!cache)
      {
        // There will be no cache for the very root of the tree
        break;
      }

      P_TimeAndFrameID latest = cache->getLatestTimeAndParent();

      if (latest.second == 0)
      {
        // Just break out here... there may still be a path from source -> target
        break;
      }

      if (!latest.first.isZero())
      {
        common_time = std::min(latest.first, common_time);
      }

      lct_cache.push_back(latest);

      frame = latest.second;

      // Early out... target frame is a direct parent of the source frame
      if (frame == target_id)
      {
        time = common_time;
        if (time == tinyros::Time(std::numeric_limits<uint32_t>::max(), 999999999))
        {
          time = tinyros::Time();
        }
        return NO_ERROR;
      }

      ++depth;
      if (depth > MAX_GRAPH_DEPTH)
      {
        if (error_string)
        {
          std::stringstream ss;
          ss<<"The tf tree is invalid because it contains a loop." << std::endl
            << allFramesAsString() << std::endl;
          *error_string = ss.str();
        }
        return LOOKUP_ERROR;
      }
    }

    // Now walk to the top parent from the target frame, accumulating the latest time and looking for a common parent
    frame = target_id;
    depth = 0;
    common_time = tinyros::Time(std::numeric_limits<uint32_t>::max(), 999999999);
    CompactFrameID common_parent = 0;
    while (true)
    {
      TimeCache* cache = getFrame(frame);

      if (!cache)
      {
        break;
      }

      P_TimeAndFrameID latest = cache->getLatestTimeAndParent();

      if (latest.second == 0)
      {
        break;
      }

      if (!latest.first.isZero())
      {
        common_time = std::min(latest.first, common_time);
      }

      std::vector<P_TimeAndFrameID>::iterator it = std::find_if(lct_cache.begin(), lct_cache.end(), TimeAndFrameIDFrameComparator(latest.second));
      if (it != lct_cache.end()) // found a common parent
      {
        common_parent = it->second;
        break;
      }

      frame = latest.second;

      // Early out... source frame is a direct parent of the target frame
      if (frame == source_id)
      {
        time = common_time;
        if (time == tinyros::Time(std::numeric_limits<uint32_t>::max(), 999999999))
        {
          time = tinyros::Time();
        }
        return NO_ERROR;
      }

      ++depth;
      if (depth > MAX_GRAPH_DEPTH)
      {
        if (error_string)
        {
          std::stringstream ss;
          ss<<"The tf tree is invalid because it contains a loop." << std::endl
            << allFramesAsString() << std::endl;
          *error_string = ss.str();
        }
        return LOOKUP_ERROR;
      }
    }

    if (common_parent == 0)
    {
      createConnectivityErrorString(source_id, target_id, error_string);
      return CONNECTIVITY_ERROR;
    }

    // Loop through the source -> root list until we hit the common parent
    {
      std::vector<P_TimeAndFrameID>::iterator it = lct_cache.begin();
      std::vector<P_TimeAndFrameID>::iterator end = lct_cache.end();
      for (; it != end; ++it)
      {
        if (!it->first.isZero())
        {
          common_time = std::min(common_time, it->first);
        }

        if (it->second == common_parent)
        {
          break;
        }
      }
    }

    if (common_time == tinyros::Time(std::numeric_limits<uint32_t>::max(), 999999999))
    {
      common_time = tinyros::Time();
    }

    time = common_time;
    return NO_ERROR;
  }

  template<typename F>
  int walkToTopParent(F& f, tinyros::Time time, CompactFrameID target_id, CompactFrameID source_id, std::string* error_string) const
  {
    // Short circuit if zero length transform to allow lookups on non existant links
    if (source_id == target_id)
    {
      f.finalize(Identity, time);
      return NO_ERROR;
    }

    //If getting the latest get the latest common time
    if (time == tinyros::Time())
    {
      int retval = getLatestCommonTime(target_id, source_id, time, error_string);
      if (retval != NO_ERROR)
      {
        return retval;
      }
    }

    // Walk the tree to its root from the source frame, accumulating the transform
    CompactFrameID frame = source_id;
    CompactFrameID top_parent = frame;
    uint32_t depth = 0;
    while (frame != 0)
    {
      TimeCache* cache = getFrame(frame);

      if (!cache)
      {
        // There will be no cache for the very root of the tree
        top_parent = frame;
        break;
      }

      CompactFrameID parent = f.gather(cache, time, 0);
      if (parent == 0)
      {
        // Just break out here... there may still be a path from source -> target
        top_parent = frame;
        break;
      }

      // Early out... target frame is a direct parent of the source frame
      if (frame == target_id)
      {
        f.finalize(TargetParentOfSource, time);
        return NO_ERROR;
      }

      f.accum(true);

      top_parent = frame;
      frame = parent;

      ++depth;
      if (depth > MAX_GRAPH_DEPTH)
      {
        if (error_string)
        {
          std::stringstream ss;
          ss << "The tf tree is invalid because it contains a loop." << std::endl
             << allFramesAsString() << std::endl;
          *error_string = ss.str();
        }
        return LOOKUP_ERROR;
      }
    }

    // Now walk to the top parent from the target frame, accumulating its transform
    frame = target_id;
    depth = 0;
    while (frame != top_parent)
    {
      TimeCache* cache = getFrame(frame);

      if (!cache)
      {
        break;
      }

      CompactFrameID parent = f.gather(cache, time, error_string);
      if (parent == 0)
      {
        if (error_string)
        {
          std::stringstream ss;
          ss << *error_string << ", when looking up transform from frame [" << lookupFrameString(source_id) << "] to frame [" << lookupFrameString(target_id) << "]";
          *error_string = ss.str();
        }

        return EXTRAPOLATION_ERROR;
      }

      // Early out... source frame is a direct parent of the target frame
      if (frame == source_id)
      {
        f.finalize(SourceParentOfTarget, time);
        return NO_ERROR;
      }

      f.accum(false);

      frame = parent;

      ++depth;
      if (depth > MAX_GRAPH_DEPTH)
      {
        if (error_string)
        {
          std::stringstream ss;
          ss << "The tf tree is invalid because it contains a loop." << std::endl
             << allFramesAsString() << std::endl;
          *error_string = ss.str();
        }
        return LOOKUP_ERROR;
      }
    }

    if (frame != top_parent)
    {
      createConnectivityErrorString(source_id, target_id, error_string);
      return CONNECTIVITY_ERROR;
    }

    f.finalize(FullPath, time);

    return NO_ERROR;
  }

  bool canTransformInternal(CompactFrameID target_id, CompactFrameID source_id,
                    const tinyros::Time& time, std::string* error_msg) const
  {
    std::scoped_lock lock(frame_mutex_);
    return canTransformNoLock(target_id, source_id, time, error_msg);
  }
  
  bool canTransformNoLock(CompactFrameID target_id, CompactFrameID source_id,
                      const tinyros::Time& time, std::string* error_msg) const
  {
    if (target_id == 0 || source_id == 0)
    {
      return false;
    }

    CanTransformAccum accum;
    if (walkToTopParent(accum, time, target_id, source_id, error_msg) == NO_ERROR)
    {
      return true;
    }

    return false;
  }

  void createConnectivityErrorString(CompactFrameID source_frame, CompactFrameID target_frame, std::string* out) const
  {
    if (!out)
    {
      return;
    }
    *out = std::string("Could not find a connection between '"+lookupFrameString(target_frame)+"' and '"+
                       lookupFrameString(source_frame)+"' because they are not part of the same tree."+
                       "Tf has two or more unconnected trees.");
  }
};

// Must provide storage for non-integral static const class members.
// Otherwise you get undefined symbol errors on OS X (why not on Linux?).
// Thanks to Rob for pointing out the right way to do this.
// In C++0x this must be initialized here #5401
const double Transformer::DEFAULT_CACHE_TIME = 10.0;

}
}
#endif 
