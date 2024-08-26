#include "s21_math.h"

long double s21_asin(double x) {
  if (x != x || x == S21_INF || x == -S21_INF || x > 1 || x < -1) {
    return S21_NAN;
  }
  if (x < 0.0) {
    return -s21_asin(-x);
  }
  if (x == 0.0) {
    return x;
  }
  if (x == 1) {
    return S21_PI / 2.0;
  }

  return s21_atan(x / s21_sqrt(-x * x + 1));
}
