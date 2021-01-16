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

#ifndef RVIZ_PLUGIN_MANAGER_H
#define RVIZ_PLUGIN_MANAGER_H

#include <list>

#include <memory>

class wxConfigBase;

namespace rviz
{

class Plugin;
typedef std::shared_ptr<Plugin> PluginPtr;
typedef std::list<PluginPtr> L_Plugin;

class PluginManager
{
public:
  PluginManager();
  ~PluginManager();

  PluginPtr loadPlugin(const std::string& description_file);
  PluginPtr loadDescription(const std::string& description_file);

  void loadConfig(const std::shared_ptr<wxConfigBase>& config);
  void saveConfig(const std::shared_ptr<wxConfigBase>& config);

  PluginPtr getPlugin(const std::string& description_file);
  PluginPtr getPluginByPackage(const std::string& package);
  PluginPtr getPluginByDisplayName(const std::string& display_name);
  const L_Plugin& getPlugins() const { return plugins_; };

private:
  L_Plugin plugins_;
};

}

#endif // RVIZ_PLUGIN_MANAGER_H