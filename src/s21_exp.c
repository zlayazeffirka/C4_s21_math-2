#include "s21_math.h"

long double s21_exp(double x) {
  if (x != x) {
    return S21_NAN;
  }
  if (x == S21_INF) {
    return S21_INF;
  }
  if (x == -S21_INF) {
    return +0.0;
  }
  if (x < 0) {
    return 1 / s21_exp(-1 * x);
  }

  long double res = 1.0, fact = 1.0, sm = 1.0;
  int i = 0;
  while (s21_fabs(sm) > PRECISION) {
    i++;
    long double numer = 1.0;
    for (int j = 0; j < i; j++) {
      numer *= x;
    }
    fact *= i;
    sm = numer / fact;
    res += sm;
    if (res == S21_INF) {
      return S21_INF;
    }
  }
  return res;
}