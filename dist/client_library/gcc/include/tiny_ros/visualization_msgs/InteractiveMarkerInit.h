#ifndef _TINYROS_visualization_msgs_InteractiveMarkerInit_h
#define _TINYROS_visualization_msgs_InteractiveMarkerInit_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/visualization_msgs/InteractiveMarker.h"

namespace tinyros
{
namespace visualization_msgs
{

  class InteractiveMarkerInit : public tinyros::Msg
  {
    public:
      typedef std::string _server_id_type;
      _server_id_type server_id;
      typedef uint64_t _seq_num_type;
      _seq_num_type seq_num;
      typedef tinyros::visualization_msgs::InteractiveMarker _markers_type;
      std::vector<_markers_type> markers;

    InteractiveMarkerInit():
      server_id(""),
      seq_num(0),
      markers(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_server_id = this->server_id.size();
      varToArr(outbuffer + offset, length_server_id);
      offset += 4;
      memcpy(outbuffer + offset, this->server_id.c_str(), length_server_id);
      offset += length_server_id;
      *(outbuffer + offset + 0) = (this->seq_num >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->seq_num >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->seq_num >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->seq_num >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->seq_num >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->seq_num >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->seq_num >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->seq_num >> (8 * 7)) & 0xFF;
      offset += sizeof(this->seq_num);
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
      uint32_t length_server_id;
      arrToVar(length_server_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_server_id; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_server_id-1]=0;
      this->server_id = (char *)(inbuffer + offset-1);
      offset += length_server_id;
      this->seq_num =  ((uint64_t) (*(inbuffer + offset)));
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->seq_num);
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
      uint32_t length_server_id = this->server_id.size();
      length += 4;
      length += length_server_id;
      length += sizeof(this->seq_num);
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
      std::size_t server_id_pos = server_id.find("\"");
      while(server_id_pos != std::string::npos){
        server_id.replace(server_id_pos, 1,"\\\"");
        server_id_pos = server_id.find("\"", server_id_pos+2);
      }
      string_echo += "\"server_id\":\"";
      string_echo += server_id;
      string_echo += "\",";
      std::stringstream ss_seq_num; ss_seq_num << "\"seq_num\":" << seq_num <<",";
      string_echo += ss_seq_num.str();
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

    virtual std::string getType(){ return "visualization_msgs/InteractiveMarkerInit"; }
    static std::string getTypeStatic(){ return "visualization_msgs/InteractiveMarkerInit"; }
    virtual std::string getMD5(){ return "b8259a8319519330ca4da698883a3e0e"; }
    static std::string getMD5Static(){ return "b8259a8319519330ca4da698883a3e0e"; }
    virtual std::string getDefinition(){ return "string server_id\nuint64 seq_num\nInteractiveMarker[] markers\n"; }
    static std::string getDefinitionStatic(){ return "string server_id\nuint64 seq_num\nInteractiveMarker[] markers\n"; }
    static bool hasHeader(){ return false; }
  };

typedef std::shared_ptr<tinyros::visualization_msgs::InteractiveMarkerInit> InteractiveMarkerInitPtr;
typedef std::shared_ptr<tinyros::visualization_msgs::InteractiveMarkerInit const> InteractiveMarkerInitConstPtr;

}
}
#endif
