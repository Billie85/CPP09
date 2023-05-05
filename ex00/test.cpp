#include <iostream>
#include <iomanip>
#include <cfloat>
#include <cmath>

int main()
{
  std::cout << std::setprecision(DBL_DIG);
  std::cout << DBL_MIN << '\n';

  // 以下の式と等価
  std::cout << std::pow(FLT_RADIX, DBL_MIN_EXP - 1) << '\n';
}