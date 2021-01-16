/*
 * Copyright (c) 2009, Willow Garage, Inc.
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

#ifndef RVIZ_THREAD_GROUP_H
#define RVIZ_THREAD_GROUP_H

#include <thread>
#include <mutex>
#include <list>
#include <memory>

namespace rviz
{
  class thread_group
  {
  private:
    thread_group(thread_group const&);
    thread_group& operator=(thread_group const&);  
  public:
    thread_group() {}
    ~thread_group()
    {
      for(auto it=threads.begin(),end=threads.end();    it!=end;++it)
      {
        delete *it;
      }
    }

    template<typename F>
    std::thread* create_thread(F threadfunc)
    {
      std::lock_guard<std::mutex> guard(m);
      std::thread* new_thread = new std::thread(threadfunc);
      threads.push_back(new_thread);
      return new_thread;
    }

    void add_thread(std::thread* thrd)
    {
      if(thrd)
      {
        std::lock_guard<std::mutex> guard(m);
        threads.push_back(thrd);
      }
    }

    void remove_thread(std::thread* thrd)
    {
      std::lock_guard<std::mutex> guard(m);
      auto it=std::find(threads.begin(),threads.end(),thrd);
      if(it!=threads.end())
      {
        threads.erase(it);
      }
    }

    void join_all()
    {
      std::lock_guard<std::mutex> guard(m);
      for(auto it=threads.begin(),end=threads.end();it!=end;++it)
      {
        (*it)->join();
      }
    }

    size_t size() const
    {
      std::lock_guard<std::mutex> guard(m);
      return threads.size();
    }

  private:
    std::list<std::thread*> threads;
    mutable std::mutex m;
  };
}

#endif

