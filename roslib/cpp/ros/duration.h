#ifndef _TINYROS_DURATION_H_
#define _TINYROS_DURATION_H_

#include <math.h>
#include <stdint.h>

namespace tinyros
{

void normalizeSecNSecSigned(int32_t& sec, int32_t& nsec);

class Duration
{
public:
  int32_t sec, nsec;

  Duration() : sec(0), nsec(0) {}
  Duration(double t) { fromSec(t); }
  Duration(int32_t _sec, int32_t _nsec) : sec(_sec), nsec(_nsec)
  {
    normalizeSecNSecSigned(sec, nsec);
  }

  double toSec() const
  {
    return (double)sec + 1e-9 * (double)nsec;
  }
  
  Duration& fromSec(double t)
  {
    sec = (int32_t) floor(t);
    nsec = (int32_t) ((t - (double)sec) * 1e9);
    return *this;
  }

  Duration& fromNSec(int64_t t)
  {
    sec  = (int32_t)(t / 1000000000);
    nsec = (int32_t)(t % 1000000000);

    normalizeSecNSecSigned(sec, nsec);

    return *this;
  }
  
  Duration operator+(const Duration &rhs) const;
  Duration operator*(double scale) const;
  Duration operator-(const Duration &rhs) const;
  Duration operator-() const;
  Duration& operator+=(const Duration &rhs);
  Duration& operator-=(const Duration &rhs);
  Duration& operator*=(double scale);
  bool operator==(const Duration &rhs) const;
  bool operator!=(const Duration &rhs) const { return !((*this) == rhs); }
  bool operator<(const Duration &rhs) const;
  bool operator>(const Duration &rhs) const;
  bool operator<=(const Duration &rhs) const;
  bool operator>=(const Duration &rhs) const;
  bool isZero() const;
  bool sleep() const;
};

}

#endif

