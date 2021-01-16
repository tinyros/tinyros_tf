#ifndef _TINYROS_visualization_msgs_MarkerArray_h
#define _TINYROS_visualization_msgs_MarkerArray_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/visualization_msgs/Marker.h"

namespace tinyros
{
namespace visualization_msgs
{

  class MarkerArray : public tinyros::Msg
  {
    public:
      typedef tinyros::visualization_msgs::Marker _markers_type;
      std::vector<_markers_type> markers;

    MarkerArray():
      markers(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t markers_length = this->markers.size();
      *(outbuffer + offset + 0) = (markers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (markers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (markers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (markers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(markers_length);
      for( uint32_t i = 0; i < markers_length; i++) {
        offset += this->markers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t markers_length = ((uint32_t) (*(inbuffer + offset))); 
      markers_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      markers_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      markers_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->markers.resize(markers_length); 
      offset += sizeof(markers_length);
      for( uint32_t i = 0; i < markers_length; i++) {
        offset += this->markers[i].deserialize(inbuffer + offset);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t markers_length = this->markers.size();
      length += sizeof(markers_length);
      for( uint32_t i = 0; i < markers_length; i++) {
        length += this->markers[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      uint32_t markers_length = this->markers.size();
      string_echo += "markers:[";
      for( uint32_t i = 0; i < markers_length; i++) {
        if( i == (markers_length - 1)) {
          string_echo += this->markers[i].echo();
          string_echo += "";
        } else {
          string_echo += this->markers[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "visualization_msgs/MarkerArray"; }
    static std::string getTypeStatic(){ return "visualization_msgs/MarkerArray"; }
    virtual std::string getMD5(){ return "032534c86d6c02fcd8eb187cf568eb46"; }
    static std::string getMD5Static(){ return "032534c86d6c02fcd8eb187cf568eb46"; }
    virtual std::string getDefinition(){ return "Marker[] markers\n"; }
    static std::string getDefinitionStatic(){ return "Marker[] markers\n"; }
    static bool hasHeader(){ return false; }
  };

typedef std::shared_ptr<tinyros::visualization_msgs::MarkerArray> MarkerArrayPtr;
typedef std::shared_ptr<tinyros::visualization_msgs::MarkerArray const> MarkerArrayConstPtr;

}
}
#endif
