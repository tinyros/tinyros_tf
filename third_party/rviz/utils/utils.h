#ifndef RVIZ_UTILS_H_
#define RVIZ_UTILS_H_
#include <string>
#include <math.h>
#include <assert.h>
#include <set>
#include <sstream>
#include <tiny_ros/tf/Quaternion.h>
#include <tiny_ros/tf/Matrix3x3.h>
#include <tiny_ros/visualization_msgs/InteractiveMarker.h>

namespace rviz {
namespace utils {
  struct TopicInfo
  {
    TopicInfo() {}
    TopicInfo(const std::string& _name, const std::string& _datatype , const std::string& _md5sum)
    : name(_name)
    , datatype(_datatype)
    , md5sum(_md5sum)
    {}
    std::string name;        ///< Name of the topic
    std::string datatype;    ///< Datatype of the topic
    std::string md5sum;      ///< md5sum of the topic
  };
  typedef std::vector<TopicInfo> V_TopicInfo;
  
  bool getTopics(V_TopicInfo& topics);
  bool isValidCharInName(char c);
  bool validate(const std::string& name, std::string& error);
  std::string parentNamespace(const std::string& name);
  std::string getCameraInfoTopic(const std::string& base_topic);
}
}

#endif

