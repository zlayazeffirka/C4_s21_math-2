#include "s21_math.h"

long double s21_acos(double x) {
  if (x != x || x == S21_INF || x == -S21_INF || x > 1 || x < -1) {
    return S21_NAN;
  }
  return S21_PI / 2.0 - s21_asin(x);
}
