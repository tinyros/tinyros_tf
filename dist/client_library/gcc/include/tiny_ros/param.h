#ifndef TINYROS_PARAM_H
#define TINYROS_PARAM_H
#include <string>
#include <vector>
#include <map>
#include "tiny_ros/package.h"

namespace tinyros
{
namespace param
{
bool load(const std::string& path);
void clear();
std::string getParamPath();
void set(const std::string& key, const std::string& s);
void set(const std::string& key, const char* s);
void set(const std::string& key, double d);
void set(const std::string& key, int i);
void set(const std::string& key, bool b);
void set(const std::string& key, const std::vector<std::string>& vec);
void set(const std::string& key, const std::vector<double>& vec);
void set(const std::string& key, const std::vector<float>& vec);
void set(const std::string& key, const std::vector<int>& vec);
void set(const std::string& key, const std::vector<bool>& vec);
void set(const std::string& key, const std::map<std::string, std::string>& map);
void set(const std::string& key, const std::map<std::string, double>& map);
void set(const std::string& key, const std::map<std::string, float>& map);
void set(const std::string& key, const std::map<std::string, int>& map);
void set(const std::string& key, const std::map<std::string, bool>& map);
bool get(const std::string& key, std::string& s);
bool get(const std::string& key, double& d);
bool get(const std::string& key, float& f);
bool get(const std::string& key, int& i);
bool get(const std::string& key, bool& b);
bool get(const std::string& key, std::vector<std::string>& vec);
bool get(const std::string& key, std::vector<double>& vec);
bool get(const std::string& key, std::vector<float>& vec);
bool get(const std::string& key, std::vector<int>& vec);
bool get(const std::string& key, std::vector<bool>& vec);
bool get(const std::string& key, std::map<std::string, std::string>& map);
bool get(const std::string& key, std::map<std::string, double>& map);
bool get(const std::string& key, std::map<std::string, float>& map);
bool get(const std::string& key, std::map<std::string, int>& map);
bool get(const std::string& key, std::map<std::string, bool>& map);
bool has(const std::string& key);
bool del(const std::string& key);
bool getParamNames(std::vector<std::string>& keys);

template<typename T>
void param(const std::string& param_name, T& param_val, const T& default_val)
{
  if (get(param_name, param_val))
  {
    return;
  }
  param_val = default_val;
}

template<typename T>
T param(const std::string& param_name, const T& default_val)
{
  T param_val;
  param(param_name, param_val, default_val);
  return param_val;
}

}

}

#endif // TINYROS_PARAM_H
