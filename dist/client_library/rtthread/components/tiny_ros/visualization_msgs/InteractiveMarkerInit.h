#ifndef _TINYROS_visualization_msgs_InteractiveMarkerInit_h
#define _TINYROS_visualization_msgs_InteractiveMarkerInit_h

#include <stdint.h>
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
      typedef tinyros::string _server_id_type;
      _server_id_type server_id;
      typedef uint64_t _seq_num_type;
      _seq_num_type seq_num;
      uint32_t markers_length;
      typedef tinyros::visualization_msgs::InteractiveMarker _markers_type;
      _markers_type st_markers;
      _markers_type * markers;

    InteractiveMarkerInit():
      server_id(""),
      seq_num(0),
      markers_length(0), markers(NULL)
    {
    }

    ~InteractiveMarkerInit()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(markers != NULL)
      {
        for( uint32_t i = 0; i < markers_length; i++){
          markers[i].deconstructor();
        }
        free(markers);
      }
      markers = NULL;
      markers_length = 0;
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
      *(outbuffer + offset + 0) = (this->markers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->markers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->markers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->markers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->markers_length);
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
      uint32_t markers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->markers_length);
      if(markers_lengthT > markers_length)
        this->markers = (tinyros::visualization_msgs::InteractiveMarker*)realloc(this->markers, markers_lengthT * sizeof(tinyros::visualization_msgs::InteractiveMarker));
      markers_length = markers_lengthT;
      for( uint32_t i = 0; i < markers_length; i++) {
        offset += this->st_markers.deserialize(inbuffer + offset);
        memcpy( &(this->markers[i]), &(this->st_markers), sizeof(tinyros::visualization_msgs::InteractiveMarker));
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
      length += sizeof(this->markers_length);
      for( uint32_t i = 0; i < markers_length; i++) {
        length += this->markers[i].serializedLength();
      }
      return length;
    }

    virtual tinyros::string getType(){ return "visualization_msgs/InteractiveMarkerInit"; }
    static tinyros::string getTypeStatic(){ return "visualization_msgs/InteractiveMarkerInit"; }
    virtual tinyros::string getMD5(){ return "b8259a8319519330ca4da698883a3e0e"; }
    static tinyros::string getMD5Static(){ return "b8259a8319519330ca4da698883a3e0e"; }
    virtual tinyros::string getDefinition(){ return "string server_id\nuint64 seq_num\nInteractiveMarker[] markers\n"; }
    static tinyros::string getDefinitionStatic(){ return "string server_id\nuint64 seq_num\nInteractiveMarker[] markers\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
