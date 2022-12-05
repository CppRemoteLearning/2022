#include <iostream>
#include "functii.h"

int main()
{
    int a, b, x;

    cout << "a = ";
    cin >> a;

    cout << "b = ";
    cin >> b;

    cout << "Suma este: " << suma(a, b) << endl;

    cout << "Introduceti numarul pe care doriti sa il verificati daca este nr Armstrong: ";
    cin >> x;
    armstrong(x);
}