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

#ifndef TINYROS_TF_TIME_CACHE_H
#define TINYROS_TF_TIME_CACHE_H
#include <set>
#include <mutex>
#include "tiny_ros/tf/transform_datatypes.h"
#include "tiny_ros/tf/static_assert.h"
#include "tiny_ros/tf/exceptions.h"
#include "tiny_ros/tf/Transform.h"
#include <sstream>

namespace tinyros
{
namespace tf
{
enum ExtrapolationMode {  ONE_VALUE, INTERPOLATE, EXTRAPOLATE_BACK, EXTRAPOLATE_FORWARD };


typedef uint32_t CompactFrameID;
typedef std::pair<tinyros::Time, CompactFrameID> P_TimeAndFrameID;

/** \brief Storage for transforms and their parent */
class TransformStorage
{
public:
  TransformStorage() {}
  TransformStorage(const StampedTransform& data, CompactFrameID frame_id, CompactFrameID child_frame_id)
  : rotation_(data.getRotation())
  , translation_(data.getOrigin())
  , stamp_(data.stamp_)
  , frame_id_(frame_id)
  , child_frame_id_(child_frame_id)
  { }

  TransformStorage(const TransformStorage& rhs)
  {
    *this = rhs;
  }

  TransformStorage& operator=(const TransformStorage& rhs)
  {
#if 01
    rotation_ = rhs.rotation_;
    translation_ = rhs.translation_;
    stamp_ = rhs.stamp_;
    frame_id_ = rhs.frame_id_;
    child_frame_id_ = rhs.child_frame_id_;
#endif
    return *this;
  }

  bool operator< (const TransformStorage &b) const
  {
    return this->stamp_ < b.stamp_;
  }


  tinyros::tf::Quaternion rotation_;
  tinyros::tf::Vector3 translation_;
  tinyros::Time stamp_;
  CompactFrameID frame_id_;
  CompactFrameID child_frame_id_;
};




/** \brief A class to keep a sorted linked list in time
 * This builds and maintains a list of timestamped
 * data.  And provides lookup functions to get
 * data out as a function of time. */
class TimeCache
{
 public:
  static const int MIN_INTERPOLATION_DISTANCE; //!< Number of nano-seconds to not interpolate below.
  static const unsigned int MAX_LENGTH_LINKED_LIST; //!< Maximum length of linked list, to make sure not to be able to use unlimited memory.
  static const double DEFAULT_MAX_STORAGE_TIME; //!< default value of 10 seconds storage

  TimeCache(tinyros::Duration max_storage_time = tinyros::Duration(DEFAULT_MAX_STORAGE_TIME))
  : max_storage_time_(max_storage_time) {}

  bool getData(tinyros::Time time, TransformStorage & data_out, std::string* error_str = 0)
  {
    const TransformStorage* p_temp_1 = NULL;
    const TransformStorage* p_temp_2 = NULL;

    int num_nodes = findClosest(p_temp_1, p_temp_2, time, error_str);
    if (num_nodes == 0)
    {
      return false;
    }
    else if (num_nodes == 1)
    {
      data_out = *p_temp_1;
    }
    else if (num_nodes == 2)
    {
      if( p_temp_1->frame_id_ == p_temp_2->frame_id_)
      {
        interpolate(*p_temp_1, *p_temp_2, time, data_out);
      }
      else
      {
        data_out = *p_temp_1;
      }
    }
    else
    {
      TINYROS_BREAK();
    }

    return true;
  }
  bool insertData(const TransformStorage& new_data)
  {
    if (storage_.begin() != storage_.end())
    {
      // trying to add data that dates back longer than we want to keep history
      if (storage_.rbegin()->stamp_ > new_data.stamp_ + max_storage_time_) {
        tinyros_log_warn("Trying to add data that dates back longer than we want to keep history");
        return false;
      }

      // if we already have data at that exact time, delete it to ensure the latest data is stored
      if (storage_.rbegin()->stamp_ >= new_data.stamp_)
      {
        L_TransformStorage::iterator storage_it  = storage_.find(new_data);
        if (storage_it != storage_.end()) {
          tinyros_log_warn("Already have data at that exact time, delete it to ensure the latest data is stored");
          storage_.erase(storage_it);
        }
      }
    }

    storage_.insert(storage_.end(), new_data);

    pruneList();

    return true;
  }
  void clearList()
  {
    storage_.clear();
  }
  CompactFrameID getParent(tinyros::Time time, std::string* error_str)
  {
    const TransformStorage* p_temp_1 = NULL;
    const TransformStorage* p_temp_2 = NULL;

    int num_nodes = findClosest(p_temp_1, p_temp_2, time, error_str);
    if (num_nodes == 0)
    {
      return 0;
    }

    return p_temp_1->frame_id_;
  }
  P_TimeAndFrameID getLatestTimeAndParent()
  {
    if (storage_.empty())
    {
      return std::make_pair(tinyros::Time(), 0);
    }

    const TransformStorage& ts = *storage_.rbegin();
    return std::make_pair(ts.stamp_, ts.frame_id_);
  }

