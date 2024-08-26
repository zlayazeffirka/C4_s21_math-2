#include "s21_math.h"

long double s21_cos(double x) {
  if (x != x || x == -S21_INF || x == S21_INF) {
    return S21_NAN;
  }
  x -= 2 * S21_PI * (long)(x / (2 * S21_PI));
  if (x == S21_PI_2) {
    return 0.00000000000000006123;
  }
  if (x == -S21_PI_2) {
    return -0.00000000000000006123;
  }
  int n = 0;  // or n = 1 and factorial method
  long double an = 1.0;
  long double s = 0;
  while (s21_fabs(an) > PRECISION) {
    s += an;
    // an = (long double)pow(-1, n) * (long double)pow(x, 2 * n + 1) / (long
    // double)s21_factorial(2 * n + 1);
    n++;
    an *= (-1) * s21_pow(x, 2) / (long double)(2 * n * (2 * n - 1));
  }
  return s;
}