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

#ifndef TINYROS_TF_TIMER_H
#define TINYROS_TF_TIMER_H

#include "tiny_ros/tf/common.h"
#include "tiny_ros/tf/forwards.h"
#include "tiny_ros/tf/callback_queue.h"
#include "tiny_ros/tf/timer_options.h"
#include "tiny_ros/tf/timer_manager.h"

namespace tinyros
{
namespace tf
{

/**
 * \brief Manages a timer callback
 *
 * A Timer should always be created through a call to NodeHandle::createTimer(), or copied from one
 * that was. Once all copies of a specific
 * Timer go out of scope, the callback associated with that handle will stop
 * being called.
 */
class Timer
{
public:
  Timer() {}
  Timer(const Timer& rhs)
  {
    impl_ = rhs.impl_;
  }
  
  ~Timer()
  {
  }

  /**
   * \brief Start the timer.  Does nothing if the timer is already started.
   */
  void start()
  {
    if (impl_)
    {
      impl_->start();
    }
  }
  /**
   * \brief Stop the timer.  Once this call returns, no more callbacks will be called.  Does
   * nothing if the timer is already stopped.
   */
  void stop()
  {
    if (impl_)
    {
      impl_->stop();
    }
  }

  /**
   * \brief Returns whether or not the timer has any pending events to call.
   */
  bool hasPending()
  {
    if (impl_)
    {
      return impl_->hasPending();
    }

    return false;
  }

  /**
   * \brief Set the period of this timer
   */
  void setPeriod(const Duration& period)
  {
    if (impl_)
    {
      impl_->setPeriod(period);
    }
  }

  bool isValid() { return impl_ && impl_->isValid(); }
  operator void*() { return isValid() ? (void*)1 : (void*)0; }

  bool operator<(const Timer& rhs)
  {
    return impl_ < rhs.impl_;
  }

  bool operator==(const Timer& rhs)
  {
    return impl_ == rhs.impl_;
  }

  bool operator!=(const Timer& rhs)
  {
    return impl_ != rhs.impl_;
  }
  
  Timer(const TimerOptions& ops)
  : impl_(new Impl)
  {
    impl_->period_ = ops.period;
    impl_->callback_ = ops.callback;
    impl_->callback_queue_ = ops.callback_queue;
    impl_->tracked_object_ = ops.tracked_object;
    impl_->has_tracked_object_ = (ops.tracked_object != NULL);
    impl_->oneshot_ = ops.oneshot;
  }

private:
  class Impl
  {
  public:
    Impl()
    : started_(false)
    , timer_handle_(-1) { }
    
    ~Impl()
    {
      tinyros_log_debug("Timer deregistering callbacks.");
      stop();
    }

    bool isValid()
    {
      return !period_.isZero();
    }
    bool hasPending()
    {
      if (!isValid() || timer_handle_ == -1)
      {
        return false;
      }

      return TimerManager<tinyros::Time, tinyros::Duration, TimerEvent>::global().hasPending(timer_handle_);
    }
    void setPeriod(const tinyros::Duration& period)
    {
      period_ = period;
      TimerManager<tinyros::Time, tinyros::Duration, TimerEvent>::global().setPeriod(timer_handle_, period);
    }

    void start()
    {
      if (!started_)
      {
        VoidConstPtr tracked_object;
        if (has_tracked_object_)
        {
          tracked_object = tracked_object_.lock();
        }

        timer_handle_ = TimerManager<tinyros::Time, tinyros::Duration, TimerEvent>::global().add(period_, callback_, callback_queue_, tracked_object, oneshot_);
        started_ = true;
      }
    }
    void stop()
    {
      if (started_)
      {
        started_ = false;
        TimerManager<tinyros::Time, tinyros::Duration, TimerEvent>::global().remove(timer_handle_);
        timer_handle_ = -1;
      }
    }

    bool started_;
    int32_t timer_handle_;

    tinyros::Duration period_;
    TimerCallback callback_;
    CallbackQueueInterface* callback_queue_;
    VoidConstWPtr tracked_object_;
    bool has_tracked_object_;
    bool oneshot_;
  };
  typedef std::shared_ptr<Impl> ImplPtr;
  typedef std::weak_ptr<Impl> ImplWPtr;

  ImplPtr impl_;
};

}
}

#endif
