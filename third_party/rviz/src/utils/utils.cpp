#include "utils.h"
#include "exceptions.h"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <tiny_ros/ros.h>
  
#define MAX_SIZE (PATH_MAX+1) 

namespace rviz {
namespace utils {
  
  bool isValidCharInName(char c)
  {
    if (isalnum(c) || c == '/' || c == '_')
    {
      return true;
    }

    return false;
  }

  bool validate(const std::string& name, std::string& error)
  {
    if (name.empty())
    {
      return true;
    }

    // First element is special, can be only ~ / or alpha
    char c = name[0];
    if (!isalpha(c) && c != '/')
    {
      std::stringstream ss;
      ss << "Character [" << c << "] is not valid as the first character in Graph Resource Name [" << name << "].  Valid characters are a-z, A-Z and /.";
      error = ss.str();
      return false;
    }

    for (size_t i = 1; i < name.size(); ++i)
    {
      c = name[i];
      if (!isValidCharInName(c))
      {
        std::stringstream ss;
        ss << "Character [" << c << "] at element [" << i << "] is not valid in Graph Resource Name [" << name <<"].  Valid characters are a-z, A-Z, 0-9, / and _.";
        error = ss.str();

        return false;
      }
    }

    return true;
  }

  std::string parentNamespace(const std::string& name)
  {
    std::string error;
    if (!validate(name, error))
    {
        throw rviz::InvalidNameException(error);
    }

    if (!name.compare(""))  return "";
    if (!name.compare("/")) return "/"; 

    std::string stripped_name;

    // rstrip trailing slash
    if (name.find_last_of('/') == name.size()-1)
      stripped_name = name.substr(0, name.size() -2);
    else
      stripped_name = name;

    //pull everything up to the last /
    size_t last_pos = stripped_name.find_last_of('/');
    if (last_pos == std::string::npos)
    {
      return "";
    }
    else if (last_pos == 0)
      return "/";
    return stripped_name.substr(0, last_pos);
  }

  static std::vector<std::string> topic_string_split(const std::string& s, const std::string& delim="\n") {
    std::vector<std::string> elems;
    std::size_t pos = 0;
    std::size_t len = s.length();
    std::size_t delim_len = delim.length();
    if (delim_len == 0) return elems;
    while (pos < len) {
      std::size_t find_pos = s.find(delim, pos);
      if (find_pos < 0) {
        elems.push_back(s.substr(pos, len - pos));
        break;
      }
      elems.push_back(s.substr(pos, find_pos - pos));
      pos = find_pos + delim_len;
    }
    return elems;
  }

  bool getTopics(V_TopicInfo& topics) 
  {
    while(!tinyros::nh()->ok()) {
      sleep(1);
    }
    
    std::string topiclist = "";
    while (topiclist.empty()) {
      topiclist = tinyros::nh()->getTopicList(10*1000);
    }

    std::vector<std::string> topics = topic_string_split(topiclist);
    for (std::size_t i = 0; i < topics.size(); i++) {
      std::string elem = topics[i];
      std::size_t type_begin = elem.find("[type:");
      std::size_t type_end = elem.find(",");
      std::size_t md5_begin = elem.find("md5:");
      std::size_t md5_end = elem.find("]");
      
      if (type_begin != std::string::npos && type_end != std::string::npos
        && md5_begin != std::string::npos && md5_end != std::string::npos) {
        TopicInfo topic;
        topic.name = elem.substr(0, type_begin);
        topic.datatype = elem.substr((type_begin + 6), (type_end - type_begin - 6));
        topic.md5sum = elem.substr((md5_begin + 4), (md5_end - md5_begin - 4));
        topic.name.erase(topic.name.find_last_not_of(" \t\f\v\n\r") + 1);
        topic.name.erase(0, topic.name.find_first_not_of(" \t\f\v\n\r"));
        topic.datatype.erase(topic.datatype.find_last_not_of(" \t\f\v\n\r") + 1);
        topic.datatype.erase(0, topic.datatype.find_first_not_of(" \t\f\v\n\r"));
        topic.md5sum.erase(topic.md5sum.find_last_not_of(" \t\f\v\n\r") + 1);
        topic.md5sum.erase(0, topic.md5sum.find_first_not_of(" \t\f\v\n\r"));
        topics.push_back(topic);
      }
    }
  }

  std::string getCameraInfoTopic(const std::string& base_topic)
  {
    // Split into separate names
    std::vector<std::string> names;
    boost::algorithm::split(names, base_topic, boost::algorithm::is_any_of("/"),
                            boost::algorithm::token_compress_on);
    // Get rid of empty tokens from trailing slashes
    while (names.back().empty())
      names.pop_back();
    // Replace image name with "camera_info"
    names.back() = "camera_info";
    // Join back together into topic name
    return boost::algorithm::join(names, "/");
  }
}
}

