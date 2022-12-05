#include <iostream>

#include "math_function.h"

int main(){
	int a=10, b=12;
	std::cout << a << "! = " << factorial_recursiv(a) << std::endl;
	std::cout << "c.m.m.d.c dintre " << a << " si " << b << " este " << euclide_recursiv(a,b) << std::endl;
	return 0;
}
