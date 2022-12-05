#include "functii.h"

void armstrong(int n)
{
    int r, suma = 0, k; k = n;
    while (n > 0) {
        r = n % 10; suma = suma + (r * r * r); n = n / 10;}
    if (k == suma) cout << "Nr Armstrong" << endl;
    else cout << "Numarul adaugat nu este nr Armstrong" << endl;
}