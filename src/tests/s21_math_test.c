#include "../s21_math.h"

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*  ck_assert_ldouble_eq_tol Check two double precision floating point numbers
 to determine if X≈Y with specified tolerance
 If not X ≈ Y with error < T, the test fails.  */

START_TEST(abs_1) {
  int a = 2147483647;
  ck_assert_int_eq(abs(a), s21_abs(a));
}
END_TEST

START_TEST(abs_2) {
  int a = -2147483648;
  ck_assert_int_eq(abs(a), s21_abs(a));
}

START_TEST(abs_3) {
  int a = 0;
  ck_assert_int_eq(abs(a), s21_abs(a));
}
END_TEST

START_TEST(sqrt_0) {
  ck_assert_ldouble_eq_tol(sqrt(0), s21_sqrt(0), S21_EPS);
  ck_assert_ldouble_eq_tol(sqrt(4), s21_sqrt(4), S21_EPS);
  ck_assert_ldouble_nan(s21_sqrt(-4));
  ck_assert_ldouble_eq_tol(sqrt(-0), s21_sqrt(-0), S21_EPS);
  ck_assert_ldouble_nan(sqrt(-4));
}
END_TEST

START_TEST(pow_1) {
  double base = 0;
  double exp = 0;
  ck_assert_ldouble_eq(pow(base, exp), s21_pow(base, exp));
}
END_TEST

START_TEST(pow_2) {
  double base = -2;
  double exp = 0.3;
  ck_assert_ldouble_nan(pow(base, exp));
  ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_3) {
  double base = 0;
  double exp = -123;
  ck_assert_ldouble_infinite(pow(base, exp));
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_4) {
  double base = S21_NAN;
  double exp = -123;
  ck_assert_ldouble_nan(pow(base, exp));
  ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_5) {
  double base = 12;
  double exp = S21_NAN;
  ck_assert_ldouble_nan(pow(base, exp));
  ck_assert_ldouble_nan(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_6) {
  double base = S21_INF;
  double exp = 20000;
  ck_assert_ldouble_infinite(pow(base, exp));
  ck_assert_ldouble_infinite(s21_pow(base, exp));
}
END_TEST

START_TEST(pow_7) {
  double base = 12;
  double exp = -S21_INF;
  ck_assert_ldouble_eq(pow(base, exp), s21_pow(base, exp));
}
END_TEST

START_TEST(pow_8) {
  double base = 12;
  int exp = 10;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_9) {
  double base = 12;
  double exp = 1.1;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_10) {
  double base = 0.9;
  double exp = S21_DBL_MAX - 1;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_11) {
  double base = 25.25;
  double exp = 0.5;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), S21_EPS);
}
END_TEST

START_TEST(pow_12) {
  double base = -S21_INF;
  double exp = -4;
  ck_assert_ldouble_eq_tol(pow(base, exp), s21_pow(base, exp), S21_EPS);
}
END_TEST

START_TEST(fabs_1) {
  double a = 12345678912345678;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_2) {
  double a = -12345678912345678;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_3) {
  double a = 1.23456789;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_4) {
  double a = -1.23456789;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_5) {
  double a = S21_DBL_MAX;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_6) {
  double a = -S21_DBL_MAX;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_7) {
  double a = 0;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_8) {
  float a = -3.3;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_9) {
  double a = S21_INF;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_10) {
  double a = -S21_INF;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_11) {
  double a = S21_NAN;
  ck_assert_ldouble_nan(fabs(a));
  ck_assert_ldouble_nan(s21_fabs(a));
}
END_TEST

