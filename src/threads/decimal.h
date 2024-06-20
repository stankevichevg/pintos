typedef struct
{
  signed int value;
} decimal;

enum rounding
{
  ZERO,
  NEAREST
};

decimal to_decimal(int integer);
int to_int(decimal dec, enum rounding rounding_mode);
decimal sum(decimal a, decimal b);
decimal sum_int(decimal a, int b);
decimal subtract(decimal a, decimal b);
decimal subtract_int(decimal a, int b);
decimal mult(decimal a, decimal b);
decimal mult_int(decimal a, int b);
decimal div(decimal a, decimal b);
decimal div_int(decimal a, int b);
