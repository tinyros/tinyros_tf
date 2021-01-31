#ifndef TINYROS_SUBSCRIBER_H_
#define TINYROS_SUBSCRIBER_H_

#include "tiny_ros/tinyros_msgs/TopicInfo.h"

namespace tinyros
{

/* Base class for objects subscribers. */
class Subscriber_
{
public:
  virtual void callback(unsigned char *data) = 0;
  virtual int getEndpointType() = 0;

  // id_ is set by NodeHandle when we advertise
  uint32_t id_;

  virtual std::string getMsgType() = 0;
  virtual std::string getMsgMD5() = 0;
  virtual bool negotiated() { return negotiated_; }
  virtual void setEnabled(bool enable) { enable_ = enable; }
  std::string topic_;

  // negotiated_ is set by NodeHandle when we negotiateTopics
  bool negotiated_;
  bool srv_flag_;
  bool use_constptr_;
  bool enable_;
};

/* Bound function subscriber. */
template<typename MsgT, typename ObjT = void>
class Subscriber: public Subscriber_
{
public:
  typedef void(ObjT::*CallbackT)(const MsgT&);
  typedef void(ObjT::*CallbackT1)(const std::shared_ptr<MsgT const>&);
  MsgT msg;

  Subscriber(std::string topic_name, CallbackT cb, ObjT* obj, int endpoint = tinyros::tinyros_msgs::TopicInfo::ID_SUBSCRIBER) :
    cb_(cb),
    obj_(obj),
    endpoint_(endpoint) {
    topic_ = topic_name;
    negotiated_ = false;
    srv_flag_ = false;
    use_constptr_ = false;
    enable_ = true;
  }

  Subscriber(std::string topic_name, CallbackT1 cb, ObjT* obj, int endpoint = tinyros::tinyros_msgs::TopicInfo::ID_SUBSCRIBER) :
    cb1_(cb),
    obj_(obj),
    endpoint_(endpoint) {
    topic_ = topic_name;
    negotiated_ = false;
    srv_flag_ = false;
    use_constptr_ = true;
    enable_ = true;
  }

  virtual void callback(unsigned char* data)
  {
    if (!enable_)
      return;
    
    if (use_constptr_) 
    {
      std::shared_ptr<MsgT> tmsg = std::shared_ptr<MsgT>(new MsgT);
      tmsg->deserialize(data);
      (obj_->*cb1_)(tmsg);
    } 
    else
    {
      MsgT tmsg;
      tmsg.deserialize(data);
      (obj_->*cb_)(tmsg);
    }
  }

  virtual std::string getMsgType()
  {
    return this->msg.getType();
  }
  virtual std::string getMsgMD5()
  {
    return this->msg.getMD5();
  }
  virtual int getEndpointType()
  {
    return endpoint_;
  }

private:
  CallbackT cb_;
  CallbackT1 cb1_;
  ObjT* obj_;
  int endpoint_;
};

/* Standalone function subscriber. */
template<typename MsgT>
class Subscriber<MsgT, void>: public Subscriber_
{
public:
  typedef void(*CallbackT)(const MsgT&);
  typedef void(*CallbackT1)(const std::shared_ptr<MsgT const>&);
  MsgT msg;

  Subscriber(std::string topic_name, CallbackT cb, int endpoint = tinyros::tinyros_msgs::TopicInfo::ID_SUBSCRIBER) :
    cb_(cb),
    endpoint_(endpoint) {
    topic_ = topic_name;
    negotiated_ = false;
    srv_flag_ = false;
    use_constptr_ = false;
    enable_ = true;
  }

  Subscriber(std::string topic_name, CallbackT1 cb, int endpoint = tinyros::tinyros_msgs::TopicInfo::ID_SUBSCRIBER) :
    cb1_(cb),
    endpoint_(endpoint) {
    topic_ = topic_name;
    negotiated_ = false;
    srv_flag_ = false;
    use_constptr_ = true;
    enable_ = true;
  }

  virtual void callback(unsigned char* data)
  {
    if (!enable_)
      return;
    
    if (use_constptr_) 
    {
      std::shared_ptr<MsgT> tmsg = std::shared_ptr<MsgT>(new MsgT);
      tmsg->deserialize(data);
      this->cb1_(tmsg);
    } 
    else
    {
      MsgT tmsg;
      tmsg.deserialize(data);
      this->cb_(tmsg);
    }
  }

  virtual std::string getMsgType()
  {
    return this->msg.getType();
  }
  virtual std::string getMsgMD5()
  {
    return this->msg.getMD5();
  }
  virtual int getEndpointType()
  {
    return endpoint_;
  }

private:
  CallbackT cb_;
  CallbackT1 cb1_;
  int endpoint_;
};

}

#endif
