#ifndef TINYROS_TIME_H_
#define TINYROS_TIME_H_

#include "tiny_ros/ros/duration.h"
#include <math.h>
#include <stdint.h>
#include <mutex>

namespace tinyros
{
void normalizeSecNSec(uint32_t &sec, uint32_t &nsec);
void normalizeSecNSecUnsigned(int64_t& sec, int64_t& nsec);

enum TimeType { SYS_TIME, SIM_TIME, DDS_TIME };

class Time
{
public:
  uint32_t sec, nsec;

  Time() : sec(0), nsec(0) {}
  Time(double t) { fromSec(t); }
  Time(uint32_t _sec, uint32_t _nsec) : sec(_sec), nsec(_nsec)
  {
    normalizeSecNSec(sec, nsec);
  }

  double toMSec() const
  {
    return (double)sec * 1000 + 1e-6 * (double)nsec;
  };

  double toSec() const
  {
    return (double)sec + 1e-9 * (double)nsec;
  }
  
  Time& fromSec(double t)
  {
    sec = (uint32_t) floor(t);
    nsec = (uint32_t) round((t - sec) * 1e9);
    return *this;
  }

  uint32_t toNsec()
  {
    return (uint32_t)sec * 1000000000ull + (uint32_t)nsec;
  }
  
  bool isZero() const { return sec == 0 && nsec == 0; }
  
  Time& fromNSec(int64_t t);
  Duration operator-(const Time &rhs) const;
  Time operator-(const Duration &rhs) const;
  Time operator+(const Duration &rhs) const;
  Time& operator+=(const Duration &rhs);
  Time& operator-=(const Duration &rhs);
  bool operator==(const Time &rhs) const;
  bool operator!=(const Time &rhs) const { return !((*this) == rhs); }
  bool operator<(const Time &rhs) const;
  bool operator>(const Time &rhs) const;
  bool operator<=(const Time &rhs) const;
  bool operator>=(const Time &rhs) const;

  static std::mutex mutex_;
  static int64_t time_start_;
  static int64_t time_last_;
  static int64_t time_dds_;
  static std::mutex sim_time_mutex_;
  static TimeType use_time_type_;
  static Time sim_time_;
  static Time dds();
  static Time now();
  static bool useTime(TimeType type, Time now = Time(0, 0));
};

}

#endif
