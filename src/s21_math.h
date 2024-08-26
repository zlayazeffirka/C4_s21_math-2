#ifndef S21_MATH_H
#define S21_MATH_H

#define S21_E 2.7182818284590452354
#define S21_EPS 0.000001L
#define S21_NAN 0.0 / 0.0
#define S21_PI 3.14159265358979323846
#define S21_PI_2 1.57079632679489661923
#define PRECISION 1e-30
#define S21_INF 1.0 / 0.0
#define S21_LN2 0.69314718055994530942
#define S21_DBL_MAX 1.7976931348623158e+308
#define S21_INT_MAX 9223372036854775807.0

int s21_abs(int x);
long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_pow(double x, double y);
long double s21_int_pow(double base, long long exp);
long double s21_fmod(double x, double y);
long double s21_exp(double x);
unsigned long long s21_factorial(int n);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_log(double x);
long double s21_sqrt(double x);

#endif
