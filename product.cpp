#include "product.hpp"

//Constructors
Product::Product(std::string name_, double price_) : name(name_), price(price_) {}

//Copy constructor
Product::Product(const Product& p) : name(p.name), price(p.price) 
{ 
    std::cout << "copy constructor called\n"; 
}

//Copy assignment operator
Product& Product::operator=(const Product& p)
{
    std::cout << "copy assignment operator called\n";
    if (this == &p)
        return *this;
    name = p.name;
    price = p.price;
    return *this;
}
//Destructor
Product::~Product()
{
    std::cout << "destructor called\n";
}

//Move constructor
Product::Product(const Product&& p) : name(std::move(p.name)), price(std::move(p.price))
{
    std::cout << "move constructor called\n";
}
//Move assignment operator called
Product& Product::operator=(const Product&& p)
{
    std::cout << "move assignment operator called\n";
    if (this == &p)
        return *this;
    name = p.name;
    price = p.price;
    return *this;
}
//setters
void Product::setName(const std::string& name_) 
{ 
    name = name_; 
}

void Product::setPrice(double price_)
{ 
    price = price_; 
}

//getters
const std::string& Product::getName() const 
{
    return name;
}

double Product::getPrice() const 
{
    return price;
}

