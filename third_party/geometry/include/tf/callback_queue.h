/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2009, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef TINYROS_TF_CALLBACK_QUEUE_H
#define TINYROS_TF_CALLBACK_QUEUE_H

#include <stdint.h>
#include <thread>
#include <memory>
#include <list>
#include <deque>
#include <chrono>
#include <mutex>
#include "tiny_ros/tf/static_assert.h"
#include "tiny_ros/tf/callback_queue_interface.h"
#include "tiny_ros/ros/time.h"
#include "tiny_ros/tf/common.h"

namespace tinyros
{
namespace tf
{

class readWriteLock 
{ 
public: 
  readWriteLock() : read_cnt(0) 
  { 
  } 
 
  void readLock() 
  { 
    read_mtx.lock(); 
    if (++read_cnt == 1) 
      write_mtx.lock(); 
    read_mtx.unlock(); 
  } 
 
  void readUnlock() 
  { 
    read_mtx.lock(); 
    if (--read_cnt == 0) 
      write_mtx.unlock(); 
    read_mtx.unlock(); 
  } 
 
  void writeLock() 
  { 
    write_mtx.lock(); 
  } 
 
  void writeUnlock() 
  { 
    write_mtx.unlock(); 
  } 
   
private: 
  std::mutex read_mtx; 
  std::mutex write_mtx; 
  int read_cnt;
}; 

struct IDInfo
{
  uint64_t id;
  readWriteLock calling_rw_mutex;
};
typedef std::shared_ptr<IDInfo> IDInfoPtr;
typedef std::map<uint64_t, IDInfoPtr> M_IDInfo;

struct CallbackInfo
{
  CallbackInfo()
  : removal_id(0)
  , marked_for_removal(false)
  {}
  CallbackInterfacePtr callback;
  uint64_t removal_id;
  bool marked_for_removal;
};
typedef std::list<CallbackInfo> L_CallbackInfo;
typedef std::deque<CallbackInfo> D_CallbackInfo;

struct TLS
{
  TLS()
  : calling_in_this_thread(0xffffffffffffffffULL)
  , cb_it(callbacks.end())
  {}
  uint64_t calling_in_this_thread;
  D_CallbackInfo callbacks;
  D_CallbackInfo::iterator cb_it;
};

static thread_local std::shared_ptr<TLS> tls_;

/**
 * \brief This is the default implementation of the ros::CallbackQueueInterface
 */
class CallbackQueue : public CallbackQueueInterface
{
public:
  CallbackQueue(bool enabled = true)
  : calling_(0)
  , enabled_(enabled) { }
  
  virtual ~CallbackQueue()
  {
    disable();
  }

  virtual void addCallback(const CallbackInterfacePtr& callback, uint64_t removal_id = 0) 
  {
    CallbackInfo info;
    info.callback = callback;
    info.removal_id = removal_id;

    {
      std::unique_lock<std::mutex> lock(mutex_);

      if (!enabled_)
      {
        return;
      }

      callbacks_.push_back(info);
    }

    {
      std::unique_lock<std::mutex> lock(id_info_mutex_);

      M_IDInfo::iterator it = id_info_.find(removal_id);
      if (it == id_info_.end())
      {
        IDInfoPtr id_info(new IDInfo);
        id_info->id = removal_id;
        id_info_.insert(std::make_pair(removal_id, id_info));
      }
    }

    condition_.notify_one();
  }
  
  virtual void removeByID(uint64_t removal_id)
  {
    setupTLS();
  
    {
      IDInfoPtr id_info;
      {
        std::unique_lock<std::mutex> lock(id_info_mutex_);
        M_IDInfo::iterator it = id_info_.find(removal_id);
        if (it != id_info_.end())
        {
          id_info = it->second;
        }
        else
        {
          return;
        }
      }
  
      // If we're being called from within a callback from our queue, we must unlock the shared lock we already own
      // here so that we can take a unique lock.  We'll re-lock it later.
      if (tls_->calling_in_this_thread == id_info->id)
      {
        id_info->calling_rw_mutex.readUnlock();
      }
  
      {
        id_info->calling_rw_mutex.writeLock();
        std::unique_lock<std::mutex> lock(mutex_);
        D_CallbackInfo::iterator it = callbacks_.begin();
        for (; it != callbacks_.end();)
        {
          CallbackInfo& info = *it;
          if (info.removal_id == removal_id)
          {
            it = callbacks_.erase(it);
          }
          else
          {
            ++it;
          }
        }
        id_info->calling_rw_mutex.writeUnlock();
      }
  
      if (tls_->calling_in_this_thread == id_info->id)
      {
        id_info->calling_rw_mutex.readLock();
      }
    }
  
    // If we're being called from within a callback, we need to remove the callbacks that match the id that have already been
    // popped off the queue
    {
      D_CallbackInfo::iterator it = tls_->callbacks.begin();
      D_CallbackInfo::iterator end = tls_->callbacks.end();
      for (; it != end; ++it)
      {
        CallbackInfo& info = *it;
        if (info.removal_id == removal_id)
        {
          info.marked_for_removal = true;
        }
      }
    }
  
    {
      std::unique_lock<std::mutex> lock(id_info_mutex_);
      id_info_.erase(removal_id);
    }
  }

