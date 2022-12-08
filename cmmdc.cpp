#include "functions.h"

int cmmdc(int a, int b)
{
    if (a==b)
        return a;
    if (a>b)
        return cmmdc(a-b, b);
    else
        return cmmdc(a, b-a);
}