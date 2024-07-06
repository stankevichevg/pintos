#include <stdio.h>
#include "decimal.h"

#define SIGNED_INT_BITS_WITHOUT_SIGN 31
#define DECIMAL_BYTES 17
#define FRACTIONAL_BYTES (SIGNED_INT_BITS_WITHOUT_SIGN - DECIMAL_BYTES)

static int f = 1 << FRACTIONAL_BYTES;
static int MAX_SUPPORTED_VALUE = (1 << DECIMAL_BYTES) - 1;
static int MIN_SUPPORTED_VALUE = -(1 << DECIMAL_BYTES);

/*
    https://pkuflyingpig.gitbook.io/pintos/appendix/4.4bsd-scheduler#fixed-point-summary
*/
decimal to_decimal(int integer)
{
    if (integer > MAX_SUPPORTED_VALUE || integer < MIN_SUPPORTED_VALUE)
    {
        // PANIC("Number is out of range of real arithmetic: '%i' ", integer);
        decimal dec = {-1};
        return dec;
    }
    decimal dec = {integer * f};
    return dec;
}

int to_int(decimal dec, enum rounding rounding_mode)
{
    if (rounding_mode == ZERO)
    {
        return dec.value / f;
    }
    if (rounding_mode == NEAREST)
    {
        if (dec.value > 0)
        {
            return (dec.value + f / 2) / f;
        }
        else
        {
            return (dec.value - f / 2) / f;
        }
    }
    PANIC("Unhandled rounding mode: '%s' ", rounding_mode);
}

decimal sum(decimal a, decimal b)
{
    decimal dec = {a.value + b.value};
    return dec;
}

decimal sum_int(decimal a, int b)
{
    return sum(a, to_decimal(b));
}

decimal subtract(decimal a, decimal b)
{
    decimal dec = {-b.value};
    return sum(a, dec);
}

decimal subtract_int(decimal a, int b)
{
    return sum_int(a, -b);
}

decimal mult(decimal a, decimal b)
{
    decimal dec = {((int64_t)a.value) * to_int(b, ZERO)};
    return dec;
}

decimal mult_int(decimal a, int b)
{
    decimal dec = {a.value * b};
    return dec;
}

decimal div(decimal a, decimal b)
{
    decimal dec = {((int64_t)a.value) * f / b.value};
    return dec;
}

decimal div_int(decimal a, int b)
{
    decimal dec = {a.value / b};
    return dec;
}