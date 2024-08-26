#include "s21_math.h"

long double s21_sqrt(double x) {
  if (x == S21_INF) {
    return S21_INF;
  }
  if (x == -S21_INF || x != x || x < 0) {
    return S21_NAN;
  }
  if (x == 0.0) return 0.0;

  double result = x;
  while (1) {
    double prev = result;
    result = (prev + x / prev) / 2;

    if (prev == result) break;
  }
  return result;
}