START_TEST(asin_1) {
  long double a = s21_asin(0);
  long double b = asin(0);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(asin_2) {
  long double a = s21_asin(-1);
  long double b = asin(-1);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(asin_3) {
  long double a = s21_asin(0.4);
  long double b = asin(0.4);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(sin_1) {
  long double a = s21_sin(0);
  long double b = sin(0);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(sin_2) {
  long double a = s21_sin(-1);
  long double b = sin(-1);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(sin_3) {
  long double a = s21_sin(0.4);
  long double b = sin(0.4);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(cos_1) {
  long double a = s21_cos(0);
  long double b = cos(0);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(cos_2) {
  long double a = s21_cos(-1);
  long double b = cos(-1);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(cos_3) {
  long double a = s21_cos(0.4);
  long double b = cos(0.4);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(cos_4) {
  long double a = s21_cos(10);
  long double b = cos(10);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(tan_1) {
  long double a = s21_tan(0);
  long double b = tan(0);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(tan_2) {
  long double a = s21_tan(-1);
  long double b = tan(-1);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(tan_3) {
  long double a = s21_tan(0.4);
  long double b = tan(0.4);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(atan_1) {
  long double a = s21_atan(0);
  long double b = atan(0);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(atan_2) {
  long double a = s21_atan(-1);
  long double b = atan(-1);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST

START_TEST(atan_3) {
  long double a = s21_atan(0.4);
  long double b = atan(0.4);
  ck_assert_ldouble_eq_tol(a, b, S21_EPS);
}
END_TEST
///////////////////////////////////////////////////////////////////////

START_TEST(ceil_1) {
  double a = 12345678912345678;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_2) {
  double a = -12345678912345678;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_3) {
  double a = 1.23456789;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_4) {
  double a = -1.23456789;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_5) {
  double a = 1.7976931348623158e+308;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_6) {
  double a = -1.7976931348623158e+308;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_7) {
  double a = 0;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_8) {
  double a = -3.3;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_9) {
  double a = S21_INF;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_10) {
  double a = -S21_INF;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_11) {
  double a = -0;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_12) {
  double a = -0.0000000000001;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_13) {
  double a = 0.0000000000001;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

///////////////////////////////////////////////////////////////////////

START_TEST(floor_1) {
  double a = 12345678912345678;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_2) {
  double a = -12345678912345678;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_3) {
  double a = 1.23456789;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_4) {
  double a = -1.23456789;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_5) {
  double a = 1.7976931348623158e+308;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_6) {
  double a = -1.7976931348623158e+308;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_7) {
  double a = 0;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_8) {
  double a = -3.3;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_9) {
  double a = S21_INF;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_10) {
  double a = -S21_INF;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_11) {
  double a = -0;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_12) {
  double a = -0.0000000000001;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_13) {
  double a = 0.0000000000001;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_14) {
  double a = S21_NAN;
  ck_assert_ldouble_nan(fabs(a));
  ck_assert_ldouble_nan(s21_fabs(a));
}
END_TEST

START_TEST(exp_1) {
  double a = 0;
  ck_assert_ldouble_eq_tol(exp(a), s21_exp(a), S21_EPS);
}
END_TEST

START_TEST(exp_2) {
  double a = 20;
  ck_assert_ldouble_eq_tol(exp(a), s21_exp(a), S21_EPS);
}
END_TEST

START_TEST(exp_3) {
  double a = -20;
  ck_assert_ldouble_eq_tol(exp(a), s21_exp(a), S21_EPS);
}
END_TEST

START_TEST(exp_4) {
  double a = 0.000123;
  ck_assert_ldouble_eq_tol(exp(a), s21_exp(a), S21_EPS);
}
END_TEST

START_TEST(exp_5) {
  double a = -0.120001;
  ck_assert_ldouble_eq_tol(exp(a), s21_exp(a), S21_EPS);
}
END_TEST

START_TEST(exp_6) {
  double a = 123123123;
  ck_assert_ldouble_infinite(exp(a));
  ck_assert_ldouble_infinite(s21_exp(a));
}
END_TEST

START_TEST(exp_7) {
  double a = S21_NAN;
  ck_assert_ldouble_nan(exp(a));
  ck_assert_ldouble_nan(s21_exp(a));
}
END_TEST

START_TEST(exp_8) {
  double a = S21_INF;
  ck_assert_ldouble_infinite(exp(a));
  ck_assert_ldouble_infinite(s21_exp(a));
}
END_TEST

START_TEST(log_1) {
  double a = S21_INF;
  ck_assert_ldouble_infinite(log(a));
  ck_assert_ldouble_infinite(s21_log(a));
}

START_TEST(log_2) {
  double a = S21_NAN;
  ck_assert_ldouble_nan(log(a));
  ck_assert_ldouble_nan(s21_log(a));
}
END_TEST

START_TEST(log_3) {
  double a = -0.000003;
  ck_assert_ldouble_nan(log(a));
  ck_assert_ldouble_nan(s21_log(a));
}
END_TEST

START_TEST(log_4) {
  double a = 131223;
  ck_assert_ldouble_eq_tol(log(a), s21_log(a), S21_EPS);
}
END_TEST

START_TEST(log_5) {
  double a = 0.000123;
  ck_assert_ldouble_eq_tol(log(a), s21_log(a), S21_EPS);
}
END_TEST

START_TEST(log_6) {
  double a = 123.123123;
  ck_assert_ldouble_eq_tol(log(a), s21_log(a), S21_EPS);
}
END_TEST

////////////////  ADDITIONAL  ////////////////////

START_TEST(pow_test_1) {
  for (double k = -9; k <= 9; k += 1.7) {
    for (double g = -9; g < 9; g += 1.7) {
      long double a = s21_pow(k, g);
      long double b = pow(k, g);
      if ((!isnan(a) && !isnan(b)) && !(a == S21_INF && b == S21_INF) &&
          !(a == -S21_INF && b == -S21_INF)) {
        ck_assert_ldouble_eq_tol(a, b, 1e-6);
      }
    }
  }
}
END_TEST

START_TEST(pow_test_2) {
  for (double k = -1e-1; k <= 1; k += 1.1e-1) {
    for (double g = -2.55; g < 2; g += 1.1) {
      long double a = s21_pow(k, g);
      long double b = pow(k, g);
      if ((!isnan(a) && !isnan(b)) && !(a == S21_INF && b == S21_INF) &&
          !(a == -S21_INF && b == -S21_INF)) {
        ck_assert_ldouble_eq_tol(a, b, 1e-6);
      }
      a = s21_pow(g, k);
      b = pow(g, k);
      if ((!isnan(a) && !isnan(b)) && !(a == S21_INF && b == S21_INF) &&
          !(a == -S21_INF && b == -S21_INF)) {
        ck_assert_ldouble_eq_tol(a, b, 1e-6);
      }
    }
  }
}
END_TEST

START_TEST(pow_test_3) {
  ck_assert_ldouble_eq(pow(1, 0), s21_pow(1, 0));
  ck_assert_ldouble_eq(pow(-1, 3), s21_pow(-1, 3));
  ck_assert_ldouble_eq(pow(-1, 4), s21_pow(-1, 4));
  ck_assert_ldouble_eq(pow(0, 0), s21_pow(0, 0));
  ck_assert_ldouble_eq(pow(0, -1), s21_pow(0, -1));
  ck_assert_ldouble_eq(pow(0, 1), s21_pow(0, 1));
  ck_assert_ldouble_eq(pow(S21_INF, 0), s21_pow(S21_INF, 0));
  ck_assert_ldouble_eq(pow(S21_INF, -1), s21_pow(S21_INF, -1));
  ck_assert_ldouble_eq(pow(-1, -S21_INF), s21_pow(-1, -S21_INF));
  ck_assert_ldouble_eq(pow(0, S21_INF), s21_pow(0, S21_INF));
  ck_assert_ldouble_nan(s21_pow(0, S21_NAN));
  ck_assert_ldouble_eq(pow(NAN, 0), s21_pow(S21_NAN, 0));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_eq(pow(S21_INF, S21_INF), s21_pow(S21_INF, S21_INF));
  ck_assert_ldouble_eq(pow(S21_INF, -S21_INF), s21_pow(S21_INF, -S21_INF));
  ck_assert_ldouble_eq(pow(-S21_INF, S21_INF), s21_pow(-S21_INF, S21_INF));
  ck_assert_ldouble_eq(pow(-S21_INF, -S21_INF), s21_pow(-S21_INF, -S21_INF));
  ck_assert_ldouble_eq(pow(-S21_INF, -3), s21_pow(-S21_INF, -3));
  ck_assert_ldouble_eq(pow(-S21_INF, 3), s21_pow(-S21_INF, 3));
  ck_assert_ldouble_eq(pow(-S21_INF, 10), s21_pow(-S21_INF, 10));
  ck_assert_ldouble_eq(pow(1, -S21_INF), s21_pow(1, -S21_INF));
  ck_assert_ldouble_eq(pow(1, NAN), s21_pow(1, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_INF));
  ck_assert_ldouble_nan(s21_pow(S21_INF, S21_NAN));
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -S21_INF));
  ck_assert_ldouble_nan(s21_pow(-S21_INF, S21_NAN));
  ck_assert_ldouble_eq(pow(2, S21_INF), s21_pow(2, S21_INF));
  ck_assert_ldouble_eq(pow(0.5, S21_INF), s21_pow(0.5, S21_INF));
  ck_assert_ldouble_eq(pow(-2, S21_INF), s21_pow(-2, S21_INF));
  ck_assert_ldouble_eq(pow(2, -S21_INF), s21_pow(2, -S21_INF));
  ck_assert_ldouble_eq(pow(0.5, -S21_INF), s21_pow(0.5, -S21_INF));
  ck_assert_ldouble_eq(pow(-2, -S21_INF), s21_pow(-2, -S21_INF));
}
END_TEST

START_TEST(log_test_1) {
  for (double k = 1; k < 100; k += 13.2) {
    long double a = s21_log(k);
    long double b = log(k);
    ck_assert_ldouble_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_2) {
  for (double k = 0.1; k < 4; k += 0.24) {
    long double a = s21_log(k);
    long double b = log(k);
    ck_assert_ldouble_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_3) {
  for (double k = 0.1; k < 10000; k += 123) {
    long double a = s21_log(k);
    long double b = log(k);
    ck_assert_ldouble_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_4) {
  for (double k = 0.000005; k < 1; k *= 5) {
    long double a = s21_log(k);
    long double b = log(k);
    ck_assert_ldouble_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_5) {
  ck_assert_ldouble_nan(s21_log(S21_NAN));
  ck_assert_ldouble_eq(log(0), s21_log(0));
  ck_assert_ldouble_nan(s21_log(-3));
  ck_assert_ldouble_eq(log(S21_INF), s21_log(S21_INF));
  ck_assert_ldouble_nan(s21_log(-S21_INF));
  ck_assert_ldouble_eq_tol(log(1), s21_log(1), S21_EPS);
  ck_assert_ldouble_eq_tol(log(S21_E), s21_log(S21_E), S21_EPS);
  ck_assert_ldouble_eq_tol(log(2), s21_log(2), 1e-6);
}
END_TEST

START_TEST(sin_test_1) {
  for (int R = 10; R >= -10; R -= 4) {
    for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 3) {
      ck_assert_ldouble_eq_tol(sin(k + R * S21_PI), s21_sin(k + R * S21_PI),
                               1e-6);
    }
  }
}
END_TEST

START_TEST(cos_test_1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 17) {
      ck_assert_ldouble_eq_tol(cos(k + R * S21_PI), s21_cos(k + R * S21_PI),
                               1e-6);
    }
  }
}
END_TEST

START_TEST(tan_test_1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 9) {
      ck_assert_ldouble_eq_tol(tan(k + R * S21_PI), s21_tan(k + R * S21_PI),
                               1e-6);
    }
  }
}
END_TEST

START_TEST(sin_cos_tan_test) {
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_INF));
  ck_assert_ldouble_nan(s21_cos(S21_INF));
  ck_assert_ldouble_nan(s21_tan(S21_INF));
  ck_assert_ldouble_nan(s21_sin(-S21_INF));
  ck_assert_ldouble_nan(s21_cos(-S21_INF));
  ck_assert_ldouble_nan(s21_tan(-S21_INF));
  ck_assert_ldouble_eq_tol(tan(S21_PI / 2), s21_tan(S21_PI / 2), 1e-7);
  ck_assert_ldouble_eq_tol(tan(-S21_PI / 2), s21_tan(-S21_PI / 2), 1e-7);
}
END_TEST

START_TEST(exp_test_1) {
  for (double i = -29; i < 23; i += 1) {
    long double a = s21_exp(i);
    long double b = exp(i);
    ck_assert_ldouble_eq_tol(a, b, S21_EPS);
  }
}
END_TEST

START_TEST(exp_test_2) {
  for (double i = -15; i < 15; i += 0.123) {
    long double a = s21_exp(i);
    long double b = exp(i);
    ck_assert_ldouble_eq_tol(a, b, S21_EPS);
  }
}
END_TEST

START_TEST(exp_test_3) {
  for (double k = -5; k < 5; k += 0.00573) {
    double a = s21_exp(k);
    double b = exp(k);
    ck_assert_ldouble_eq_tol(a, b, S21_EPS);
  }
}
END_TEST

START_TEST(exp_test_4) {
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_eq(exp(S21_INF), s21_exp(S21_INF));
  ck_assert_ldouble_eq(exp(-S21_INF), s21_exp(-S21_INF));
  ck_assert_ldouble_eq(exp(0), s21_exp(0));
  ck_assert_ldouble_eq_tol(exp(1), s21_exp(1), 1e-15);
}
END_TEST

START_TEST(asin_test_1) {
  for (float i = -1; i <= 1; i += 0.1) {
    long double a = s21_asin(i);
    long double b = asin(i);
    ck_assert_ldouble_eq_tol(a, b, 1e-7);
  }
  ck_assert_ldouble_eq_tol(asin(1), s21_asin(1), S21_EPS);
}
END_TEST

START_TEST(asin_test_2) {
  for (float k = -1; k <= 1; k += 0.0771) {
    long double a = s21_asin(k);
    long double b = asin(k);
    ck_assert_ldouble_eq_tol(a, b, S21_EPS);
  }
}
END_TEST

START_TEST(acos_test_1) {
  for (float k = -1; k <= 1; k += 0.1) {
    long double a = s21_acos(k);
    long double b = acos(k);
    ck_assert_ldouble_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(acos_test_2) {
  for (float k = -1; k <= 1; k += 0.1) {
    long double a = s21_acos(k);
    long double b = acos(k);
    ck_assert_ldouble_eq_tol(a, b, S21_EPS);
  }
}
END_TEST

START_TEST(atan_test_1) {
  for (float k = -10; k <= 10; k += 4) {
    long double a = s21_atan(k);
    long double b = atan(k);
    ck_assert_ldouble_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(sqrt_test_1) {
  for (double k = 0; k < 21; k += 3) {
    long double a = s21_sqrt(k);
    long double b = sqrt(k);
    ck_assert_ldouble_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(sqrt_test_2) {
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
  ck_assert_ldouble_nan(sqrt(NAN));
  ck_assert_ldouble_eq(s21_sqrt(S21_INF), sqrt(S21_INF));
  ck_assert_ldouble_nan(s21_sqrt(-S21_INF));
  ck_assert_ldouble_nan(sqrt(-S21_INF));
  ck_assert_ldouble_nan(s21_sqrt(-5));
  ck_assert_ldouble_nan(sqrt(-5));
  ck_assert_ldouble_eq_tol(s21_sqrt(1000), sqrt(1000), S21_EPS);
  ck_assert_ldouble_eq(s21_sqrt(-0.0), sqrt(-0.0));
}
END_TEST

START_TEST(atan_test_2) {
  double a = 12;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-7);
  a = 0.4;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-7);
  a = -0.333;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-7);
  a = 55;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-7);
  a = 13.54;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-7);
  a = S21_E;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-7);
}
END_TEST

START_TEST(asin_acos_atan_test) {
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_ldouble_nan(s21_asin(S21_INF));
  ck_assert_ldouble_nan(s21_acos(S21_INF));
  ck_assert_ldouble_eq(atan(S21_INF), s21_atan(S21_INF));
  ck_assert_ldouble_nan(s21_asin(-S21_INF));
  ck_assert_ldouble_nan(s21_acos(-S21_INF));
  ck_assert_ldouble_eq(atan(-S21_INF), atan(-S21_INF));
  ck_assert_ldouble_nan(s21_asin(5));
  ck_assert_ldouble_nan(s21_acos(6));
  ck_assert_ldouble_nan(s21_asin(-8));
  ck_assert_ldouble_nan(s21_acos(-4));
}
END_TEST

START_TEST(abs_test) {
  ck_assert_int_eq(abs(-7), s21_abs(-7));
  ck_assert_int_eq(abs(-98), s21_abs(-98));
  ck_assert_int_eq(abs(123), s21_abs(123));
  ck_assert_int_eq(abs(10009), s21_abs(10009));
  ck_assert_int_eq(abs(-10009), s21_abs(-10009));
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_ldouble_eq(fabs(S21_INF), s21_fabs(S21_INF));
  ck_assert_ldouble_eq(fabs(-S21_INF), s21_fabs(-S21_INF));
  ck_assert_ldouble_nan(fabs(NAN));
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
  ck_assert_ldouble_eq(fabs(-7.0), s21_fabs(-7.0));
  ck_assert_ldouble_eq(fabs(-98.1), s21_fabs(-98.1));
  ck_assert_ldouble_eq(fabs(123.02), s21_fabs(123.02));
  ck_assert_ldouble_eq(fabs(10009.0), s21_fabs(10009.0));
  ck_assert_ldouble_eq(fabs(-10009.555), s21_fabs(-10009.555));
  ck_assert_ldouble_eq(fabs(-0.10009), s21_fabs(-0.10009));
  ck_assert_ldouble_eq(fabs(-1e23), s21_fabs(-1e23));
}
END_TEST

START_TEST(floor_test) {
  ck_assert_ldouble_eq(floor(S21_INF), s21_floor(S21_INF));
  ck_assert_ldouble_eq(floor(-S21_INF), s21_floor(-S21_INF));
  ck_assert_ldouble_nan(floor(NAN));
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
  ck_assert_ldouble_eq(floor(-7.0), s21_floor(-7.0));
  ck_assert_ldouble_eq(floor(-98.1), s21_floor(-98.1));
  ck_assert_ldouble_eq(floor(123.02), s21_floor(123.02));
  ck_assert_ldouble_eq(floor(10009.00123), s21_floor(10009.00123));
  ck_assert_ldouble_eq(floor(-10009.555), s21_floor(-10009.555));
  ck_assert_ldouble_eq(floor(-0.10009), s21_floor(-0.10009));
  ck_assert_ldouble_eq(floor(-1e-23), s21_floor(-1e-23));
  ck_assert_ldouble_eq(floor(100091234.5), s21_floor(100091234.5));
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_ldouble_eq(ceil(S21_INF), s21_ceil(S21_INF));
  ck_assert_ldouble_eq(ceil(-S21_INF), s21_ceil(-S21_INF));
  ck_assert_ldouble_nan(ceil(NAN));
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
  ck_assert_ldouble_eq(ceil(-7.0), s21_ceil(-7.0));
  ck_assert_ldouble_eq(ceil(-98.1), s21_ceil(-98.1));
  ck_assert_ldouble_eq(ceil(123.02), s21_ceil(123.02));
  ck_assert_ldouble_eq(ceil(10009.00123), s21_ceil(10009.00123));
  ck_assert_ldouble_eq(ceil(-10009.555), s21_ceil(-10009.555));
  ck_assert_ldouble_eq(ceil(-0.10009), s21_ceil(-0.10009));
  ck_assert_ldouble_eq(ceil(-1e-23), s21_ceil(-1e-23));
}
END_TEST

START_TEST(fmod_test_1) {
  ck_assert_ldouble_nan(fmod(1, 0));
  ck_assert_ldouble_nan(s21_fmod(1, 0));
  ck_assert_ldouble_eq(fmod(0, -1), s21_fmod(0, -1));
  ck_assert_ldouble_eq(fmod(0, 1), s21_fmod(0, 1));
  ck_assert_ldouble_nan(fmod(S21_INF, -1));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, -1));
  ck_assert_ldouble_eq(fmod(-1, -S21_INF), s21_fmod(-1, -S21_INF));
  ck_assert_ldouble_eq(fmod(0, S21_INF), s21_fmod(0, S21_INF));
  ck_assert_ldouble_nan(fmod(NAN, 0));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, 0));
  ck_assert_ldouble_nan(s21_fmod(0, S21_NAN));
  ck_assert_ldouble_nan(fmod(0, NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(fmod(NAN, NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_INF));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, -S21_INF));
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, S21_NAN));
  ck_assert_ldouble_nan(fmod(NAN, S21_INF));
  ck_assert_ldouble_nan(fmod(S21_INF, NAN));
  ck_assert_ldouble_nan(fmod(NAN, -S21_INF));
  ck_assert_ldouble_nan(fmod(-S21_INF, NAN));
}
END_TEST

//////////////////  ADDITIONAL II ///////////////
START_TEST(s21_abs_1) { ck_assert_int_eq(s21_abs(44), abs(44)); }
END_TEST

START_TEST(s21_abs_2) { ck_assert_int_eq(s21_abs(-44), abs(-44)); }
END_TEST

START_TEST(s21_abs_3) {
  ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
}
END_TEST

START_TEST(s21_abs_4) {
  ck_assert_int_eq(s21_abs(2147483647), abs(2147483647));
}
END_TEST

START_TEST(s21_abs_5) { ck_assert_int_eq(s21_abs(-0), abs(-0)); }
END_TEST

START_TEST(s21_abs_6) { ck_assert_int_eq(s21_abs(+0), abs(+0)); }
END_TEST

START_TEST(s21_abs_7) { ck_assert_int_eq(s21_abs(123), abs(123)); }
END_TEST

START_TEST(s21_abs_8) { ck_assert_int_eq(s21_abs(INT32_MAX), abs(INT32_MAX)); }
END_TEST

START_TEST(s21_abs_9) { ck_assert_int_eq(s21_abs(INT32_MIN), abs(INT32_MIN)); }
END_TEST

START_TEST(s21_abs_10) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(s21_abs_11) { ck_assert_int_eq(s21_abs(123), abs(123)); }
END_TEST

START_TEST(s21_abs_12) { ck_assert_int_eq(s21_abs(4456), abs(4456)); }
END_TEST

START_TEST(s21_abs_13) { ck_assert_int_eq(s21_abs(678), abs(678)); }
END_TEST

START_TEST(s21_abs_14) { ck_assert_int_eq(s21_abs(111111), abs(111111)); }
END_TEST

START_TEST(s21_abs_15) { ck_assert_int_eq(s21_abs(-111111), abs(-111111)); }
END_TEST

START_TEST(s21_acos_1) {
  long double test_val = 1;
  ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_acos_2) {
  long double test_val = -1;
  ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_acos_3) {
  long double test_val = S21_NAN;
  ck_assert_ldouble_nan(s21_acos(test_val));
  ck_assert_ldouble_nan(acos(test_val));
}
END_TEST

START_TEST(s21_acos_4) {
  long double test_val = S21_INF;
  ck_assert_ldouble_nan(s21_cos(test_val));
  ck_assert_ldouble_nan(acos(test_val));
}
END_TEST

START_TEST(s21_acos_5) {
  long double test_val = -S21_INF;
  ck_assert_ldouble_nan(s21_acos(test_val));
  ck_assert_ldouble_nan(acos(test_val));
}
END_TEST

START_TEST(s21_acos_6) {
  long double test_val = -S21_NAN;
  ck_assert_ldouble_nan(s21_acos(test_val));
  ck_assert_ldouble_nan(acos(test_val));
}
END_TEST

START_TEST(s21_acos_7) {
  long double test_val = S21_PI;
  ck_assert_ldouble_nan(s21_acos(test_val));
  ck_assert_ldouble_nan(acos(test_val));
}
END_TEST

START_TEST(s21_acos_8) {
  long double test_val = -S21_PI;
  ck_assert_ldouble_nan(s21_acos(test_val));
  ck_assert_ldouble_nan(acos(test_val));
}
END_TEST

START_TEST(s21_acos_9) {
  long double test_val = 0.789789;
  ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_acos_10) {
  long double test_val = -0.789789;
  ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_acos_11) {
  long double test_val = 0;
  ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_acos_12) {
  long double test_val = S21_PI / 5;
  ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_acos_13) {
  long double test_val = -S21_PI / 5;
  ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_acos_14) {
  long double test_val = S21_PI / 9;
  ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_acos_15) {
  long double test_val = -S21_PI / 9;
  ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_acos_16) {
  long double test_val = S21_PI / 6;
  ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_acos_17) {
  long double test_val = -S21_PI / 6;
  ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_acos_18) {
  long double test_val = S21_PI / 21;
  ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_acos_19) {
  long double test_val = -S21_PI / 21;
  ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_acos_20) {
  long double test_val = S21_PI / 99;
  ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_acos_21) {
  for (int i = 0; i < 5; ++i) {
    long double test_val = i * 0.01 * S21_PI;
    ck_assert_ldouble_eq_tol(s21_acos(test_val), acos(test_val), S21_EPS);
    long double test_val_m = -i * 0.01 * S21_PI;
    ck_assert_ldouble_eq_tol(s21_acos(test_val_m), acos(test_val_m), S21_EPS);
  }
}
END_TEST

START_TEST(s21_asin_1) {
  long double test_val = 1;
  ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_asin_2) {
  long double test_val = -1;
  ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_asin_3) {
  long double test_val = S21_NAN;
  ck_assert_ldouble_nan(s21_asin(test_val));
  ck_assert_ldouble_nan(asin(test_val));
}
END_TEST

START_TEST(s21_asin_4) {
  long double test_val = S21_INF;
  ck_assert_ldouble_nan(s21_asin(test_val));
  ck_assert_ldouble_nan(asin(test_val));
}
END_TEST

START_TEST(s21_asin_5) {
  long double test_val = -S21_INF;
  ck_assert_ldouble_nan(s21_asin(test_val));
  ck_assert_ldouble_nan(asin(test_val));
}
END_TEST

START_TEST(s21_asin_6) {
  long double test_val = -S21_NAN;
  ck_assert_ldouble_nan(s21_asin(test_val));
  ck_assert_ldouble_nan(asin(test_val));
}
END_TEST

START_TEST(s21_asin_7) {
  long double test_val = S21_PI / 4;
  ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_asin_8) {
  long double test_val = -S21_PI / 4;
  ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_asin_9) {
  long double test_val = 0.789789;
  ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_asin_10) {
  long double test_val = -0.789789;
  ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_asin_11) {
  long double test_val = 0;
  ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_asin_12) {
  long double test_val = S21_PI / 5;
  ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_asin_13) {
  long double test_val = -S21_PI / 5;
  ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_asin_14) {
  long double test_val = S21_PI / 2;
  ck_assert_ldouble_nan(s21_asin(test_val));
  ck_assert_ldouble_nan(asin(test_val));
}
END_TEST

START_TEST(s21_asin_15) {
  long double test_val = -S21_PI / 2;
  ck_assert_ldouble_nan(s21_asin(test_val));
  ck_assert_ldouble_nan(asin(test_val));
}
END_TEST

START_TEST(s21_asin_16) {
  long double test_val = S21_PI / 6;
  ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_asin_17) {
  long double test_val = -S21_PI / 6;
  ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_asin_18) {
  long double test_val = S21_PI / 14;
  ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_asin_19) {
  long double test_val = -S21_PI / 19;
  ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_asin_20) {
  long double test_val = 0.2 * S21_PI;
  ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_asin_21) {
  for (int i = 0; i < 5; ++i) {
    long double test_val = i * 0.01 * S21_PI;
    ck_assert_ldouble_eq_tol(s21_asin(test_val), asin(test_val), S21_EPS);
    long double test_val_m = -i * 0.01 * S21_PI;
    ck_assert_ldouble_eq_tol(s21_asin(test_val_m), asin(test_val_m), S21_EPS);
  }
}
END_TEST

START_TEST(s21_atan_1) {
  long double test_val = 1;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_2) {
  long double test_val = -1;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_3) {
  long double test_val = S21_NAN;
  ck_assert_ldouble_nan(s21_atan(test_val));
  ck_assert_ldouble_nan(atan(test_val));
}
END_TEST

START_TEST(s21_atan_4) {
  long double test_val = S21_INF;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_5) {
  long double test_val = -S21_INF;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_6) {
  long double test_val = -S21_NAN;
  ck_assert_ldouble_nan(s21_atan(test_val));
  ck_assert_ldouble_nan(atan(test_val));
}
END_TEST

START_TEST(s21_atan_7) {
  long double test_val = S21_PI;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_8) {
  long double test_val = -S21_PI;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_9) {
  long double test_val = 0.789789;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_10) {
  long double test_val = -0.789789;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_11) {
  long double test_val = 0;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_12) {
  long double test_val = S21_PI / 5;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_13) {
  long double test_val = -S21_PI / 5;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_14) {
  long double test_val = S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_15) {
  long double test_val = -S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_16) {
  long double test_val = S21_PI / 6;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_17) {
  long double test_val = -S21_PI / 6;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_18) {
  long double test_val = S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_19) {
  long double test_val = -S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_20) {
  long double test_val = 2 * S21_PI;
  ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_atan_21) {
  for (int i = 0; i < 5; ++i) {
    long double test_val = i * S21_PI;
    ck_assert_ldouble_eq_tol(s21_atan(test_val), atan(test_val), S21_EPS);
    long double test_val_m = -i * S21_PI;
    ck_assert_ldouble_eq_tol(s21_atan(test_val_m), atan(test_val_m), S21_EPS);
  }
}
END_TEST

START_TEST(s21_ceil_1) { ck_assert_ldouble_eq(s21_ceil(1.3), ceil(1.3)); }
END_TEST

START_TEST(s21_ceil_2) { ck_assert_ldouble_eq(s21_ceil(-1.3), ceil(-1.3)); }
END_TEST

START_TEST(s21_ceil_3) { ck_assert_ldouble_eq(s21_ceil(0.1), ceil(0.1)); }
END_TEST

START_TEST(s21_ceil_4) { ck_assert_ldouble_eq(s21_ceil(-0.1), ceil(-0.1)); }
END_TEST

START_TEST(s21_ceil_5) {
  ck_assert_ldouble_eq(s21_ceil(-9999.1), ceil(-9999.1));
}
END_TEST

START_TEST(s21_ceil_6) {
  ck_assert_ldouble_eq(s21_ceil(-9999.123), ceil(-9999.123));
}
END_TEST

START_TEST(s21_ceil_7) {
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_nan(ceil(NAN));
}
END_TEST

START_TEST(s21_ceil_8) {
  ck_assert_ldouble_eq(s21_ceil(-9999999999999999.0),
                       ceil(-9999999999999999.0));
}
END_TEST

START_TEST(s21_ceil_9) { ck_assert_ldouble_eq(s21_ceil(-0), ceil(-0)); }
END_TEST

START_TEST(s21_ceil_10) { ck_assert_ldouble_eq(s21_ceil(0), ceil(0)); }
END_TEST

START_TEST(s21_ceil_11) { ck_assert_ldouble_eq(s21_ceil(-0.7), ceil(-0.7)); }
END_TEST

START_TEST(s21_ceil_12) { ck_assert_ldouble_eq(s21_ceil(-1.9), ceil(-1.9)); }
END_TEST

START_TEST(s21_ceil_13) {
  ck_assert_ldouble_eq(s21_ceil(9999999999999999.0), ceil(9999999999999999.0));
}
END_TEST

START_TEST(s21_ceil_14) { ck_assert_ldouble_eq(s21_ceil(-9.0), ceil(-9.0)); }
END_TEST

START_TEST(s21_ceil_15) { ck_assert_ldouble_eq(s21_ceil(9.0), ceil(9.0)); }
END_TEST

START_TEST(s21_ceil_16) { ck_assert_ldouble_eq(s21_ceil(9), ceil(9)); }
END_TEST

START_TEST(s21_ceil_17) { ck_assert_ldouble_eq(s21_ceil(-9), ceil(-9)); }
END_TEST

START_TEST(s21_ceil_18) {
  ck_assert_ldouble_eq(s21_ceil(-S21_INF), ceil(-S21_INF));
}
END_TEST

START_TEST(s21_ceil_19) {
  ck_assert_ldouble_eq(s21_ceil(S21_INF), ceil(S21_INF));
}
END_TEST

START_TEST(s21_cos_1) {
  long double test_val = 1;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_2) {
  long double test_val = -1;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_3) {
  long double test_val = S21_NAN;
  ck_assert_ldouble_nan(s21_cos(test_val));
  ck_assert_ldouble_nan(cos(test_val));
}
END_TEST

START_TEST(s21_cos_4) {
  long double test_val = S21_INF;
  ck_assert_ldouble_nan(s21_cos(test_val));
  ck_assert_ldouble_nan(cos(test_val));
}
END_TEST

START_TEST(s21_cos_5) {
  long double test_val = -S21_INF;
  ck_assert_ldouble_nan(s21_cos(test_val));
  ck_assert_ldouble_nan(cos(test_val));
}
END_TEST

START_TEST(s21_cos_6) {
  long double test_val = -S21_NAN;
  ck_assert_ldouble_nan(s21_cos(test_val));
  ck_assert_ldouble_nan(cos(test_val));
}
END_TEST

START_TEST(s21_cos_7) {
  long double test_val = S21_PI;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_8) {
  long double test_val = -S21_PI;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_9) {
  long double test_val = 0.789789;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_10) {
  long double test_val = -0.789789;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_11) {
  long double test_val = 0;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_12) {
  long double test_val = S21_PI / 5;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_13) {
  long double test_val = -S21_PI / 5;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_14) {
  long double test_val = S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_15) {
  long double test_val = -S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_16) {
  long double test_val = S21_PI / 6;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_17) {
  long double test_val = -S21_PI / 6;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_18) {
  long double test_val = S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_19) {
  long double test_val = -S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_20) {
  long double test_val = 2 * S21_PI;
  ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_cos_21) {
  for (int i = 0; i < 5; ++i) {
    long double test_val = i * S21_PI;
    ck_assert_ldouble_eq_tol(s21_cos(test_val), cos(test_val), S21_EPS);
    long double test_val_m = -i * S21_PI;
    ck_assert_ldouble_eq_tol(s21_cos(test_val_m), cos(test_val_m), S21_EPS);
  }
}
END_TEST

START_TEST(s21_cos_22) {
  for (double i = -S21_PI; i <= S21_PI; i += 1.234567) {
    ck_assert_ldouble_eq_tol(cos(1234567890.123456 + i),
                             s21_cos(1234567890.123456 + i), S21_EPS);
  }
}
END_TEST

START_TEST(s21_cos_23) {
  for (double i = -S21_PI; i <= S21_PI; i += 1.234467) {
    ck_assert_ldouble_eq_tol(cos(-1234567890.123456 + i),
                             s21_cos(-1234567890.123456 + i), S21_EPS);
  }
}
END_TEST

START_TEST(s21_cos_24) {
  ck_assert_ldouble_eq_tol(s21_cos(9999999999.999999), cos(9999999999.999999),
                           S21_EPS);
}
END_TEST

START_TEST(s21_cos_25) {
  ck_assert_ldouble_eq_tol(s21_cos(-9999999999.999999), cos(-9999999999.999999),
                           S21_EPS);
}
END_TEST
START_TEST(s21_exp_1) { ck_assert_ldouble_eq_tol(s21_exp(1), exp(1), S21_EPS); }
END_TEST

START_TEST(s21_exp_2) {
  ck_assert_ldouble_eq_tol(s21_exp(15), exp(15), S21_EPS);
}
END_TEST

START_TEST(s21_exp_3) {
  ck_assert_ldouble_eq_tol(s21_exp(0.2544576373), exp(0.2544576373), S21_EPS);
}
END_TEST

START_TEST(s21_exp_4) {
  ck_assert_ldouble_eq_tol(s21_exp(-6), exp(-6), S21_EPS);
}
END_TEST

START_TEST(s21_exp_5) {
  ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), S21_EPS);
}
END_TEST

START_TEST(s21_exp_6) { ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), S21_EPS); }
END_TEST

START_TEST(s21_exp_7) {
  ck_assert_ldouble_nan(s21_exp(S21_NAN));
  ck_assert_ldouble_nan(exp(S21_NAN));
}
END_TEST

START_TEST(s21_exp_8) {
  ck_assert_ldouble_infinite(s21_exp(S21_INF));
  ck_assert_ldouble_infinite(exp(S21_INF));
}
END_TEST

START_TEST(s21_exp_9) {
  long double test_val = S21_INF;
  ck_assert_ldouble_eq_tol(s21_exp(-test_val), exp(-test_val), S21_EPS);
}
END_TEST

START_TEST(s21_exp_10) {
  ck_assert_ldouble_infinite(s21_exp(999999));
  ck_assert_ldouble_infinite(exp(999999));
}
END_TEST

START_TEST(s21_exp_11) {
  ck_assert_ldouble_eq_tol(s21_exp(-999999), exp(-999999), S21_EPS);
}
END_TEST

START_TEST(s21_exp_12) {
  ck_assert_ldouble_eq_tol(s21_exp(-1.156156), exp(-1.156156), S21_EPS);
}
END_TEST

START_TEST(s21_exp_13) {
  long double test_val = 1e-9;
  ck_assert_ldouble_eq_tol(s21_exp(test_val), exp(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_exp_14) {
  ck_assert_ldouble_eq_tol(s21_exp(0.5555555555555555), exp(0.5555555555555555),
                           S21_EPS);
}
END_TEST

START_TEST(s21_exp_15) {
  ck_assert_ldouble_eq_tol(s21_exp(-0.5555555555555555),
                           exp(-0.5555555555555555), S21_EPS);
}
END_TEST

START_TEST(s21_fabs_1) {
  ck_assert_ldouble_eq(s21_fabs(15.123123123123123), fabs(15.123123123123123));
}
END_TEST

START_TEST(s21_fabs_2) {
  ck_assert_ldouble_eq(s21_fabs(21.123123123123123), fabs(21.123123123123123));
}
END_TEST

START_TEST(s21_fabs_3) {
  ck_assert_ldouble_eq(s21_fabs(-21.123123123123123),
                       fabs(-21.123123123123123));
}
END_TEST

START_TEST(s21_fabs_4) {
  ck_assert_ldouble_eq(s21_fabs(-15.123123123123123),
                       fabs(-15.123123123123123));
}
END_TEST

START_TEST(s21_fabs_5) {
  ck_assert_ldouble_eq(s21_fabs(-9519359135915.53151413431),
                       fabs(-9519359135915.53151413431));
}
END_TEST

START_TEST(s21_fabs_6) {
  ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY));
}
END_TEST

START_TEST(s21_fabs_7) {
  ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

START_TEST(s21_fabs_8) {
  ck_assert_ldouble_nan(fabs(S21_NAN));
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
}
END_TEST

START_TEST(s21_fabs_9) {
  ck_assert_ldouble_eq(s21_fabs(-23456.23465642365), fabs(-23456.23465642365));
}
END_TEST

START_TEST(s21_fabs_10) { ck_assert_ldouble_eq(s21_fabs(0.0), fabs(0.0)); }
END_TEST

START_TEST(s21_fabs_11) {
  ck_assert_ldouble_eq(s21_fabs(0.000001), fabs(0.000001));
}
END_TEST

START_TEST(s21_fabs_12) {
  ck_assert_ldouble_eq(s21_fabs(-0.000001), fabs(-0.000001));
}
END_TEST

START_TEST(s21_fabs_13) {
  ck_assert_ldouble_eq(s21_fabs(-2456245611.156156156),
                       fabs(-2456245611.156156156));
}
END_TEST

START_TEST(s21_fabs_14) {
  ck_assert_ldouble_eq(s21_fabs(2456245611.156156156),
                       fabs(2456245611.156156156));
}
END_TEST

START_TEST(s21_fabs_15) {
  ck_assert_ldouble_eq(s21_fabs(-2456245611.156156156),
                       fabs(2456245611.156156156));
}
END_TEST

START_TEST(s21_floor_1) {
  ck_assert_ldouble_eq_tol(s21_floor(-15.123123123), floor(-15.123123123),
                           S21_EPS);
}
END_TEST

START_TEST(s21_floor_2) {
  ck_assert_ldouble_eq_tol(s21_floor(21.123123123), floor(21.123123123),
                           S21_EPS);
}
END_TEST

START_TEST(s21_floor_3) { ck_assert_ldouble_eq(s21_floor(0.1), floor(0.1)); }
END_TEST

START_TEST(s21_floor_4) { ck_assert_ldouble_eq(s21_floor(-0.1), floor(-0.1)); }
END_TEST

START_TEST(s21_floor_5) { ck_assert_ldouble_eq(s21_floor(0.0), floor(0.0)); }
END_TEST

START_TEST(s21_floor_6) { ck_assert_ldouble_eq(s21_floor(-0.9), floor(-0.9)); }
END_TEST

START_TEST(s21_floor_7) { ck_assert_ldouble_eq(s21_floor(0.9), floor(0.9)); }
END_TEST

START_TEST(s21_floor_8) {
  ck_assert_ldouble_nan(floor(S21_NAN));
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
}
END_TEST

START_TEST(s21_floor_9) {
  ck_assert_ldouble_eq_tol(s21_floor(0.999), floor(0.999), S21_EPS);
}
END_TEST

START_TEST(s21_floor_10) {
  ck_assert_ldouble_eq_tol(s21_floor(1.999), floor(1.999), S21_EPS);
}
END_TEST

START_TEST(s21_floor_11) {
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_nan(floor(NAN));
}
END_TEST

START_TEST(s21_floor_12) {
  ck_assert_ldouble_eq(s21_floor(999999.987987987987),
                       floor(999999.987987987987));
}
END_TEST

START_TEST(s21_floor_13) {
  ck_assert_ldouble_eq(s21_floor(-999999.987987987987),
                       floor(-999999.987987987987));
}
END_TEST

START_TEST(s21_floor_14) { ck_assert_ldouble_eq(s21_floor(-1.9), floor(-1.9)); }
END_TEST

START_TEST(s21_floor_15) { ck_assert_ldouble_eq(s21_floor(1.9), floor(1.9)); }
END_TEST

START_TEST(s21_floor_16) {
  ck_assert_ldouble_eq(s21_floor(-9999999999999999.),
                       floor(-9999999999999999.));
}
END_TEST

START_TEST(s21_floor_17) { ck_assert_ldouble_eq(s21_floor(0), floor(0)); }
END_TEST

START_TEST(s21_floor_18) { ck_assert_ldouble_eq(s21_floor(19), floor(19)); }
END_TEST

START_TEST(s21_floor_19) { ck_assert_ldouble_eq(s21_floor(-19), floor(-19)); }
END_TEST

START_TEST(s21_floor_20) {
  ck_assert_ldouble_eq(s21_floor(S21_INF), floor(S21_INF));
}
END_TEST

START_TEST(s21_floor_21) {
  ck_assert_ldouble_eq(s21_floor(-S21_INF), floor(-S21_INF));
}
END_TEST
START_TEST(s21_fmod_1) {
  ck_assert_ldouble_eq_tol(s21_fmod(7.3, 2.9), fmod(7.3, 2.9), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_2) {
  ck_assert_ldouble_eq_tol(s21_fmod(15.5, 2.2), fmod(15.5, 2.2), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_3) {
  ck_assert_ldouble_eq_tol(s21_fmod(21, 5), fmod(21, 5), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_4) {
  ck_assert_ldouble_eq_tol(s21_fmod(-21, 5), fmod(-21, 5), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_5) {
  ck_assert_ldouble_eq_tol(s21_fmod(15.5, -5), fmod(15.5, -5), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_6) {
  ck_assert_ldouble_eq_tol(s21_fmod(-15.5, -5), fmod(-15.5, -5), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_7) {
  ck_assert_ldouble_eq_tol(s21_fmod(-15.5, -2.2), fmod(-15.5, -2.2), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_8) {
  ck_assert_ldouble_eq_tol(s21_fmod(-15.4584584547949546, 2.549849898494),
                           fmod(-15.4584584547949546, 2.549849898494), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_9) {
  ck_assert_ldouble_nan(s21_fmod(-15.4584584547949546, S21_NAN));
  ck_assert_ldouble_nan(fmod(-15.4584584547949546, S21_NAN));
}
END_TEST

START_TEST(s21_fmod_10) {
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(fmod(S21_NAN, S21_NAN));
}
END_TEST

START_TEST(s21_fmod_11) {
  ck_assert_ldouble_nan(s21_fmod(NAN, 2.549849898494));
  ck_assert_ldouble_nan(fmod(NAN, 2.549849898494));
}
END_TEST

START_TEST(s21_fmod_12) {
  ck_assert_ldouble_eq_tol(s21_fmod(2.549849898494, S21_INF),
                           fmod(2.549849898494, S21_INF), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_13) {
  ck_assert_ldouble_nan(s21_fmod(S21_INF, 2.549849898494));
  ck_assert_ldouble_nan(fmod(S21_INF, 2.549849898494));
}
END_TEST

START_TEST(s21_fmod_14) {
  ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_INF));
  ck_assert_ldouble_nan(fmod(S21_INF, S21_INF));
}
END_TEST

START_TEST(s21_fmod_15) {
  ck_assert_ldouble_eq_tol(s21_fmod(12, 1e-8), fmod(12, 1e-8), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_16) {
  ck_assert_ldouble_eq_tol(s21_fmod(12, 2), fmod(12, 2), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_17) {
  ck_assert_ldouble_eq_tol(s21_fmod(0.0000000000000000009, 50),
                           fmod(0.0000000000000000009, 50), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_18) {
  ck_assert_ldouble_eq_tol(s21_fmod(-15.4584584547949546, -2.549849898494),
                           fmod(-15.4584584547949546, -2.549849898494),
                           S21_EPS);
}
END_TEST

START_TEST(s21_fmod_19) {
  ck_assert_ldouble_eq_tol(s21_fmod(-9e-10, 50), fmod(-9e-10, 50), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_20) {
  ck_assert_ldouble_eq_tol(s21_fmod(50, -9e-10), fmod(50, -9e-10), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_21) {
  ck_assert_ldouble_eq_tol(s21_fmod(-123456789.0, -0.1),
                           fmod(-123456789.0, -0.1), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_22) {
  ck_assert_ldouble_eq_tol(s21_fmod(-123456789.0, -0.000001),
                           fmod(-123456789.0, -0.000001), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_23) {
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, 50));
  ck_assert_ldouble_nan(fmod(-S21_INF, 50));
}
END_TEST

START_TEST(s21_fmod_24) {
  ck_assert_ldouble_nan(s21_fmod(S21_INF, 50));
  ck_assert_ldouble_nan(fmod(S21_INF, 50));
}
END_TEST

START_TEST(s21_fmod_25) {
  ck_assert_ldouble_nan(s21_fmod(50, 0));
  ck_assert_ldouble_nan(fmod(50, 0));
}
END_TEST

START_TEST(s21_fmod_26) {
  ck_assert_ldouble_nan(s21_fmod(-1, 0));
  ck_assert_ldouble_nan(fmod(-1, 0));
}
END_TEST

START_TEST(s21_fmod_27) {
  ck_assert_ldouble_nan(s21_fmod(-S21_INF, 0));
  ck_assert_ldouble_nan(fmod(-S21_INF, 0));
}
END_TEST

START_TEST(s21_log_1) { ck_assert_ldouble_eq_tol(s21_log(1), log(1), S21_EPS); }
END_TEST

START_TEST(s21_log_2) {
  ck_assert_ldouble_eq_tol(s21_log(15), log(15), S21_EPS);
}
END_TEST

START_TEST(s21_log_3) {
  ck_assert_ldouble_eq_tol(s21_log(0.2544576373), log(0.2544576373), S21_EPS);
}
END_TEST

START_TEST(s21_log_4) {
  ck_assert_ldouble_nan(s21_log(-6));
  ck_assert_ldouble_nan(log(-6));
}
END_TEST

START_TEST(s21_log_5) {
  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_ldouble_nan(log(-1));
}
END_TEST

START_TEST(s21_log_6) {
  ck_assert_ldouble_eq_tol(s21_log(1.123123), log(1.123123), S21_EPS);
}
END_TEST

START_TEST(s21_log_7) {
  ck_assert_ldouble_nan(s21_log(S21_NAN));
  ck_assert_ldouble_nan(exp(S21_NAN));
}
END_TEST

START_TEST(s21_log_8) {
  ck_assert_ldouble_nan(s21_log(-567));
  ck_assert_ldouble_nan(log(-567));
}
END_TEST

START_TEST(s21_log_9) {
  ck_assert_ldouble_eq_tol(s21_log(999), log(999), S21_EPS);
}
END_TEST

START_TEST(s21_log_10) {
  ck_assert_ldouble_eq_tol(s21_log(21), log(21), S21_EPS);
}
END_TEST

START_TEST(s21_log_11) {
  ck_assert_ldouble_eq_tol(s21_log(1.156156), log(1.156156), S21_EPS);
}
END_TEST

START_TEST(s21_log_12) {
  ck_assert_ldouble_eq_tol(s21_log(1.156156), log(1.156156), S21_EPS);
}
END_TEST

START_TEST(s21_log_13) {
  ck_assert_ldouble_eq_tol(s21_log(0.2544576373), log(0.2544576373), S21_EPS);
}
END_TEST

START_TEST(s21_log_14) {
  ck_assert_ldouble_eq_tol(s21_log(0.5555555555555555), log(0.5555555555555555),
                           S21_EPS);
}
END_TEST

START_TEST(s21_log_15) {
  ck_assert_ldouble_eq_tol(s21_log(25.978987987879978778),
                           log(25.978987987879978778), S21_EPS);
}
END_TEST

START_TEST(s21_log_16) {
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_infinite(log(0));
}
END_TEST

START_TEST(s21_log_17) {
  ck_assert_ldouble_infinite(s21_log(S21_INF));
  ck_assert_ldouble_infinite(log(S21_INF));
}
END_TEST

START_TEST(s21_log_18) {
  ck_assert_ldouble_eq_tol(s21_log(2), log(2), S21_EPS);
}
END_TEST

START_TEST(s21_pow_1) {
  ck_assert_ldouble_eq_tol(s21_pow(0, 5), pow(0, 5), S21_EPS);
}
END_TEST

START_TEST(s21_pow_2) {
  ck_assert_ldouble_infinite(s21_pow(0, -5));
  ck_assert_ldouble_infinite(pow(0, -5));
}
END_TEST

START_TEST(s21_pow_3) {
  ck_assert_ldouble_nan(s21_pow(0, S21_NAN));
  ck_assert_ldouble_nan(pow(0, S21_NAN));
}
END_TEST

START_TEST(s21_pow_4) {
  ck_assert_ldouble_eq_tol(s21_pow(0, 5.5), pow(0, 5.5), S21_EPS);
}
END_TEST

START_TEST(s21_pow_5) {
  ck_assert_ldouble_infinite(s21_pow(0, -5.5));
  ck_assert_ldouble_infinite(pow(0, -5.5));
}
END_TEST

START_TEST(s21_pow_6) {
  ck_assert_ldouble_nan(s21_pow(0, -S21_NAN));
  ck_assert_ldouble_nan(pow(0, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_7) {
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), S21_EPS);
}
END_TEST

START_TEST(s21_pow_8) {
  ck_assert_ldouble_eq_tol(s21_pow(0, S21_INF), pow(0, S21_INF), S21_EPS);
}
END_TEST

START_TEST(s21_pow_9) {
  ck_assert_ldouble_infinite(s21_pow(0, -S21_INF));
  ck_assert_ldouble_infinite(pow(0, -S21_INF));
}
END_TEST

START_TEST(s21_pow_10) {
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(pow(S21_NAN, S21_NAN));
}
END_TEST

START_TEST(s21_pow_11) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, 5), pow(-1, 5), S21_EPS);
}
END_TEST

START_TEST(s21_pow_12) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, -5), pow(-1, -5), S21_EPS);
}
END_TEST

START_TEST(s21_pow_13) {
  ck_assert_ldouble_nan(s21_pow(-1, -5.5));
  ck_assert_ldouble_nan(pow(-1, -5.5));
}
END_TEST

START_TEST(s21_pow_14) {
  ck_assert_ldouble_nan(s21_pow(-1, 5.5));
  ck_assert_ldouble_nan(pow(-1, 5.5));
}
END_TEST

START_TEST(s21_pow_15) {
  ck_assert_ldouble_nan(s21_pow(-1, S21_NAN));
  ck_assert_ldouble_nan(pow(-1, S21_NAN));
}
END_TEST

START_TEST(s21_pow_16) {
  ck_assert_ldouble_nan(s21_pow(-1, -S21_NAN));
  ck_assert_ldouble_nan(pow(-1, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_17) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, 0), pow(-1, 0), S21_EPS);
}
END_TEST

START_TEST(s21_pow_18) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, S21_INF), pow(-1, S21_INF), S21_EPS);
}
END_TEST

START_TEST(s21_pow_19) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, -S21_INF), pow(-1, S21_INF), S21_EPS);
}
END_TEST

START_TEST(s21_pow_20) {
  ck_assert_ldouble_eq_tol(s21_pow(1, 5), pow(1, 5), S21_EPS);
}
END_TEST

START_TEST(s21_pow_21) {
  ck_assert_ldouble_eq_tol(s21_pow(1, -5), pow(1, -5), S21_EPS);
}
END_TEST

START_TEST(s21_pow_22) {
  ck_assert_ldouble_eq_tol(s21_pow(1, 5.5), pow(1, 5.5), S21_EPS);
}
END_TEST

START_TEST(s21_pow_23) {
  ck_assert_ldouble_eq_tol(s21_pow(1, -5.5), pow(1, -5.5), S21_EPS);
}
END_TEST

START_TEST(s21_pow_24) {
  ck_assert_ldouble_eq_tol(s21_pow(1, S21_NAN), pow(1, S21_NAN), S21_EPS);
}
END_TEST

START_TEST(s21_pow_25) {
  ck_assert_ldouble_eq_tol(s21_pow(1, -S21_NAN), pow(1, -S21_NAN), S21_EPS);
}
END_TEST

START_TEST(s21_pow_26) {
  ck_assert_ldouble_eq_tol(s21_pow(1, 0), pow(1, 0), S21_EPS);
}
END_TEST

START_TEST(s21_pow_27) {
  ck_assert_ldouble_eq_tol(s21_pow(1, S21_INF), pow(1, S21_INF), S21_EPS);
}
END_TEST

START_TEST(s21_pow_28) {
  ck_assert_ldouble_eq_tol(s21_pow(1, -S21_INF), pow(1, -S21_INF), S21_EPS);
}
END_TEST

START_TEST(s21_pow_29) {
  ck_assert_ldouble_eq_tol(s21_pow(5, 0), pow(5, 0), S21_EPS);
}
END_TEST

START_TEST(s21_pow_30) {
  ck_assert_ldouble_eq_tol(s21_pow(-5, 0), pow(-5, 0), S21_EPS);
}
END_TEST

START_TEST(s21_pow_31) {
  ck_assert_ldouble_eq_tol(s21_pow(5.5, 0), pow(5.5, 0), S21_EPS);
}
END_TEST

START_TEST(s21_pow_32) {
  ck_assert_ldouble_eq_tol(s21_pow(-5.5, 0), pow(-5.5, 0), S21_EPS);
}
END_TEST

START_TEST(s21_pow_33) {
  ck_assert_ldouble_eq_tol(s21_pow(S21_NAN, 0), pow(S21_NAN, 0), S21_EPS);
}
END_TEST

START_TEST(s21_pow_34) {
  ck_assert_ldouble_eq_tol(s21_pow(-S21_NAN, 0), pow(-S21_NAN, 0), S21_EPS);
}
END_TEST

START_TEST(s21_pow_35) {
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), S21_EPS);
}
END_TEST

