#include "s21_math.h"

long double s21_fmod(double x, double y) {
  if (y == 0.0 || x != x || y != y || x == S21_INF || x == -S21_INF) {
    return S21_NAN;
  }
  if (x == 0.0 && (y < 0 || y > 0)) {
    return (long double)x;
  }
  if (y == -S21_INF || y == S21_INF) {
    return (long double)x;
  }

  long double xl = (long double)x;
  long double yl = (long double)y;
  long double fdiv = 0;
  if (x / y > 0) {
    fdiv = s21_floor(xl / yl);
  } else {
    fdiv = s21_ceil(xl / yl);
  }
  long double res = xl - fdiv * yl;
  if (res >= 0 && x < 0) {
    res += y;
  }
  return res;
}