#ifndef _TINYROS_SERVICE_FrameGraph_h
#define _TINYROS_SERVICE_FrameGraph_h
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace tf
{

static const char FRAMEGRAPH[] = "tf/FrameGraph";

  class FrameGraphRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:

    FrameGraphRequest()
    {
      this->__id__ = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->__id__ >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->__id__ >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->__id__ >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->__id__ >> (8 * 3)) & 0xFF;
      offset += sizeof(this->__id__);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->__id__ =  ((uint32_t) (*(inbuffer + offset)));
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->__id__);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return FRAMEGRAPH; }
    static std::string getTypeStatic(){ return FRAMEGRAPH; }
    virtual std::string getMD5(){ return "d66179e20d21cee31291f40363976e1d"; }
    static std::string getMD5Static(){ return "d66179e20d21cee31291f40363976e1d"; }
    virtual std::string getDefinition(){ return ""; }
    static std::string getDefinitionStatic(){ return ""; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::tf::FrameGraphRequest> Ptr;
    typedef std::shared_ptr<tinyros::tf::FrameGraphRequest const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::tf::FrameGraphRequest> FrameGraphRequestPtr;
typedef std::shared_ptr<tinyros::tf::FrameGraphRequest const> FrameGraphRequestConstPtr;

  class FrameGraphResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef std::string _dot_graph_type;
      _dot_graph_type dot_graph;

    FrameGraphResponse():
      dot_graph("")
    {
      this->__id__ = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->__id__ >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->__id__ >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->__id__ >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->__id__ >> (8 * 3)) & 0xFF;
      offset += sizeof(this->__id__);
      uint32_t length_dot_graph = this->dot_graph.size();
      varToArr(outbuffer + offset, length_dot_graph);
      offset += 4;
      memcpy(outbuffer + offset, this->dot_graph.c_str(), length_dot_graph);
      offset += length_dot_graph;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->__id__ =  ((uint32_t) (*(inbuffer + offset)));
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->__id__);
      uint32_t length_dot_graph;
      arrToVar(length_dot_graph, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_dot_graph; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_dot_graph-1]=0;
      this->dot_graph = (char *)(inbuffer + offset-1);
      offset += length_dot_graph;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_dot_graph = this->dot_graph.size();
      length += 4;
      length += length_dot_graph;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::size_t dot_graph_pos = dot_graph.find("\"");
      while(dot_graph_pos != std::string::npos){
        dot_graph.replace(dot_graph_pos, 1,"\\\"");
        dot_graph_pos = dot_graph.find("\"", dot_graph_pos+2);
      }
      string_echo += "\"dot_graph\":\"";
      string_echo += dot_graph;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return FRAMEGRAPH; }
    static std::string getTypeStatic(){ return FRAMEGRAPH; }
    virtual std::string getMD5(){ return "8528671f80a5c0815f9700a446efbc36"; }
    static std::string getMD5Static(){ return "8528671f80a5c0815f9700a446efbc36"; }
    virtual std::string getDefinition(){ return "string dot_graph\n"; }
    static std::string getDefinitionStatic(){ return "string dot_graph\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::tf::FrameGraphResponse> Ptr;
    typedef std::shared_ptr<tinyros::tf::FrameGraphResponse const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::tf::FrameGraphResponse> FrameGraphResponsePtr;
typedef std::shared_ptr<tinyros::tf::FrameGraphResponse const> FrameGraphResponseConstPtr;

  class FrameGraph {
    public:
    typedef FrameGraphRequest Request;
    typedef FrameGraphResponse Response;
  };

}
}
#endif
