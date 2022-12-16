#include "product.h"

Produs& Produs::operator=(const Produs& other)
{
    id = other.id;
    nume = other.nume;
    tip = other.tip;
    pret = other.pret;
    
    return *this;
}

Produs& Produs::operator=(Produs&& other)
{
    id = other.id;
    nume = std::move(other.nume);
    tip = std::move(other.tip);
    pret = other.pret;
    
    return *this;
}

std::string Produs::getNume()
{
    return nume;
}

std::string Produs::getTip()
{
    return tip;
}

int Produs::getId()
{
    return id;
}

double Produs::getPret()
{
    return pret;
}
