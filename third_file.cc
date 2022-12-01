#include "include/first_test_header.h"
#include <iostream>

int main()
{
  double celsius = 68.5;
  double fahrenheit = CeliusToFahrenheit(celsius);
  std::cout << celsius << " in fahrenheit = " << fahrenheit << "\n";
}