  enum CallOneResult
  {
    Called,
    TryAgain,
    Disabled,
    Empty,
  };

  /**
   * \brief Pop a single callback off the front of the queue and invoke it.  If the callback was not ready to be called,
   * pushes it back onto the queue.
   */
  CallOneResult callOne()
  {
    return callOne(tinyros::Duration());
  }

  /**
   * \brief Pop a single callback off the front of the queue and invoke it.  If the callback was not ready to be called,
   * pushes it back onto the queue.  This version includes a timeout which lets you specify the amount of time to wait for
   * a callback to be available before returning.
   *
   * \param timeout The amount of time to wait for a callback to be available.  If there is already a callback available,
   * this parameter does nothing.
   */
  CallOneResult callOne(tinyros::Duration timeout)
  {
    setupTLS();
    TLS* tls = tls_.get();

    CallbackInfo cb_info;

    {
      std::unique_lock<std::mutex> lock(mutex_);

      if (!enabled_)
      {
        return Disabled;
      }

      if (callbacks_.empty())
      {
        if (!timeout.isZero())
        {
          condition_.wait_until(lock, std::chrono::system_clock::now() + std::chrono::microseconds((int64_t)(timeout.toSec() * 1000000.0f)));
        }

        if (callbacks_.empty())
        {
          return Empty;
        }

        if (!enabled_)
        {
          return Disabled;
        }
      }

      D_CallbackInfo::iterator it = callbacks_.begin();
      for (; it != callbacks_.end();)
      {
        CallbackInfo& info = *it;

        if (info.marked_for_removal)
        {
          it = callbacks_.erase(it);
          continue;
        }

        if (info.callback->ready())
        {
          cb_info = info;
          it = callbacks_.erase(it);
          break;
        }

        ++it;
      }

      if (!cb_info.callback)
      {
        return TryAgain;
      }

      ++calling_;
    }

    bool was_empty = tls->callbacks.empty();
    tls->callbacks.push_back(cb_info);
    if (was_empty)
    {
      tls->cb_it = tls->callbacks.begin();
    }

    CallOneResult res = callOneCB(tls);
    if (res != Empty)
    {
      std::unique_lock<std::mutex> lock(mutex_);
      --calling_;
    }
    return res;
  }

  /**
   * \brief Invoke all callbacks currently in the queue.  If a callback was not ready to be called, pushes it back onto the queue.
   */
  void callAvailable()
  {
    callAvailable(tinyros::Duration());
  }
  /**
   * \brief Invoke all callbacks currently in the queue.  If a callback was not ready to be called, pushes it back onto the queue.  This version
   * includes a timeout which lets you specify the amount of time to wait for a callback to be available before returning.
   *
   * \param timeout The amount of time to wait for at least one callback to be available.  If there is already at least one callback available,
   * this parameter does nothing.
   */
  void callAvailable(tinyros::Duration timeout)
  {
    setupTLS();
    TLS* tls = tls_.get();

    {
      std::unique_lock<std::mutex> lock(mutex_);

      if (!enabled_)
      {
        return;
      }

      if (callbacks_.empty())
      {
        if (!timeout.isZero())
        {
          condition_.wait_until(lock, std::chrono::system_clock::now() + std::chrono::microseconds((int64_t)(timeout.toSec() * 1000000.0f)));
        }

        if (callbacks_.empty() || !enabled_)
        {
          return;
        }
      }

      bool was_empty = tls->callbacks.empty();

      tls->callbacks.insert(tls->callbacks.end(), callbacks_.begin(), callbacks_.end());
      callbacks_.clear();

      calling_ += tls->callbacks.size();

      if (was_empty)
      {
        tls->cb_it = tls->callbacks.begin();
      }
    }

    std::size_t called = 0;

    while (!tls->callbacks.empty())
    {
      if (callOneCB(tls) != Empty)
      {
        ++called;
      }
    }

    {
      std::unique_lock<std::mutex> lock(mutex_);
      calling_ -= called;
    }
  }

