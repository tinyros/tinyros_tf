#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <mutex>
#include <yaml-cpp/yaml.h>
#include <sys/stat.h>
#include <tiny_ros/ros.h>
#include "tiny_ros/package.h"

namespace tinyros
{
namespace param
{
static std::mutex param_mutex_;
static std::string param_path_ = "";
static bool param_init_ = false;
static YAML::Node doc;

#define TINYROS_PARAM_SET_BEGIN \
  std::unique_lock<std::mutex> lock(param_mutex_); \
  if (!param_init_) { \
    tinyros_log_error("tinyros::param::set(\"%s\") params not loaded.", key.c_str()); \
    return; \
  } \
  std::ofstream fout(param_path_); \
  if (fout.fail()) { \
    tinyros_log_error("tinyros::param::set(\"%s\") file could not open %s.", key.c_str(), param_path_.c_str()); \
    return; \
  } \
  try {
#define TINYROS_PARAM_SET_END \
    fout << doc; \
    fout.close(); \
  } catch (const YAML::Exception& e) { \
    tinyros_log_error("tinyros::param::set(\"%s\"): %s", key.c_str(), e.msg.c_str()); \
  }

#define TINYROS_PARAM_GET_BEGIN \
  std::unique_lock<std::mutex> lock(param_mutex_); \
  if (!param_init_) { \
    tinyros_log_error("tinyros::param::get(\"%s\") params not loaded.", key.c_str()); \
    return false; \
  } \
  try {
#define TINYROS_PARAM_GET_END \
    return true; \
  } catch (const YAML::Exception& e) { \
    tinyros_log_error("tinyros::param::get(\"%s\"): %s", key.c_str(), e.msg.c_str()); \
    return false; \
  }

static int createDir(std::string dirname) {
  if(access(dirname.c_str(), F_OK) == 0 ) {
    return 0;
  }
  
  char* dir = strdup(dirname.c_str());
  if (!dir) {
    tinyros_log_error("%s no memory error", __FUNCTION__);
    return -1;
  }

  int i, ret = -1, len = strlen(dir);

  for(i=1; i < len; i++) {
    if(dir[i]=='/') {
      dir[i] = 0;
      if(access((const char*)dir, F_OK) != 0 ) {
        if(mkdir(dir, 0777) == -1) {
          tinyros_log_error("%s mkdir: %s", __FUNCTION__, dir);
          goto beach;
        }
      }
      dir[i] = '/';
    }
  }

  if(access((const char*)dir, F_OK) != 0 ) {
    if(mkdir(dir, 0777) == -1) {
      tinyros_log_error("%s mkdir: %s", __FUNCTION__, dir);
      goto beach;
    }
  }

  ret = 0;

beach:
  if (!dir) {
    free(dir);
  }
  return ret;
}

bool load(const std::string& path) {
  std::unique_lock<std::mutex> lock(param_mutex_);
  std::ifstream fin(path.c_str());
  if (fin.fail()) {
    std::size_t idx = path.rfind("/");
    if (idx != std::string::npos) {
      createDir(path.substr(0, idx));
    }
    std::fstream fc(path.c_str(), std::ios::out);
    tinyros_log_error("%s file could not open %s.", __FUNCTION__, path.c_str());
    return false;
  }
  
  doc = YAML::Load(fin);
  
  param_path_ = path;
  param_init_ = true;

  return true;
}

std::string getParamPath() {
  std::unique_lock<std::mutex> lock(param_mutex_);
  return param_path_;
}

void clear() {
  std::unique_lock<std::mutex> lock(param_mutex_);
  param_path_ = "";
  param_init_ = false;
}

void set(const std::string& key, const std::string& s) {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = s;
  } TINYROS_PARAM_SET_END
}

void set(const std::string& key, const char* s)  {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = s;
  } TINYROS_PARAM_SET_END
}

void set(const std::string& key, double d)  {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = d;
  } TINYROS_PARAM_SET_END
}

void set(const std::string& key, int i)  {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = i;
  } TINYROS_PARAM_SET_END
}

void set(const std::string& key, bool b)  {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = b;
  } TINYROS_PARAM_SET_END
}

void set(const std::string& key, const std::vector<std::string>& vec)  {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = vec;
  } TINYROS_PARAM_SET_END
}

void set(const std::string& key, const std::vector<double>& vec)  {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = vec;
  } TINYROS_PARAM_SET_END
}

void set(const std::string& key, const std::vector<float>& vec)  {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = vec;
  } TINYROS_PARAM_SET_END
}

void set(const std::string& key, const std::vector<int>& vec)  {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = vec;
  } TINYROS_PARAM_SET_END
}

void set(const std::string& key, const std::vector<bool>& vec)  {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = vec;
  } TINYROS_PARAM_SET_END
}

void set(const std::string& key, const std::map<std::string, std::string>& map)  {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = map;
  } TINYROS_PARAM_SET_END
}

void set(const std::string& key, const std::map<std::string, double>& map)  {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = map;
  } TINYROS_PARAM_SET_END
}

void set(const std::string& key, const std::map<std::string, float>& map)  {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = map;
  } TINYROS_PARAM_SET_END
}

