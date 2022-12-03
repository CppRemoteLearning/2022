#include "math_function.h"

int factorial_recursiv(int n){
	if(n==0)
		return 1;

	return n*factorial_recursiv(n-1);
}
