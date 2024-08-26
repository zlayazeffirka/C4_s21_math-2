#include "s21_math.h"

long double s21_ceil(double x) {
  if (x > S21_INT_MAX || x < -S21_INT_MAX || x == S21_INF || x == -S21_INF ||
      x != x) {
    return (long double)x;
  }
  long double res = (long long)x;
  int sign = 0;
  if (x < 0) {
    sign = 1;
    x *= -1;
  }
  long double fraction = x - (sign ? -res : res);
  if (fraction && !sign) {
    res += 1;
  }
  return res;
}