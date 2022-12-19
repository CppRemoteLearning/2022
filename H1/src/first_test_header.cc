#include "../include/first_test_header.h"

int CalculateSumOfNInRange(const int& beg, const int& end)
{
  return end*(end+1)/2 - beg*(beg+1)/2 + beg;
}