#include <math.h>
#include <rtthread.h>
#include "tiny_ros/ros/duration.h"

namespace tinyros
{
void normalizeSecNSecSigned(int32_t &sec, int32_t &nsec)
{
  int32_t nsec_part = nsec;
  int32_t sec_part = sec;

  while (nsec_part > 1000000000L)
  {
    nsec_part -= 1000000000L;
    ++sec_part;
  }
  while (nsec_part < 0)
  {
    nsec_part += 1000000000L;
    --sec_part;
  }
  sec = sec_part;
  nsec = nsec_part;
}

Duration Duration::operator+(const Duration &rhs) const
{
  return Duration(sec + rhs.sec, nsec + rhs.nsec);
}

Duration Duration::operator*(double scale) const
{
  return Duration(toSec() * scale);
}

Duration Duration::operator-(const Duration &rhs) const
{
  return Duration(sec - rhs.sec, nsec - rhs.nsec);
}

Duration Duration::operator-() const
{
  return Duration(-sec, -nsec);
}

Duration& Duration::operator+=(const Duration &rhs)
{
  sec += rhs.sec;
  nsec += rhs.nsec;
  normalizeSecNSecSigned(sec, nsec);
  return *this;
}

Duration& Duration::operator-=(const Duration &rhs)
{
  sec += -rhs.sec;
  nsec += -rhs.nsec;
  normalizeSecNSecSigned(sec, nsec);
  return *this;
}

Duration& Duration::operator*=(double scale)
{
  fromSec(toSec() * scale);
  return *this;
}

bool Duration::operator==(const Duration &rhs) const {
  sec == rhs.sec && nsec == rhs.nsec;
}

bool Duration::operator<(const Duration &rhs) const {
  if (sec < rhs.sec)
    return true;
  else if (sec == rhs.sec && nsec < rhs.nsec)
    return true;
  return false;
}

bool Duration::operator>(const Duration &rhs) const {
  if (sec > rhs.sec)
    return true;
  else if (sec == rhs.sec && nsec > rhs.nsec)
    return true;
  return false;
}

bool Duration::operator<=(const Duration &rhs) const {
  if (sec < rhs.sec)
    return true;
  else if (sec == rhs.sec && nsec <= rhs.nsec)
    return true;
  return false;
}

bool Duration::operator>=(const Duration &rhs) const {
  if (sec > rhs.sec)
    return true;
  else if (sec == rhs.sec && nsec >= rhs.nsec)
    return true;
  return false;
}

bool Duration::isZero() const
{
  return sec == 0 && nsec == 0;
}

bool Duration::sleep() const {
  rt_thread_delay(sec*1000 + nsec/1000000);
}
}

