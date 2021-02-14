#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <tiny_ros/ros.h>
#include "tiny_ros/package.h"

namespace tinyros {
namespace package {
  std::string getPath() {
    char  current_absolute_path[PATH_MAX+1];
    int  cnt = readlink( "/proc/self/exe" , current_absolute_path, PATH_MAX+1);
    if(cnt > 0 && cnt < (PATH_MAX+1)) {
      for(int i = cnt; i >=0; --i) {
       if(current_absolute_path[i] ==  '/' ) {
          current_absolute_path[i+1] =  '\0' ;
          return std::string(current_absolute_path);
       }
      }
    }
    return "";
  }
  
  std::string getName() {
    char  current_absolute_path[PATH_MAX+1];
    int  cnt = readlink( "/proc/self/exe" , current_absolute_path, PATH_MAX+1);
    if(cnt > 0 && cnt < (PATH_MAX+1)) {
      for(int i = cnt; i >=0; --i) {
       if(current_absolute_path[i] ==  '/' ) {
          return std::string(current_absolute_path + i + 1);
       }
      }
    }
    return "";
  }
}
}

