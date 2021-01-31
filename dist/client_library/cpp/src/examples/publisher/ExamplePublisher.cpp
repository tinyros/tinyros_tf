#include "tiny_ros/ros.h"
#include "tiny_ros/tinyros_hello/TinyrosHello.h"
#include "tiny_ros/param.h"

int main (int argc, char *argv[]) {
  int count = 0;
  char buffer[50];
  bool isudp = false;
  std::string ipaddr = "127.0.0.1";
  if (argc >= 2) {
    ipaddr = argv[1];
  }
  if (argc >= 3) {
    isudp = atoi(argv[2]);
  }
  
  tinyros::init("GccExamplePublisher", ipaddr);

  std::string v;
  std::vector<std::string> vec;
  std::vector<std::string> vec1;
  std::map<std::string, std::string> map;
  std::map<std::string, int> map1;
  std::vector<std::string> keys;
  vec.push_back("1");
  vec.push_back("2");
  vec.push_back("3");
  map["map1"] = "1";
  map["map2"] = "2";
  map["map3"] = "4";
  tinyros::param::load(tinyros::package::getPath() + "param.yaml");
  tinyros::param::getParamNames(keys);
  tinyros::param::param<std::string>("test2", v, "111");
  tinyros::param::get("map", map1);
  tinyros::param::get("vec", vec1);
  tinyros::param::set("vec", vec);
  tinyros::param::set("map", map);
  //tinyros::param::del("vec");
  
  
  printf("keys: %s\n", keys[0].c_str());
  printf("v: %s\n", v.c_str());
  
  printf("vec: %s\n", vec1[0].c_str());
  printf("map1: %d\n", map1["map1"]);
  printf("has: %d\n", tinyros::param::has("map"));
  
  tinyros::Publisher hello_pub ("tinyros_hello", new tinyros::tinyros_hello::TinyrosHello());
  if (!isudp) {
    tinyros::nh()->advertise(hello_pub);
  } else {
    tinyros::udp()->advertise(hello_pub);
  }
  
  tinyros::tinyros_hello::TinyrosHello msg;
  while (true) {
    snprintf(buffer, sizeof(buffer), "%d", count++);
    msg.hello = std::string(buffer) + ": GccHello, tiny-ros ^_^";
    hello_pub.publish (&msg);
#ifdef WIN32
    Sleep(1000);
#else
    sleep(1);
#endif
  }
  return 0;
}