START_TEST(s21_pow_36) {
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF, 0), pow(S21_INF, 0), S21_EPS);
}
END_TEST

START_TEST(s21_pow_37) {
  ck_assert_ldouble_eq_tol(s21_pow(-S21_INF, 0), pow(-S21_INF, 0), S21_EPS);
}
END_TEST

START_TEST(s21_pow_38) {
  ck_assert_ldouble_infinite(s21_pow(S21_INF, 5));
  ck_assert_ldouble_infinite(pow(S21_INF, 5));
}
END_TEST

START_TEST(s21_pow_39) {
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF, -5), pow(S21_INF, -5), S21_EPS);
}
END_TEST

START_TEST(s21_pow_40) {
  ck_assert_ldouble_infinite(s21_pow(S21_INF, 5.5));
  ck_assert_ldouble_infinite(pow(S21_INF, 5.5));
}
END_TEST

START_TEST(s21_pow_41) {
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF, -5.5), pow(S21_INF, -5.5), S21_EPS);
}
END_TEST

START_TEST(s21_pow_42) {
  ck_assert_ldouble_nan(s21_pow(S21_INF, S21_NAN));
  ck_assert_ldouble_nan(pow(S21_INF, S21_NAN));
}
END_TEST

START_TEST(s21_pow_43) {
  ck_assert_ldouble_nan(s21_pow(S21_INF, -S21_NAN));
  ck_assert_ldouble_nan(pow(S21_INF, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_44) {
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF, 0), pow(S21_INF, 0), S21_EPS);
}
END_TEST

