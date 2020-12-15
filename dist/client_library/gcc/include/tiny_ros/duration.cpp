
#include <math.h>

#ifdef WIN32
#include <windows.h>
#include <sys/timeb.h>
#else
#include <time.h>
#endif

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
#if defined(WIN32)
  HANDLE timer = NULL;
  LARGE_INTEGER sleepTime;
  sleepTime.QuadPart = -
    static_cast<int64_t>(sec)*10000000LL -
    static_cast<int64_t>(nsec) / 100LL;

  timer = CreateWaitableTimer(NULL, TRUE, NULL);
  if (timer == NULL)
  {
    return false;
  }

  if (!SetWaitableTimer (timer, &sleepTime, 0, NULL, NULL, 0))
  {
    return false;
  }

  if (WaitForSingleObject (timer, INFINITE) != WAIT_OBJECT_0)
  {
    return false;
  }
  return true;
#else
  timespec req = { sec, nsec };
  nanosleep(&req, NULL);
  return true;
#endif
}

}