void set(const std::string& key, const std::map<std::string, int>& map)  {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = map;
  } TINYROS_PARAM_SET_END
}

void set(const std::string& key, const std::map<std::string, bool>& map)  {
  TINYROS_PARAM_SET_BEGIN {
    doc[key] = map;
  } TINYROS_PARAM_SET_END
}

bool get(const std::string& key, std::string& s)  {
  TINYROS_PARAM_GET_BEGIN {
    s = doc[key].as<std::string>();
  } TINYROS_PARAM_GET_END
}

bool get(const std::string& key, double& d)  {
  TINYROS_PARAM_GET_BEGIN {
    d = doc[key].as<double>();
  } TINYROS_PARAM_GET_END
}

bool get(const std::string& key, float& f)  {
  TINYROS_PARAM_GET_BEGIN {
    f = doc[key].as<float>();
  } TINYROS_PARAM_GET_END
}

bool get(const std::string& key, int& i)  {
  TINYROS_PARAM_GET_BEGIN {
    i = doc[key].as<int>();
  } TINYROS_PARAM_GET_END
}

bool get(const std::string& key, bool& b)  {
  TINYROS_PARAM_GET_BEGIN {
    b = doc[key].as<bool>();
  } TINYROS_PARAM_GET_END
}

bool get(const std::string& key, std::vector<std::string>& vec) {
  TINYROS_PARAM_GET_BEGIN {
    vec = doc[key].as<std::vector<std::string> >();
  } TINYROS_PARAM_GET_END
}

bool get(const std::string& key, std::vector<double>& vec) {
  TINYROS_PARAM_GET_BEGIN {
    vec = doc[key].as<std::vector<double> >();
  } TINYROS_PARAM_GET_END
}
bool get(const std::string& key, std::vector<float>& vec) {
  TINYROS_PARAM_GET_BEGIN {
    vec = doc[key].as<std::vector<float> >();
  } TINYROS_PARAM_GET_END
}
bool get(const std::string& key, std::vector<int>& vec) {
  TINYROS_PARAM_GET_BEGIN {
    vec = doc[key].as<std::vector<int> >();
  } TINYROS_PARAM_GET_END
}
bool get(const std::string& key, std::vector<bool>& vec) {
  TINYROS_PARAM_GET_BEGIN {
    vec = doc[key].as<std::vector<bool> >();
  } TINYROS_PARAM_GET_END
}
bool get(const std::string& key, std::map<std::string, std::string>& map) {
  TINYROS_PARAM_GET_BEGIN {
    map = doc[key].as<std::map<std::string, std::string> >();
  } TINYROS_PARAM_GET_END
}
bool get(const std::string& key, std::map<std::string, double>& map) {
  TINYROS_PARAM_GET_BEGIN {
    map = doc[key].as<std::map<std::string, double> >();
  } TINYROS_PARAM_GET_END
}
bool get(const std::string& key, std::map<std::string, float>& map) {
  TINYROS_PARAM_GET_BEGIN {
    map = doc[key].as<std::map<std::string, float> >();
  } TINYROS_PARAM_GET_END
}
bool get(const std::string& key, std::map<std::string, int>& map) {
  TINYROS_PARAM_GET_BEGIN {
    map = doc[key].as<std::map<std::string, int> >();
  } TINYROS_PARAM_GET_END
}
bool get(const std::string& key, std::map<std::string, bool>& map) {
  TINYROS_PARAM_GET_BEGIN {
    map = doc[key].as<std::map<std::string, bool> >();
  } TINYROS_PARAM_GET_END
}
bool has(const std::string& key) {
  std::unique_lock<std::mutex> lock(param_mutex_);
  if (!param_init_) {
    tinyros_log_error("tinyros::param::has(\"%s\") params not loaded.", key.c_str());
    return false;
  }
  for (auto it = doc.begin(); it != doc.end(); it++) {
    if(it->first.as<std::string>() == key) {
      return true;
    }
  }
  return false;
}
bool del(const std::string& key) {
  std::unique_lock<std::mutex> lock(param_mutex_);
  if (!param_init_) {
    tinyros_log_error("tinyros::param::del(\"%s\") params not loaded.", key.c_str());
    return false;
  }

  try {
    doc.remove(key);
    std::ofstream fout(param_path_);
    if (fout.fail()) {
      tinyros_log_error("tinyros::param::del(\"%s\") file could not open %s.", key.c_str(), param_path_.c_str());
      return false;
    }
    fout << doc;
    return true;
  } catch (const YAML::Exception& e) { \
    tinyros_log_error("tinyros::param::del(\"%s\"): %s", key.c_str(), e.msg.c_str()); \
    return false;
  }
}

bool getParamNames(std::vector<std::string>& keys) {
  std::unique_lock<std::mutex> lock(param_mutex_);
  if (!param_init_) {
    tinyros_log_error("tinyros::param::getParamNames() params not loaded.");
    return false;
  }
  for (auto it = doc.begin(); it != doc.end(); it++) {
    keys.push_back(it->first.as<std::string>());
  }
  return true;
}

}

}