  /// Debugging information methods
  unsigned int getListLength()
  {
    return storage_.size();
  }
  tinyros::Time getLatestTimestamp()
  {
    if (storage_.empty()) return tinyros::Time(); //empty list case
    return storage_.rbegin()->stamp_;
  }
  tinyros::Time getOldestTimestamp()
  {
    if (storage_.empty()) return tinyros::Time(); //empty list case
    return storage_.begin()->stamp_;
  }

  // hoisting these into separate functions causes an ~8% speedup.  Removing calling them altogether adds another ~10%
  void createEmptyException(std::string *error_str)
  {
    if (error_str)
    {
      *error_str = "Unable to lookup transform, cache is empty";
    }
  }

  void createExtrapolationException1(tinyros::Time t0, tinyros::Time t1, std::string* error_str)
  {
    if (error_str)
    {
      std::stringstream ss;
      ss << "Lookup would require extrapolation at time " << t0.sec << "." << t0.nsec << ", but only time " << t1.sec << "." << t1.nsec << " is in the buffer";
      *error_str = ss.str();
    }
  }

  void createExtrapolationException2(tinyros::Time t0, tinyros::Time t1, std::string* error_str)
  {
    if (error_str)
    {
      std::stringstream ss;
      ss << "Lookup would require extrapolation into the future.  Requested time " << t0.sec << "." << t0.nsec << " but the latest data is at time " << t1.sec << "." << t1.nsec;
      *error_str = ss.str();
    }
  }

  void createExtrapolationException3(tinyros::Time t0, tinyros::Time t1, std::string* error_str)
  {
    if (error_str)
    {
      std::stringstream ss;
      ss << "Lookup would require extrapolation into the past.  Requested time " << t0.sec << "." << t0.nsec << " but the earliest data is at time " << t1.sec << "." << t1.nsec;
      *error_str = ss.str();
    }
  }

private:
  typedef std::set<TransformStorage> L_TransformStorage;
  L_TransformStorage storage_;

  tinyros::Duration max_storage_time_;


  /// A helper function for getData
  //Assumes storage is already locked for it
  inline uint8_t findClosest(const TransformStorage*& one, const TransformStorage*& two, tinyros::Time target_time, std::string* error_str)
  {
    //No values stored
    if (storage_.empty())
    {
      createEmptyException(error_str);
      return 0;
    }

    //If time == 0 return the latest
    if (target_time.isZero())
    {
      one = &(*storage_.rbegin());
      return 1;
    }

    // One value stored
    if (++storage_.begin() == storage_.end())
    {
      const TransformStorage& ts = *storage_.begin();
      if (ts.stamp_ == target_time)
      {
        one = &ts;
        return 1;
      }
      else
      {
        createExtrapolationException1(target_time, ts.stamp_, error_str);
        return 0;
      }
    }

    tinyros::Time latest_time = (*storage_.rbegin()).stamp_;
    tinyros::Time earliest_time = (*(storage_.begin())).stamp_;

    if (target_time == latest_time)
    {
      one = &(*storage_.rbegin());
      return 1;
    }
    else if (target_time == earliest_time)
    {
      one = &(*storage_.begin());
      return 1;
    }
    // Catch cases that would require extrapolation
    else if (target_time > latest_time)
    {
      createExtrapolationException2(target_time, latest_time, error_str);
      return 0;
    }
    else if (target_time < earliest_time)
    {
      createExtrapolationException3(target_time, earliest_time, error_str);
      return 0;
    }

    //Create a temporary object to compare to when searching the lower bound via std::set
    TransformStorage tmp;
    tmp.stamp_ = target_time;

    //Find the first value equal or higher than the target value
    L_TransformStorage::iterator storage_it = storage_.upper_bound(tmp);

    //Finally the case were somewhere in the middle  Guarenteed no extrapolation :-)
    two = &*(storage_it); //Newer
    one = &*(--storage_it); //Older

    return 2;

  }

  inline void interpolate(const TransformStorage& one, const TransformStorage& two, tinyros::Time time, TransformStorage& output)
  {
    // Check for zero distance case
    if( two.stamp_ == one.stamp_ )
    {
      output = two;
      return;
    }
    //Calculate the ratio
    tfScalar ratio = (time.toSec() - one.stamp_.toSec()) / (two.stamp_.toSec() - one.stamp_.toSec());

    //Interpolate translation
    output.translation_.setInterpolate3(one.translation_, two.translation_, ratio);

    //Interpolate rotation
    output.rotation_ = slerp( one.rotation_, two.rotation_, ratio);

    output.stamp_ = one.stamp_;
    output.frame_id_ = one.frame_id_;
    output.child_frame_id_ = one.child_frame_id_;
  }

  void pruneList()
  {
    tinyros::Time latest_time = storage_.rbegin()->stamp_;
  
    while(!storage_.empty() && storage_.begin()->stamp_ + max_storage_time_ < latest_time)
    {
      storage_.erase(storage_.begin());
    }
  }
};

const int TimeCache::MIN_INTERPOLATION_DISTANCE = 5; //!< Number of nano-seconds to not interpolate below.
const unsigned int TimeCache::MAX_LENGTH_LINKED_LIST = 1000000; //!< Maximum length of linked list, to make sure not to be able to use unlimited memory.
const double TimeCache::DEFAULT_MAX_STORAGE_TIME = 10.0; //!< default value of 10 seconds storage

}
}
#endif
