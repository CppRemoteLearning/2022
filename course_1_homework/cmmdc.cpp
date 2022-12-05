#include "math_function.h"

int euclide_recursiv(int a, int b){
	if(!b)
		return a;
	return euclide_recursiv(b, a%b);
}
