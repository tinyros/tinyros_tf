#ifndef _TINYROS_tinyros_hello_TinyrosHello_h
#define _TINYROS_tinyros_hello_TinyrosHello_h

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

  class TinyrosHello : public tinyros::Msg
  {
    public:
      typedef std::string _hello_type;
      _hello_type hello;

    TinyrosHello():
      hello("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_hello = this->hello.size();
      varToArr(outbuffer + offset, length_hello);
      offset += 4;
      memcpy(outbuffer + offset, this->hello.c_str(), length_hello);
      offset += length_hello;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_hello;
      arrToVar(length_hello, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_hello; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_hello-1]=0;
      this->hello = (char *)(inbuffer + offset-1);
      offset += length_hello;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_hello = this->hello.size();
      length += 4;
      length += length_hello;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::size_t hello_pos = hello.find("\"");
      while(hello_pos != std::string::npos){
        hello.replace(hello_pos, 1,"\\\"");
        hello_pos = hello.find("\"", hello_pos+2);
      }
      string_echo += "\"hello\":\"";
      string_echo += hello;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "tinyros_hello/TinyrosHello"; }
    static std::string getTypeStatic(){ return "tinyros_hello/TinyrosHello"; }
    virtual std::string getMD5(){ return "0c68e66a217802ad0c9f648b7a69d090"; }
    static std::string getMD5Static(){ return "0c68e66a217802ad0c9f648b7a69d090"; }
    virtual std::string getDefinition(){ return "string  hello\n"; }
    static std::string getDefinitionStatic(){ return "string  hello\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::tinyros_hello::TinyrosHello> Ptr;
    typedef std::shared_ptr<tinyros::tinyros_hello::TinyrosHello const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::tinyros_hello::TinyrosHello> TinyrosHelloPtr;
typedef std::shared_ptr<tinyros::tinyros_hello::TinyrosHello const> TinyrosHelloConstPtr;

}
}
#endif
