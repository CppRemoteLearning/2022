#include "include/first_test_header.h"
#include <iostream>

int main()
{
  int beg = 5;
  int end = 10;
  int sum = CalculateSumOfNInRange(beg, end);
  PrintOutTextAndValue("The sum is = ", sum);
}