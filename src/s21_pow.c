#include "s21_math.h"

long double s21_int_pow(double a, long long b) {
  long double res = a;
  if (b == 0) {
    return 1;
  }
  if (b == 1) {
    res = a;
  } else if (b % 2) {
    res = a * s21_int_pow(a, b - 1);
  } else if (res != 0) {
    res = s21_int_pow(a * a, b / 2);
  }
  return res;
}

long double s21_pow(double a, double b) {
  if (a < 0 && s21_floor(b) != b && a != -S21_INF && b != S21_INF &&
      b != -S21_INF) {
    return S21_NAN;
  }
  if (b == 0.0 || a == 1.0) {
    return 1.0;
  }
  if (a != a || b != b) {
    return S21_NAN;
  }
  if (a == 0.0 && b > 0.0 && s21_floor(b) == b &&
      s21_fabs(s21_fmod(b, 2.0)) >= S21_EPS) {
    return a;
  }
  if (a == 0.0 && b > 0.0 &&
      !(s21_floor(b) == b && s21_fabs(s21_fmod(b, 2.0)) >= S21_EPS)) {
    return +0.0;
  }
  if (a == -1.0 && (b == S21_INF || b == -S21_INF)) {
    return 1.0;
  }
  if (s21_fabs(a) < 1.0 && b == -S21_INF) {
    return S21_INF;
  }
  if ((s21_fabs(a) > 1.0 && b == -S21_INF) ||
      (s21_fabs(a) < 1.0 && b == S21_INF)) {
    return +0.0;
  }
  if (s21_fabs(a) > 1.0 && b == S21_INF) {
    return S21_INF;
  }
  if (a == -S21_INF && b < 0.0 && s21_floor(b) == b &&
      s21_fabs(s21_fmod(b, 2.0)) >= S21_EPS) {
    return -0.0;
  }
  if (a == -S21_INF && b < 0.0 &&
      !(s21_floor(b) == b && s21_fabs(s21_fmod(b, 2.0)) >= S21_EPS)) {
    return +0.0;
  }
  if (a == -S21_INF && b > 0.0 && s21_floor(b) == b &&
      s21_fabs(s21_fmod(b, 2.0)) >= S21_EPS) {
    return -S21_INF;
  }
  if (a == -S21_INF && b > 0.0 &&
      !(s21_floor(b) == b && s21_fabs(s21_fmod(b, 2.0)) >= S21_EPS)) {
    return S21_INF;
  }
  if (a == S21_INF && b < 0) {
    return +0.0;
  }
  if (a == S21_INF && b > 0) {
    return S21_INF;
  }
  if ((a == 0.0 && 1.0 / a > 0 && b < 0.0 && s21_floor(b) == b &&
       s21_fabs(s21_fmod(b, 2.0)) >= S21_EPS) ||
      (a == 0 && b < 0.0 &&
       !(s21_floor(b) == b && s21_fabs(s21_fmod(b, 2.0)) >= S21_EPS))) {
    return S21_INF;
  }
  if (a == 0.0 && 1.0 / a < 0 && b < 0.0 && s21_floor(b) == b &&
      s21_fabs(s21_fmod(b, 2.0)) >= S21_EPS) {
    return -S21_INF;
  }

  long double res = 0;
  int sign = 0;
  if (a < 0) {
    sign = 1;
    a *= -1;
  }
  if (b < 0) {
    res = 1 / s21_pow(a, -1 * b);
  } else {
    long double int_b = s21_floor(b);
    res = s21_exp((b - int_b) * s21_log(a)) * s21_int_pow(a, (long long)int_b);
  }
  if (s21_floor(b) == b && s21_fabs(s21_fmod(b, 2.0)) >= S21_EPS && sign) {
    res *= -1;
  }
  return res;
}