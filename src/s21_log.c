#include "s21_math.h"

long double s21_log(double x) {
  if (x != x) {
    return S21_NAN;
  }
  if (x == S21_INF) {
    return S21_INF;
  }
  if (x < 0) {
    return S21_NAN;
  }
  long double xl = (long double)x;
  if (xl == 0) {
    return -S21_INF;
  }
  if (xl == 1) {
    return +0.0;
  }
  if (xl < 1) {
    return -s21_log(1.0 / xl);
  }
  long pow2 = 0;
  while (xl >= 2) {
    pow2++;
    xl /= 2;
  }
  long double t = (xl - 1) / (1 + xl);
  long double an = t;
  long double res = an;
  long n = 1;
  while (s21_fabs(an) >= PRECISION) {
    an *= t * t * (2 * n - 1) / (2 * n + 1);
    n++;
    res += an;
  }
  return pow2 * S21_LN2 + 2 * res;
}