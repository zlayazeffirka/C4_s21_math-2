#include "s21_math.h"

long double s21_fabs(double x) {
  long double res = (long double)x;
  if (res < 0 || (res == 0 && 1.0 / res < 0)) {
    res *= -1;
  }
  return res;
}