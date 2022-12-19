#include "include/first_test_header.h"
#include <iostream>

int main()
{
  int beg = 5, end = 10;
  std::cout << "The sum between: " << beg << " " << end << " = " <<  CalculateSumOfNInRange(beg, end) << "\n";
  double celsius = 68.5;
  std::cout << celsius << "in Fahrenheit = " << CeliusToFahrenheit(celsius);
}