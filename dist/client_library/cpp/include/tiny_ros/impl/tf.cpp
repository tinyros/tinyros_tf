#include "tiny_ros/tf/tf.h"

namespace tinyros
{
namespace tf
{
  const double Transformer::DEFAULT_CACHE_TIME = 10.0;
  const unsigned int Transformer::MAX_GRAPH_DEPTH = 100UL;
  const int64_t Transformer::DEFAULT_MAX_EXTRAPOLATION_DISTANCE = 0ULL;

  const int TimeCache::MIN_INTERPOLATION_DISTANCE = 5; //!< Number of nano-seconds to not interpolate below.
  const unsigned int TimeCache::MAX_LENGTH_LINKED_LIST = 1000000; //!< Maximum length of linked list, to make sure not to be able to use unlimited memory.
  const double TimeCache::DEFAULT_MAX_STORAGE_TIME = 10.0; //!< default value of 10 seconds storage

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

  /** \brief Throw InvalidArgument if quaternion is malformed */
  void assertQuaternionValid(const tf::Quaternion & q)
  {
    if(std::fabs(q.x()*q.x() + q.y()*q.y() + q.z()*q.z() + q.w()*q.w() - 1) > 0.01)
    {
      std::stringstream ss;
      ss << "Quaternion malformed, magnitude: " << q.x()*q.x() + q.y()*q.y() + q.z()*q.z() + q.w()*q.w() << " should be 1.0" <<std::endl;
      throw tinyros::tf::InvalidArgument(ss.str());
    }  //  TINYROS_ASSERT(std::fabs(q.x()*q.x() + q.y()*q.y() + q.z*q.z() + q.w()*q.w() - 1 < 0.01));
  }

  /** \brief Throw InvalidArgument if quaternion is malformed */
  void assertQuaternionValid(const tinyros::geometry_msgs::Quaternion & q)
  {
    if(std::fabs(q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w - 1) > 0.01)
    {
      std::stringstream ss;
      ss << "Quaternion malformed, magnitude: " << q.x*q.x + q.y*q.y + q.z*q.z + q.w*q.w << " should be 1.0" <<std::endl;
      throw tinyros::tf::InvalidArgument(ss.str());
    }  //  TINYROS_ASSERT(std::fabs(q.x()*q.x() + q.y()*q.y() + q.z*q.z() + q.w()*q.w() - 1 < 0.01));
  }

}
}

