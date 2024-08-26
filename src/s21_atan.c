#include "s21_math.h"

long double s21_atan(double x) {
  if (x != x) {
    return S21_NAN;
  }
  if (x == S21_INF) {
    return S21_PI / 2.0;
  }
  if (x == -S21_INF) {
    return -S21_PI / 2.0;
  }
  if (x < 0.0) {
    return -s21_atan(-x);
  }
  if (x == 0.0) {
    return x;
  }
  if (x > 1.0) {
    return S21_PI / 2.0 - s21_atan(1.0 / x);
  }
  if (x == 1.0) {
    return S21_PI / 4.0;
  }
  long double prev = (long double)x;
  long double s = prev - s21_sin(prev) * s21_cos(prev) +
                  (long double)x * s21_cos(prev) * s21_cos(prev);
  for (int i = 0; i < 1000; i++) {
    prev = s;
    s = prev - s21_sin(prev) * s21_cos(prev) +
        (long double)x * s21_cos(prev) * s21_cos(prev);
  }
  return s;
}
