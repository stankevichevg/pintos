#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/decimal.c"

void test_to_decimal(void)
{
  // given
  int integers[] = {0, 1, 3, -1, -3, 131071, -131072, 131072, -131073};
  int length = sizeof(integers) / sizeof(integers[0]);
  decimal actual[length];

  // when
  for (int i = 0; i < length; i++)
  {
    actual[i] = to_decimal(integers[i]);
  }

  // then
  for (int i = 0; i < length; i++)
  {
    msg("Actual %i", actual[i]);
  }
}

void test_to_int_rounding_zero(void)
{
  // given
  decimal decimals[] = {0, 16384, 49152, -16384, -49152, 2147467264, -2147483648};
  int length = sizeof(decimals) / sizeof(decimals[0]);
  int actual[length];

  // when
  for (int i = 0; i < length; i++)
  {
    actual[i] = to_int(decimals[i], ZERO);
  }

  // then
  for (int i = 0; i < length; i++)
  {
    msg("Actual %i", actual[i]);
  }
}

void test_to_int_rounding_nearest(void)
{
  // given
  decimal decimals[] = {0, 16384, 49152, -16384, -49152, 2147467264, -2147475455};
  int length = sizeof(decimals) / sizeof(decimals[0]);
  int actual[length];

  // when
  for (int i = 0; i < length; i++)
  {
    actual[i] = to_int(decimals[i], NEAREST);
  }

  // then
  for (int i = 0; i < length; i++)
  {
    msg("Actual %i", actual[i]);
  }
}

void test_multiple_operations(void)
{
  // given

  // when
  // (((((((123 + 321) - (234 + 432)) - 55) * 3) * 4) / 7) / 9)
  decimal dec = div_int(
          div(
              mult_int(
                  mult(
                      subtract_int(
                          subtract(
                              sum(
                                  to_decimal(123),
                                  to_decimal(321)),
                              sum_int(
                                  to_decimal(234),
                                  432)),
                          55),
                      to_decimal(3)),
                  4),
              to_decimal(7)),
          9);

  // then
  int actual_round_to_zero = to_int(dec, ZERO);
  int actual_round_to_nearest = to_int(dec, NEAREST);
  msg("Actual %i", actual_round_to_zero);
  msg("Actual %i", actual_round_to_nearest);
}
