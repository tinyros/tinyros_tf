/*********************************************************************
* Software License Agreement (BSD License)
* 
*  Copyright (c) 2008, Willow Garage, Inc.
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
*   * Neither the name of the Willow Garage nor the names of its
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
*********************************************************************/

/* Author: Wim Meeussen */

#include "model.h"
#include "parser.h"

#include <tiny_ros/ros.h>
#include <tiny_ros/param.h>

/* we include the default parser for plain URDF files; 
   other parsers are loaded via plugins (if available) */
#include <urdf_parser/urdf_parser.h>
#include <tiny_ros/pluginlib/class_loader.h>

#include <boost/algorithm/string.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/thread.hpp>

#include <vector>
#include <fstream>
#include <iostream>

namespace urdf{

static bool IsColladaData(const std::string& data)
{
  return data.find("<COLLADA") != std::string::npos;
}


bool Model::initFile(const std::string& filename)
{

  // get the entire file
  std::string xml_string;
  std::fstream xml_file(filename.c_str(), std::fstream::in);
  if (xml_file.is_open())
  {
    while ( xml_file.good() )
    {
      std::string line;
      std::getline( xml_file, line);
      xml_string += (line + "\n");
    }
    xml_file.close();
    return Model::initString(xml_string);
  }
  else
  {
    tinyros_log_error("Could not open file [%s] for parsing.",filename.c_str());
    return false;
  }

}


bool Model::initParam(const std::string& param)
{
  return initParamWithNodeHandle(param);
}

bool Model::initParamWithNodeHandle(const std::string& param)
{
  std::string xml_string;
  // read the robot description from the parameter server
  if (!tinyros::param::get(param, xml_string)){
    tinyros_log_error("Could not read parameter %s on parameter server", param.c_str());
    return false;
  }
  return Model::initString(xml_string);
}

bool Model::initXml(TiXmlDocument *xml_doc)
{
  if (!xml_doc)
  {
    tinyros_log_error("Could not parse the xml document");
    return false;
  }

  std::stringstream ss;
  ss << *xml_doc;

  return Model::initString(ss.str());
}

bool Model::initXml(TiXmlElement *robot_xml)
{
  if (!robot_xml)
  {
    tinyros_log_error("Could not parse the xml element");
    return false;
  }

  std::stringstream ss;
  ss << (*robot_xml);

  return Model::initString(ss.str());
}

bool Model::initString(const std::string& xml_string)
{
  urdf::ModelInterfaceSharedPtr model;

  // necessary for COLLADA compatibility
  if( IsColladaData(xml_string) ) {
    tinyros_log_debug("Parsing robot collada xml string");

    static boost::mutex PARSER_PLUGIN_LOCK;
    static boost::scoped_ptr<pluginlib::ClassLoader<urdf::URDFParser> > PARSER_PLUGIN_LOADER;
    boost::mutex::scoped_lock _(PARSER_PLUGIN_LOCK);

    try
    {
      if (!PARSER_PLUGIN_LOADER)
        PARSER_PLUGIN_LOADER.reset(new pluginlib::ClassLoader<urdf::URDFParser>("urdf_parser_plugin", "urdf::URDFParser", "plugin_description.xml"));
      const std::vector<std::string> &classes = PARSER_PLUGIN_LOADER->getDeclaredClasses();
      bool found = false;
      for (std::size_t i = 0 ; i < classes.size() ; ++i)
      if (classes[i].find("urdf/ColladaURDFParser") != std::string::npos)
      {
        boost::shared_ptr<urdf::URDFParser> instance = PARSER_PLUGIN_LOADER->createInstance(classes[i]);
        if (instance)
          model = instance->parse(xml_string);
        found = true;
        break;
      }
      if (!found)
        tinyros_log_error("No URDF parser plugin found for Collada files. Did you install the corresponding package?");
    }
    catch(pluginlib::PluginlibException& ex)
    {
      tinyros_log_error("Exception while creating planning plugin loader %s. Will not parse Collada file.", ex.what());
    }
  }
  else {
    tinyros_log_debug("Parsing robot urdf xml string");
    model = parseURDF(xml_string);
  }

  // copy data from model into this object
  if (model){
    this->links_ = model->links_;
    this->joints_ = model->joints_;
    this->materials_ = model->materials_;
    this->name_ = model->name_;
    this->root_link_ = model->root_link_;
    return true;
  }
  return false;
}



}// namespace
