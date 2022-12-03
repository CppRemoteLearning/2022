
#include <iostream>

#include "math_function.h"

int main(){

	int a, b;
	std::cout << "Calculul factorialului" << std::endl;
	std::cout << "nr. = ";
	std::cin >> a;
	std::cout << a << "! = " << factorial_recursiv(a) << "\n\n";

	std::cout << "Calculul c.m.m.d.c-ului" << std::endl; 
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;
	std::cout << "c.m.m.d.c dintre " << a << " si " << b << " este " << euclide_recursiv(a,b) << std::endl;
	return 0;
}
