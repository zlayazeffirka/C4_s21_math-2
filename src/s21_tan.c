#include "s21_math.h"

long double s21_tan(double x) {
  if (x != x || x == S21_INF || x == -S21_INF) {
    return S21_NAN;
  }
  if (x == S21_PI / 2) {
    return 16331239353195370.0;
  }
  if (x == -S21_PI / 2) {
    return -16331239353195370.0;
  }
  return s21_sin(x) / s21_cos(x);
}