  /**
   * \brief returns whether or not the queue is empty
   */
  bool empty() { return isEmpty(); }
  /**
   * \brief returns whether or not the queue is empty
   */
  bool isEmpty()
  {
    std::unique_lock<std::mutex> lock(mutex_);

    return callbacks_.empty() && calling_ == 0;
  }
  /**
   * \brief Removes all callbacks from the queue.  Does \b not wait for calls currently in progress to finish.
   */
  void clear()
  {
    std::unique_lock<std::mutex> lock(mutex_);

    callbacks_.clear();
  }

  /**
   * \brief Enable the queue (queue is enabled by default)
   */
  void enable()
  {
    std::unique_lock<std::mutex> lock(mutex_);
    enabled_ = true;

    condition_.notify_all();
  }
  /**
   * \brief Disable the queue, meaning any calls to addCallback() will have no effect
   */
  void disable()
  {
    std::unique_lock<std::mutex> lock(mutex_);
    enabled_ = false;

    condition_.notify_all();
  }
  /**
   * \brief Returns whether or not this queue is enabled
   */
  bool isEnabled()
  {
    std::unique_lock<std::mutex> lock(mutex_);

    return enabled_;
  }

protected:
  void setupTLS()
  {
    if (!tls_.get())
    {
      tls_.reset(new TLS);
    }
  }

  CallOneResult callOneCB(TLS* tls)
  {
    // Check for a recursive call.  If recursive, increment the current iterator.  Otherwise
    // set the iterator it the beginning of the thread-local callbacks
    if (tls->calling_in_this_thread == 0xffffffffffffffffULL)
    {
      tls->cb_it = tls->callbacks.begin();
    }

    if (tls->cb_it == tls->callbacks.end())
    {
      return Empty;
    }

    TINYROS_ASSERT(!tls->callbacks.empty());
    TINYROS_ASSERT(tls->cb_it != tls->callbacks.end());

    CallbackInfo info = *tls->cb_it;
    CallbackInterfacePtr& cb = info.callback;

    IDInfoPtr id_info = getIDInfo(info.removal_id);
    if (id_info)
    {
      id_info->calling_rw_mutex.readLock();
      uint64_t last_calling = tls->calling_in_this_thread;
      tls->calling_in_this_thread = id_info->id;

      CallbackInterface::CallResult result = CallbackInterface::Invalid;
      if (info.marked_for_removal)
      {
        tls->cb_it = tls->callbacks.erase(tls->cb_it);
      }
      else
      {
        tls->cb_it = tls->callbacks.erase(tls->cb_it);
        result = cb->call();
      }

      tls->calling_in_this_thread = last_calling;

      // Push TryAgain callbacks to the back of the shared queue
      if (result == CallbackInterface::TryAgain && !info.marked_for_removal)
      {
        std::unique_lock<std::mutex> lock(mutex_);
        callbacks_.push_back(info);
        id_info->calling_rw_mutex.readUnlock();
        return TryAgain;
      }
      id_info->calling_rw_mutex.readUnlock();
      return Called;
    }
    else
    {
      tls->cb_it = tls->callbacks.erase(tls->cb_it);
    }

    return Called;
  }

  IDInfoPtr getIDInfo(uint64_t id) 
  {
    std::unique_lock<std::mutex> lock(id_info_mutex_);
    M_IDInfo::iterator it = id_info_.find(id);
    if (it != id_info_.end())
    {
      return it->second;
    }

    return IDInfoPtr();
  }
  
  D_CallbackInfo callbacks_;
  std::size_t calling_;
  std::mutex mutex_;
  std::condition_variable condition_;

  std::mutex id_info_mutex_;
  M_IDInfo id_info_;

  bool enabled_;
};
typedef std::shared_ptr<CallbackQueue> CallbackQueuePtr;

}
}
#endif
