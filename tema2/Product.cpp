#include "headers/Product.h"
#include <iostream>

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