START_TEST(s21_pow_45) {
  ck_assert_ldouble_infinite(s21_pow(S21_INF, S21_INF));
  ck_assert_ldouble_infinite(pow(S21_INF, S21_INF));
}
END_TEST

START_TEST(s21_pow_46) {
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF, -S21_INF), pow(S21_INF, -S21_INF),
                           S21_EPS);
}
END_TEST

START_TEST(s21_pow_47) {
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF, -5.5), pow(S21_INF, -5.5), S21_EPS);
}
END_TEST

START_TEST(s21_pow_48) {
  ck_assert_ldouble_eq_tol(s21_pow(-S21_INF, -5), pow(-S21_INF, -5), S21_EPS);
}
END_TEST

START_TEST(s21_pow_49) {
  ck_assert_ldouble_infinite(s21_pow(-S21_INF, 5.5));
  ck_assert_ldouble_infinite(pow(-S21_INF, 5.5));
}
END_TEST

START_TEST(s21_pow_50) {
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF, -5.5), pow(-S21_INF, -5.5),
                           S21_EPS);
}
END_TEST

START_TEST(s21_pow_51) {
  ck_assert_ldouble_nan(s21_pow(-S21_INF, S21_NAN));
  ck_assert_ldouble_nan(pow(-S21_INF, S21_NAN));
}
END_TEST

