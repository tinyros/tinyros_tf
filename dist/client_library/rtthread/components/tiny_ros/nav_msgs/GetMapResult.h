#ifndef _TINYROS_nav_msgs_GetMapResult_h
#define _TINYROS_nav_msgs_GetMapResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/nav_msgs/OccupancyGrid.h"

namespace tinyros
{
namespace nav_msgs
{

  class GetMapResult : public tinyros::Msg
  {
    public:
      typedef tinyros::nav_msgs::OccupancyGrid _map_type;
      _map_type map;

    GetMapResult():
      map()
    {
    }

    ~GetMapResult()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->map.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->map.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->map.serializedLength();
      return length;
    }

    virtual tinyros::string getType(){ return "nav_msgs/GetMapResult"; }
    static tinyros::string getTypeStatic(){ return "nav_msgs/GetMapResult"; }
    virtual tinyros::string getMD5(){ return "dd8eb0759b1a400b141d7f3238732c4d"; }
    static tinyros::string getMD5Static(){ return "dd8eb0759b1a400b141d7f3238732c4d"; }
    virtual tinyros::string getDefinition(){ return "nav_msgs/OccupancyGrid map\n"; }
    static tinyros::string getDefinitionStatic(){ return "nav_msgs/OccupancyGrid map\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
