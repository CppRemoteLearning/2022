#include "headers/Product.h"
#include <ostream>

Product& Product::operator=(const Product& other)
{
    //copy
    if(this != &other)
    {
        Name = other.Name;
        Price = other.Price;
        Quantity = other.Quantity;
    }
    return *this;
}

Product& Product::operator=(Product&& other)
{
    //move
    if(this != &other)
    {
        Name = std::move(other.Name);
        Price = other.Price;
        Quantity = other.Quantity;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Product& product)
{
    os << product.Name << ": Price->"<<product.Price<<", Quantity->"<<product.Quantity;
    return os;
}
