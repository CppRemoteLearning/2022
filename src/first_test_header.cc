#include "../include/first_test_header.h"
#include <iostream>

void PrintOutText(const std::string& text)
{
  std::cout << text;
}

void PrintOutTextAndValue(const std::string& text, const int& value)
{
  std::cout << text << value << "\n";
}

int CalculateSumOfNInRange(const int& beg, const int& end)
{
  return end*(end+1)/2 - beg*(beg+1)/2 + beg;
}

double CeliusToFahrenheit(const double& celsius)
{
  return celsius * 1.8 + 32;
}