START_TEST(s21_pow_52) {
  ck_assert_ldouble_nan(s21_pow(-S21_INF, -S21_NAN));
  ck_assert_ldouble_nan(pow(-S21_INF, -S21_NAN));
}
END_TEST

START_TEST(s21_pow_53) {
  ck_assert_ldouble_eq_tol(s21_pow(-S21_INF, 0), pow(-S21_INF, 0), S21_EPS);
}
END_TEST

START_TEST(s21_pow_54) {
  ck_assert_ldouble_infinite(s21_pow(-S21_INF, S21_INF));
  ck_assert_ldouble_infinite(pow(-S21_INF, S21_INF));
}
END_TEST

START_TEST(s21_pow_55) {
  ck_assert_ldouble_eq_tol(s21_pow(-S21_INF, -S21_INF), pow(-S21_INF, -S21_INF),
                           S21_EPS);
}
END_TEST

START_TEST(s21_pow_56) {
  ck_assert_ldouble_eq_tol(s21_pow(0.5, S21_INF), pow(0.5, S21_INF), S21_EPS);
}
END_TEST

START_TEST(s21_pow_57) {
  ck_assert_ldouble_infinite(s21_pow(0.5, -S21_INF));
  ck_assert_ldouble_infinite(pow(0.5, -S21_INF));
}
END_TEST

