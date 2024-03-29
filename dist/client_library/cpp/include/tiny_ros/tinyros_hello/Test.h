#ifndef _TINYROS_SERVICE_Test_h
#define _TINYROS_SERVICE_Test_h
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace tinyros_hello
{

static const char TEST[] = "tinyros_hello/Test";

  class TestRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef std::string _input_type;
      _input_type input;

    TestRequest():
      input("")
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
      uint32_t length_input = this->input.size();
      varToArr(outbuffer + offset, length_input);
      offset += 4;
      memcpy(outbuffer + offset, this->input.c_str(), length_input);
      offset += length_input;
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
      uint32_t length_input;
      arrToVar(length_input, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_input; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_input-1]=0;
      this->input = (char *)(inbuffer + offset-1);
      offset += length_input;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_input = this->input.size();
      length += 4;
      length += length_input;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::size_t input_pos = input.find("\"");
      while(input_pos != std::string::npos){
        input.replace(input_pos, 1,"\\\"");
        input_pos = input.find("\"", input_pos+2);
      }
      string_echo += "\"input\":\"";
      string_echo += input;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return TEST; }
    static std::string getTypeStatic(){ return TEST; }
    virtual std::string getMD5(){ return "26ee7a44335f1f7b55a5a7490460807d"; }
    static std::string getMD5Static(){ return "26ee7a44335f1f7b55a5a7490460807d"; }
    virtual std::string getDefinition(){ return "string input\n"; }
    static std::string getDefinitionStatic(){ return "string input\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::tinyros_hello::TestRequest> Ptr;
    typedef std::shared_ptr<tinyros::tinyros_hello::TestRequest const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::tinyros_hello::TestRequest> TestRequestPtr;
typedef std::shared_ptr<tinyros::tinyros_hello::TestRequest const> TestRequestConstPtr;

  class TestResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef std::string _output_type;
      _output_type output;

    TestResponse():
      output("")
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
      uint32_t length_output = this->output.size();
      varToArr(outbuffer + offset, length_output);
      offset += 4;
      memcpy(outbuffer + offset, this->output.c_str(), length_output);
      offset += length_output;
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
      uint32_t length_output;
      arrToVar(length_output, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_output; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_output-1]=0;
      this->output = (char *)(inbuffer + offset-1);
      offset += length_output;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_output = this->output.size();
      length += 4;
      length += length_output;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::size_t output_pos = output.find("\"");
      while(output_pos != std::string::npos){
        output.replace(output_pos, 1,"\\\"");
        output_pos = output.find("\"", output_pos+2);
      }
      string_echo += "\"output\":\"";
      string_echo += output;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return TEST; }
    static std::string getTypeStatic(){ return TEST; }
    virtual std::string getMD5(){ return "e2f6296e6ea9df7406f4fac9fb52d44b"; }
    static std::string getMD5Static(){ return "e2f6296e6ea9df7406f4fac9fb52d44b"; }
    virtual std::string getDefinition(){ return "string output\n"; }
    static std::string getDefinitionStatic(){ return "string output\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::tinyros_hello::TestResponse> Ptr;
    typedef std::shared_ptr<tinyros::tinyros_hello::TestResponse const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::tinyros_hello::TestResponse> TestResponsePtr;
typedef std::shared_ptr<tinyros::tinyros_hello::TestResponse const> TestResponseConstPtr;

  class Test {
    public:
    typedef TestRequest Request;
    typedef TestResponse Response;
  };

}
}
#endif