START_TEST(s21_pow_58) {
  ck_assert_ldouble_infinite(s21_pow(1.5, S21_INF));
  ck_assert_ldouble_infinite(pow(1.5, S21_INF));
}
END_TEST

START_TEST(s21_pow_59) {
  ck_assert_ldouble_eq_tol(s21_pow(1.5, -S21_INF), pow(1.5, -S21_INF), S21_EPS);
}
END_TEST

START_TEST(s21_pow_60) {
  ck_assert_ldouble_eq_tol(s21_pow(0.1, 0.000000001), pow(0.1, 0.000000001),
                           S21_EPS);
}
END_TEST

START_TEST(s21_pow_61) {
  ck_assert_ldouble_eq_tol(s21_pow(2.2, -2), pow(2.2, -2), S21_EPS);
}
END_TEST

START_TEST(s21_pow_62) {
  ck_assert_ldouble_eq_tol(s21_pow(2.2, -2.2), pow(2.2, -2.2), S21_EPS);
}
END_TEST

START_TEST(s21_pow_63) {
  ck_assert_ldouble_eq_tol(s21_pow(93.5, -83.5), pow(93.5, -83.5), S21_EPS);
}
END_TEST

START_TEST(s21_pow_64) {
  ck_assert_ldouble_infinite(s21_pow(1.5, S21_INF));
  ck_assert_ldouble_infinite(pow(1.5, S21_INF));
}
END_TEST

START_TEST(s21_pow_65) {
  ck_assert_ldouble_infinite(s21_pow(-S21_INF, 5));
  ck_assert_ldouble_infinite(pow(-S21_INF, 5));
}
END_TEST

START_TEST(s21_sin_1) {
  long double test_val = 1;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_2) {
  long double test_val = -1;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_3) {
  long double test_val = S21_NAN;
  ck_assert_ldouble_nan(s21_sin(test_val));
  ck_assert_ldouble_nan(sin(test_val));
}
END_TEST

START_TEST(s21_sin_4) {
  long double test_val = S21_INF;
  ck_assert_ldouble_nan(s21_sin(test_val));
  ck_assert_ldouble_nan(sin(test_val));
}
END_TEST

START_TEST(s21_sin_5) {
  long double test_val = -S21_INF;
  ck_assert_ldouble_nan(s21_sin(test_val));
  ck_assert_ldouble_nan(sin(test_val));
}
END_TEST

START_TEST(s21_sin_6) {
  long double test_val = -S21_NAN;
  ck_assert_ldouble_nan(s21_sin(test_val));
  ck_assert_ldouble_nan(sin(test_val));
}
END_TEST

START_TEST(s21_sin_7) {
  long double test_val = S21_PI;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_8) {
  long double test_val = -S21_PI;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_9) {
  long double test_val = 0.789789;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_10) {
  long double test_val = -0.789789;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_11) {
  long double test_val = 0;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_12) {
  long double test_val = S21_PI / 5;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_13) {
  long double test_val = -S21_PI / 5;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_14) {
  long double test_val = S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_15) {
  long double test_val = -S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_16) {
  long double test_val = S21_PI / 6;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_17) {
  long double test_val = -S21_PI / 6;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_18) {
  long double test_val = S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_19) {
  long double test_val = -S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_20) {
  long double test_val = 2 * S21_PI;
  ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_sin_21) {
  for (int i = 0; i < 5; ++i) {
    long double test_val = i * S21_PI;
    ck_assert_ldouble_eq_tol(s21_sin(test_val), sin(test_val), S21_EPS);
    long double test_val_m = -i * S21_PI;
    ck_assert_ldouble_eq_tol(s21_sin(test_val_m), sin(test_val_m), S21_EPS);
  }
}
END_TEST

START_TEST(s21_sin_22) {
  for (double i = -S21_PI; i <= S21_PI; i += 1.234567) {
    ck_assert_ldouble_eq_tol(sin(1234567890.123456 + i),
                             s21_sin(1234567890.123456 + i), S21_EPS);
  }
}
END_TEST

START_TEST(s21_sin_23) {
  for (double i = -S21_PI; i <= S21_PI; i += 1.234467) {
    ck_assert_ldouble_eq_tol(sin(-1234567890.123456 + i),
                             s21_sin(-1234567890.123456 + i), S21_EPS);
  }
}
END_TEST

START_TEST(s21_sin_24) {
  ck_assert_ldouble_eq_tol(s21_sin(9999999999.999999), sin(9999999999.999999),
                           S21_EPS);
}
END_TEST

START_TEST(s21_sqrt_1) {
  ck_assert_ldouble_eq_tol(s21_sqrt(4), sqrt(4), S21_EPS);
}
END_TEST

START_TEST(s21_sqrt_2) {
  ck_assert_ldouble_eq_tol(s21_sqrt(9), sqrt(9), S21_EPS);
}
END_TEST

START_TEST(s21_sqrt_3) {
  ck_assert_ldouble_eq_tol(s21_sqrt(44.44), sqrt(44.44), S21_EPS);
}
END_TEST

START_TEST(s21_sqrt_4) {
  ck_assert_ldouble_eq_tol(s21_sqrt(44.444444), sqrt(44.444444), S21_EPS);
}
END_TEST

START_TEST(s21_sqrt_5) { ck_assert_ldouble_eq(s21_sqrt(0), sqrt(0)); }
END_TEST

START_TEST(s21_sqrt_6) {
  ck_assert_ldouble_nan(sqrt(-1));
  ck_assert_ldouble_nan(s21_sqrt(-1));
}
END_TEST

START_TEST(s21_sqrt_7) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0.123123123123), sqrt(0.123123123123),
                           S21_EPS);
}
END_TEST

START_TEST(s21_sqrt_8) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0.999999999), sqrt(0.999999999), S21_EPS);
}
END_TEST

START_TEST(s21_sqrt_9) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0.123123123), sqrt(0.123123123), S21_EPS);
}
END_TEST

START_TEST(s21_sqrt_10) {
  ck_assert_ldouble_nan(s21_sqrt(-INFINITY));
  ck_assert_ldouble_nan(sqrt(-INFINITY));
}
END_TEST

START_TEST(s21_sqrt_11) {
  ck_assert_ldouble_nan(s21_sqrt(-7));
  ck_assert_ldouble_nan(sqrt(-7));
}
END_TEST

START_TEST(s21_sqrt_12) {
  ck_assert_ldouble_nan(s21_sqrt(NAN));
  ck_assert_ldouble_nan(sqrt(NAN));
}
END_TEST

START_TEST(s21_sqrt_13) {
  ck_assert_ldouble_eq_tol(s21_sqrt(159159159159.159159159),
                           sqrt(159159159159.159159159), S21_EPS);
}
END_TEST

START_TEST(s21_sqrt_14) {
  ck_assert_ldouble_nan(s21_sqrt(-159159159159.159159159));
  ck_assert_ldouble_nan(sqrt(-159159159159.159159159));
}
END_TEST

START_TEST(s21_sqrt_15) {
  ck_assert_ldouble_eq_tol(s21_sqrt(17.01), sqrt(17.01), S21_EPS);
}
END_TEST

START_TEST(s21_tan_1) {
  long double test_val = 1;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_2) {
  long double test_val = -1;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_3) {
  long double test_val = S21_NAN;
  ck_assert_ldouble_nan(s21_tan(test_val));
  ck_assert_ldouble_nan(tan(test_val));
}
END_TEST

START_TEST(s21_tan_4) {
  long double test_val = S21_INF;
  ck_assert_ldouble_nan(s21_tan(test_val));
  ck_assert_ldouble_nan(tan(test_val));
}
END_TEST

START_TEST(s21_tan_5) {
  long double test_val = -S21_INF;
  ck_assert_ldouble_nan(s21_tan(test_val));
  ck_assert_ldouble_nan(tan(test_val));
}
END_TEST

START_TEST(s21_tan_6) {
  long double test_val = -S21_NAN;
  ck_assert_ldouble_nan(s21_tan(test_val));
  ck_assert_ldouble_nan(tan(test_val));
}
END_TEST

START_TEST(s21_tan_7) {
  long double test_val = S21_PI;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_8) {
  long double test_val = -S21_PI;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_9) {
  long double test_val = 0.789789;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_10) {
  long double test_val = -0.789789;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_11) {
  long double test_val = 0;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_12) {
  long double test_val = S21_PI / 5;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_13) {
  long double test_val = -S21_PI / 5;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_14) {
  long double test_val = S21_PI / 2;
  ck_assert_ldouble_eq(s21_tan(test_val), tan(test_val));
}
END_TEST

START_TEST(s21_tan_15) {
  long double test_val = -S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_16) {
  long double test_val = S21_PI / 6;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_17) {
  long double test_val = -S21_PI / 6;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_18) {
  long double test_val = S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_19) {
  long double test_val = -S21_PI / 2;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_20) {
  long double test_val = 2 * S21_PI;
  ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
}
END_TEST

START_TEST(s21_tan_21) {
  for (int i = 0; i < 5; ++i) {
    long double test_val = i * S21_PI;
    ck_assert_ldouble_eq_tol(s21_tan(test_val), tan(test_val), S21_EPS);
    long double test_val_m = -i * S21_PI;
    ck_assert_ldouble_eq_tol(s21_tan(test_val_m), tan(test_val_m), S21_EPS);
  }
}
END_TEST

Suite *suite_insert(void) {
  Suite *s = suite_create("suite_insert");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, abs_1);
  tcase_add_test(tc, abs_2);
  tcase_add_test(tc, abs_3);

  tcase_add_test(tc, asin_1);
  tcase_add_test(tc, asin_2);
  tcase_add_test(tc, asin_3);

  tcase_add_test(tc, sin_1);
  tcase_add_test(tc, sin_2);
  tcase_add_test(tc, sin_3);
  tcase_add_test(tc, cos_1);
  tcase_add_test(tc, cos_2);
  tcase_add_test(tc, cos_3);
  tcase_add_test(tc, cos_4);
  tcase_add_test(tc, tan_1);
  tcase_add_test(tc, tan_2);
  tcase_add_test(tc, tan_3);
  tcase_add_test(tc, atan_1);
  tcase_add_test(tc, atan_2);
  tcase_add_test(tc, atan_3);
  tcase_add_test(tc, sqrt_0);

  tcase_add_test(tc, pow_1);
  tcase_add_test(tc, pow_2);
  tcase_add_test(tc, pow_3);
  tcase_add_test(tc, pow_4);
  tcase_add_test(tc, pow_5);
  tcase_add_test(tc, pow_6);
  tcase_add_test(tc, pow_7);
  tcase_add_test(tc, pow_8);
  tcase_add_test(tc, pow_9);
  tcase_add_test(tc, pow_10);
  tcase_add_test(tc, pow_11);
  tcase_add_test(tc, pow_12);
  tcase_add_test(tc, fabs_1);
  tcase_add_test(tc, fabs_2);
  tcase_add_test(tc, fabs_3);
  tcase_add_test(tc, fabs_4);
  tcase_add_test(tc, fabs_5);
  tcase_add_test(tc, fabs_6);
  tcase_add_test(tc, fabs_7);
  tcase_add_test(tc, fabs_8);
  tcase_add_test(tc, fabs_9);
  tcase_add_test(tc, fabs_10);
  tcase_add_test(tc, fabs_11);

  tcase_add_test(tc, ceil_1);
  tcase_add_test(tc, ceil_2);
  tcase_add_test(tc, ceil_3);
  tcase_add_test(tc, ceil_4);
  tcase_add_test(tc, ceil_5);
  tcase_add_test(tc, ceil_6);
  tcase_add_test(tc, ceil_7);
  tcase_add_test(tc, ceil_8);
  tcase_add_test(tc, ceil_9);
  tcase_add_test(tc, ceil_10);
  tcase_add_test(tc, ceil_11);
  tcase_add_test(tc, ceil_12);
  tcase_add_test(tc, ceil_13);

  tcase_add_test(tc, floor_1);
  tcase_add_test(tc, floor_2);
  tcase_add_test(tc, floor_3);
  tcase_add_test(tc, floor_4);
  tcase_add_test(tc, floor_5);
  tcase_add_test(tc, floor_6);
  tcase_add_test(tc, floor_7);
  tcase_add_test(tc, floor_8);
  tcase_add_test(tc, floor_9);
  tcase_add_test(tc, floor_10);
  tcase_add_test(tc, floor_11);
  tcase_add_test(tc, floor_12);
  tcase_add_test(tc, floor_13);
  tcase_add_test(tc, floor_14);

  tcase_add_test(tc, exp_1);
  tcase_add_test(tc, exp_2);
  tcase_add_test(tc, exp_3);
  tcase_add_test(tc, exp_4);
  tcase_add_test(tc, exp_5);
  tcase_add_test(tc, exp_6);
  tcase_add_test(tc, exp_7);
  tcase_add_test(tc, exp_8);

  tcase_add_test(tc, log_1);
  tcase_add_test(tc, log_2);
  tcase_add_test(tc, log_3);
  tcase_add_test(tc, log_4);
  tcase_add_test(tc, log_5);
  tcase_add_test(tc, log_6);

  ////////////////  ADDITIONAL  ///////////////
  tcase_add_test(tc, pow_test_1);
  tcase_add_test(tc, pow_test_2);
  tcase_add_test(tc, pow_test_3);
  tcase_add_test(tc, log_test_1);
  tcase_add_test(tc, log_test_2);
  tcase_add_test(tc, log_test_3);
  tcase_add_test(tc, log_test_4);
  tcase_add_test(tc, log_test_5);
  tcase_add_test(tc, sin_test_1);
  tcase_add_test(tc, cos_test_1);
  tcase_add_test(tc, tan_test_1);
  tcase_add_test(tc, sin_cos_tan_test);
  tcase_add_test(tc, exp_test_1);
  tcase_add_test(tc, exp_test_2);
  tcase_add_test(tc, exp_test_3);
  tcase_add_test(tc, exp_test_4);
  tcase_add_test(tc, asin_test_1);
  tcase_add_test(tc, asin_test_2);
  tcase_add_test(tc, acos_test_1);
  tcase_add_test(tc, acos_test_2);
  tcase_add_test(tc, atan_test_1);
  tcase_add_test(tc, atan_test_2);
  tcase_add_test(tc, asin_acos_atan_test);
  tcase_add_test(tc, sqrt_test_1);
  tcase_add_test(tc, sqrt_test_2);
  tcase_add_test(tc, abs_test);
  tcase_add_test(tc, fabs_test);
  tcase_add_test(tc, floor_test);
  tcase_add_test(tc, ceil_test);
  tcase_add_test(tc, fmod_test_1);

  /////////////////  ADDITIONAL II  ////////
  tcase_add_test(tc, s21_abs_1);
  tcase_add_test(tc, s21_abs_2);
  tcase_add_test(tc, s21_abs_3);
  tcase_add_test(tc, s21_abs_4);
  tcase_add_test(tc, s21_abs_5);
  tcase_add_test(tc, s21_abs_6);
  tcase_add_test(tc, s21_abs_7);
  tcase_add_test(tc, s21_abs_8);
  tcase_add_test(tc, s21_abs_9);
  tcase_add_test(tc, s21_abs_10);
  tcase_add_test(tc, s21_abs_11);
  tcase_add_test(tc, s21_abs_12);
  tcase_add_test(tc, s21_abs_13);
  tcase_add_test(tc, s21_abs_14);
  tcase_add_test(tc, s21_abs_15);

  tcase_add_test(tc, s21_acos_1);
  tcase_add_test(tc, s21_acos_2);
  tcase_add_test(tc, s21_acos_3);
  tcase_add_test(tc, s21_acos_4);
  tcase_add_test(tc, s21_acos_5);
  tcase_add_test(tc, s21_acos_6);
  tcase_add_test(tc, s21_acos_7);
  tcase_add_test(tc, s21_acos_8);
  tcase_add_test(tc, s21_acos_9);
  tcase_add_test(tc, s21_acos_10);
  tcase_add_test(tc, s21_acos_11);
  tcase_add_test(tc, s21_acos_12);
  tcase_add_test(tc, s21_acos_13);
  tcase_add_test(tc, s21_acos_14);
  tcase_add_test(tc, s21_acos_15);
  tcase_add_test(tc, s21_acos_16);
  tcase_add_test(tc, s21_acos_17);
  tcase_add_test(tc, s21_acos_18);
  tcase_add_test(tc, s21_acos_19);
  tcase_add_test(tc, s21_acos_20);
  tcase_add_test(tc, s21_acos_21);
  tcase_add_test(tc, s21_asin_1);
  tcase_add_test(tc, s21_asin_2);
  tcase_add_test(tc, s21_asin_3);
  tcase_add_test(tc, s21_asin_4);
  tcase_add_test(tc, s21_asin_5);
  tcase_add_test(tc, s21_asin_6);
  tcase_add_test(tc, s21_asin_7);
  tcase_add_test(tc, s21_asin_8);
  tcase_add_test(tc, s21_asin_9);
  tcase_add_test(tc, s21_asin_10);

  tcase_add_test(tc, s21_asin_11);
  tcase_add_test(tc, s21_asin_12);
  tcase_add_test(tc, s21_asin_13);
  tcase_add_test(tc, s21_asin_14);
  tcase_add_test(tc, s21_asin_15);
  tcase_add_test(tc, s21_asin_16);
  tcase_add_test(tc, s21_asin_17);
  tcase_add_test(tc, s21_asin_18);
  tcase_add_test(tc, s21_asin_19);
  tcase_add_test(tc, s21_asin_20);

  tcase_add_test(tc, s21_asin_21);

  tcase_add_test(tc, s21_atan_1);
  tcase_add_test(tc, s21_atan_2);
  tcase_add_test(tc, s21_atan_3);
  tcase_add_test(tc, s21_atan_4);
  tcase_add_test(tc, s21_atan_5);
  tcase_add_test(tc, s21_atan_6);
  tcase_add_test(tc, s21_atan_7);
  tcase_add_test(tc, s21_atan_8);
  tcase_add_test(tc, s21_atan_9);
  tcase_add_test(tc, s21_atan_10);
  tcase_add_test(tc, s21_atan_11);
  tcase_add_test(tc, s21_atan_12);
  tcase_add_test(tc, s21_atan_13);
  tcase_add_test(tc, s21_atan_14);
  tcase_add_test(tc, s21_atan_15);
  tcase_add_test(tc, s21_atan_16);
  tcase_add_test(tc, s21_atan_17);
  tcase_add_test(tc, s21_atan_18);
  tcase_add_test(tc, s21_atan_19);
  tcase_add_test(tc, s21_atan_20);
  tcase_add_test(tc, s21_atan_21);

  tcase_add_test(tc, s21_ceil_1);
  tcase_add_test(tc, s21_ceil_2);
  tcase_add_test(tc, s21_ceil_3);
  tcase_add_test(tc, s21_ceil_4);
  tcase_add_test(tc, s21_ceil_5);
  tcase_add_test(tc, s21_ceil_6);
  tcase_add_test(tc, s21_ceil_7);
  tcase_add_test(tc, s21_ceil_8);
  tcase_add_test(tc, s21_ceil_9);
  tcase_add_test(tc, s21_ceil_10);
  tcase_add_test(tc, s21_ceil_11);
  tcase_add_test(tc, s21_ceil_12);
  tcase_add_test(tc, s21_ceil_13);
  tcase_add_test(tc, s21_ceil_14);
  tcase_add_test(tc, s21_ceil_15);
  tcase_add_test(tc, s21_ceil_16);
  tcase_add_test(tc, s21_ceil_17);
  tcase_add_test(tc, s21_ceil_18);
  tcase_add_test(tc, s21_ceil_19);

  tcase_add_test(tc, s21_cos_1);
  tcase_add_test(tc, s21_cos_2);
  tcase_add_test(tc, s21_cos_3);
  tcase_add_test(tc, s21_cos_4);
  tcase_add_test(tc, s21_cos_5);
  tcase_add_test(tc, s21_cos_6);
  tcase_add_test(tc, s21_cos_7);
  tcase_add_test(tc, s21_cos_8);
  tcase_add_test(tc, s21_cos_9);
  tcase_add_test(tc, s21_cos_10);
  tcase_add_test(tc, s21_cos_11);
  tcase_add_test(tc, s21_cos_12);
  tcase_add_test(tc, s21_cos_13);
  tcase_add_test(tc, s21_cos_14);
  tcase_add_test(tc, s21_cos_15);
  tcase_add_test(tc, s21_cos_16);
  tcase_add_test(tc, s21_cos_17);
  tcase_add_test(tc, s21_cos_18);
  tcase_add_test(tc, s21_cos_19);
  tcase_add_test(tc, s21_cos_20);
  tcase_add_test(tc, s21_cos_21);
  tcase_add_test(tc, s21_cos_22);
  tcase_add_test(tc, s21_cos_23);
  tcase_add_test(tc, s21_cos_24);
  tcase_add_test(tc, s21_cos_25);
  tcase_add_test(tc, s21_exp_1);
  tcase_add_test(tc, s21_exp_2);
  tcase_add_test(tc, s21_exp_3);
  tcase_add_test(tc, s21_exp_4);
  tcase_add_test(tc, s21_exp_5);
  tcase_add_test(tc, s21_exp_6);
  tcase_add_test(tc, s21_exp_7);
  tcase_add_test(tc, s21_exp_8);
  tcase_add_test(tc, s21_exp_9);
  tcase_add_test(tc, s21_exp_10);
  tcase_add_test(tc, s21_exp_11);
  tcase_add_test(tc, s21_exp_12);
  tcase_add_test(tc, s21_exp_13);
  tcase_add_test(tc, s21_exp_14);
  tcase_add_test(tc, s21_exp_15);
  tcase_add_test(tc, s21_fabs_1);
  tcase_add_test(tc, s21_fabs_2);
  tcase_add_test(tc, s21_fabs_3);
  tcase_add_test(tc, s21_fabs_4);
  tcase_add_test(tc, s21_fabs_5);
  tcase_add_test(tc, s21_fabs_6);
  tcase_add_test(tc, s21_fabs_7);
  tcase_add_test(tc, s21_fabs_8);
  tcase_add_test(tc, s21_fabs_9);
  tcase_add_test(tc, s21_fabs_10);
  tcase_add_test(tc, s21_fabs_11);
  tcase_add_test(tc, s21_fabs_12);
  tcase_add_test(tc, s21_fabs_13);
  tcase_add_test(tc, s21_fabs_14);
  tcase_add_test(tc, s21_fabs_15);

  tcase_add_test(tc, s21_floor_1);
  tcase_add_test(tc, s21_floor_2);
  tcase_add_test(tc, s21_floor_3);
  tcase_add_test(tc, s21_floor_4);
  tcase_add_test(tc, s21_floor_5);
  tcase_add_test(tc, s21_floor_6);
  tcase_add_test(tc, s21_floor_7);
  tcase_add_test(tc, s21_floor_8);
  tcase_add_test(tc, s21_floor_9);
  tcase_add_test(tc, s21_floor_10);
  tcase_add_test(tc, s21_floor_11);
  tcase_add_test(tc, s21_floor_12);
  tcase_add_test(tc, s21_floor_13);
  tcase_add_test(tc, s21_floor_14);
  tcase_add_test(tc, s21_floor_15);
  tcase_add_test(tc, s21_floor_16);
  tcase_add_test(tc, s21_floor_17);
  tcase_add_test(tc, s21_floor_18);
  tcase_add_test(tc, s21_floor_19);
  tcase_add_test(tc, s21_floor_20);
  tcase_add_test(tc, s21_floor_21);

  tcase_add_test(tc, s21_fmod_1);
  tcase_add_test(tc, s21_fmod_2);
  tcase_add_test(tc, s21_fmod_3);
  tcase_add_test(tc, s21_fmod_4);
  tcase_add_test(tc, s21_fmod_5);
  tcase_add_test(tc, s21_fmod_6);
  tcase_add_test(tc, s21_fmod_7);
  tcase_add_test(tc, s21_fmod_8);
  tcase_add_test(tc, s21_fmod_9);
  tcase_add_test(tc, s21_fmod_10);
  tcase_add_test(tc, s21_fmod_11);
  tcase_add_test(tc, s21_fmod_12);
  tcase_add_test(tc, s21_fmod_13);
  tcase_add_test(tc, s21_fmod_14);
  tcase_add_test(tc, s21_fmod_15);
  tcase_add_test(tc, s21_fmod_16);
  tcase_add_test(tc, s21_fmod_17);
  tcase_add_test(tc, s21_fmod_18);
  tcase_add_test(tc, s21_fmod_19);
  tcase_add_test(tc, s21_fmod_20);
  tcase_add_test(tc, s21_fmod_21);
  tcase_add_test(tc, s21_fmod_22);
  tcase_add_test(tc, s21_fmod_23);
  tcase_add_test(tc, s21_fmod_24);
  tcase_add_test(tc, s21_fmod_25);
  tcase_add_test(tc, s21_fmod_26);
  tcase_add_test(tc, s21_fmod_27);
  tcase_add_test(tc, s21_log_1);
  tcase_add_test(tc, s21_log_2);
  tcase_add_test(tc, s21_log_3);
  tcase_add_test(tc, s21_log_4);
  tcase_add_test(tc, s21_log_5);
  tcase_add_test(tc, s21_log_6);
  tcase_add_test(tc, s21_log_7);
  tcase_add_test(tc, s21_log_8);
  tcase_add_test(tc, s21_log_9);
  tcase_add_test(tc, s21_log_10);
  tcase_add_test(tc, s21_log_11);
  tcase_add_test(tc, s21_log_12);
  tcase_add_test(tc, s21_log_13);
  tcase_add_test(tc, s21_log_14);
  tcase_add_test(tc, s21_log_15);
  tcase_add_test(tc, s21_log_16);
  tcase_add_test(tc, s21_log_17);
  tcase_add_test(tc, s21_log_18);

  tcase_add_test(tc, s21_pow_1);
  tcase_add_test(tc, s21_pow_2);
  tcase_add_test(tc, s21_pow_3);
  tcase_add_test(tc, s21_pow_4);
  tcase_add_test(tc, s21_pow_5);
  tcase_add_test(tc, s21_pow_6);
  tcase_add_test(tc, s21_pow_7);
  tcase_add_test(tc, s21_pow_8);
  tcase_add_test(tc, s21_pow_9);
  tcase_add_test(tc, s21_pow_10);
  tcase_add_test(tc, s21_pow_11);
  tcase_add_test(tc, s21_pow_12);
  tcase_add_test(tc, s21_pow_13);
  tcase_add_test(tc, s21_pow_14);
  tcase_add_test(tc, s21_pow_15);
  tcase_add_test(tc, s21_pow_16);
  tcase_add_test(tc, s21_pow_17);
  tcase_add_test(tc, s21_pow_18);
  tcase_add_test(tc, s21_pow_19);
  tcase_add_test(tc, s21_pow_20);
  tcase_add_test(tc, s21_pow_21);
  tcase_add_test(tc, s21_pow_22);
  tcase_add_test(tc, s21_pow_23);
  tcase_add_test(tc, s21_pow_24);
  tcase_add_test(tc, s21_pow_25);
  tcase_add_test(tc, s21_pow_26);
  tcase_add_test(tc, s21_pow_27);
  tcase_add_test(tc, s21_pow_28);
  tcase_add_test(tc, s21_pow_29);
  tcase_add_test(tc, s21_pow_30);
  tcase_add_test(tc, s21_pow_31);
  tcase_add_test(tc, s21_pow_32);
  tcase_add_test(tc, s21_pow_33);
  tcase_add_test(tc, s21_pow_34);
  tcase_add_test(tc, s21_pow_35);
  tcase_add_test(tc, s21_pow_36);
  tcase_add_test(tc, s21_pow_37);
  tcase_add_test(tc, s21_pow_38);
  tcase_add_test(tc, s21_pow_39);
  tcase_add_test(tc, s21_pow_40);
  tcase_add_test(tc, s21_pow_41);
  tcase_add_test(tc, s21_pow_42);
  tcase_add_test(tc, s21_pow_43);
  tcase_add_test(tc, s21_pow_44);
  tcase_add_test(tc, s21_pow_45);
  tcase_add_test(tc, s21_pow_46);
  tcase_add_test(tc, s21_pow_47);
  tcase_add_test(tc, s21_pow_48);
  tcase_add_test(tc, s21_pow_49);
  tcase_add_test(tc, s21_pow_50);
  tcase_add_test(tc, s21_pow_51);
  tcase_add_test(tc, s21_pow_52);
  tcase_add_test(tc, s21_pow_53);
  tcase_add_test(tc, s21_pow_54);
  tcase_add_test(tc, s21_pow_55);
  tcase_add_test(tc, s21_pow_56);
  tcase_add_test(tc, s21_pow_57);
  tcase_add_test(tc, s21_pow_58);
  tcase_add_test(tc, s21_pow_59);
  tcase_add_test(tc, s21_pow_60);
  tcase_add_test(tc, s21_pow_61);
  tcase_add_test(tc, s21_pow_62);
  tcase_add_test(tc, s21_pow_63);
  tcase_add_test(tc, s21_pow_64);
  tcase_add_test(tc, s21_pow_65);

  tcase_add_test(tc, s21_sin_1);
  tcase_add_test(tc, s21_sin_2);
  tcase_add_test(tc, s21_sin_3);
  tcase_add_test(tc, s21_sin_4);
  tcase_add_test(tc, s21_sin_5);
  tcase_add_test(tc, s21_sin_6);
  tcase_add_test(tc, s21_sin_7);
  tcase_add_test(tc, s21_sin_8);
  tcase_add_test(tc, s21_sin_9);
  tcase_add_test(tc, s21_sin_10);

  tcase_add_test(tc, s21_sin_11);
  tcase_add_test(tc, s21_sin_12);
  tcase_add_test(tc, s21_sin_13);
  tcase_add_test(tc, s21_sin_14);
  tcase_add_test(tc, s21_sin_15);
  tcase_add_test(tc, s21_sin_16);
  tcase_add_test(tc, s21_sin_17);
  tcase_add_test(tc, s21_sin_18);
  tcase_add_test(tc, s21_sin_19);
  tcase_add_test(tc, s21_sin_20);

  tcase_add_test(tc, s21_sin_21);
  tcase_add_test(tc, s21_sin_22);
  tcase_add_test(tc, s21_sin_23);
  tcase_add_test(tc, s21_sin_24);

  tcase_add_test(tc, s21_sqrt_1);
  tcase_add_test(tc, s21_sqrt_2);
  tcase_add_test(tc, s21_sqrt_3);
  tcase_add_test(tc, s21_sqrt_4);
  tcase_add_test(tc, s21_sqrt_5);
  tcase_add_test(tc, s21_sqrt_6);
  tcase_add_test(tc, s21_sqrt_7);
  tcase_add_test(tc, s21_sqrt_8);
  tcase_add_test(tc, s21_sqrt_9);
  tcase_add_test(tc, s21_sqrt_10);
  tcase_add_test(tc, s21_sqrt_11);
  tcase_add_test(tc, s21_sqrt_12);
  tcase_add_test(tc, s21_sqrt_13);
  tcase_add_test(tc, s21_sqrt_14);
  tcase_add_test(tc, s21_sqrt_15);

  tcase_add_test(tc, s21_tan_1);
  tcase_add_test(tc, s21_tan_2);
  tcase_add_test(tc, s21_tan_3);
  tcase_add_test(tc, s21_tan_4);
  tcase_add_test(tc, s21_tan_5);
  tcase_add_test(tc, s21_tan_6);
  tcase_add_test(tc, s21_tan_7);
  tcase_add_test(tc, s21_tan_8);
  tcase_add_test(tc, s21_tan_9);
  tcase_add_test(tc, s21_tan_10);
  tcase_add_test(tc, s21_tan_11);
  tcase_add_test(tc, s21_tan_12);
  tcase_add_test(tc, s21_tan_13);
  tcase_add_test(tc, s21_tan_14);
  tcase_add_test(tc, s21_tan_15);
  tcase_add_test(tc, s21_tan_16);
  tcase_add_test(tc, s21_tan_17);
  tcase_add_test(tc, s21_tan_18);
  tcase_add_test(tc, s21_tan_19);
  tcase_add_test(tc, s21_tan_20);
  tcase_add_test(tc, s21_tan_21);
  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  /* We create variable no_failed to store the number of failed tests: */
  int no_failed = 0;
  /* We declare s as a pointer to a Suite and call on function in order to
   * create and return our test suite: */
  Suite *s = suite_insert();
  /* We pass our newly created test suite to the function srunner_create in
   * order to get a pointer to a test suite runner */
  SRunner *sr = srunner_create(s);
  /* This function will run our test suite and check our assertions, CK_VERBOSE
   * used to show all tests,  use CK_NORMAL instead to see only failed ones: */
  srunner_run_all(sr, CK_VERBOSE);
  /* To extract the number of failed tests: */
  no_failed = srunner_ntests_failed(sr);
  /* We free any memory that was allocated due to our runner: */
  srunner_free(sr);
  /* We return if the number of failed tests is 0 else we fail the test run */
  return no_failed == 0 ? 0 : 1;

  /*  for mor information check
  https://www.ccs.neu.edu/home/skotthe/classes/cs5600/fall/2015/labs/intro-check.html
  or https://check.sourceforge.net/doc/doxygen/html/check_8h.html  */
}
