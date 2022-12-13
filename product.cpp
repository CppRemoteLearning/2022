#include "store.hpp"

//Constructors
Product::Product(string name_, double price_) : name(name_), price(price_) {}

Product:://Copy constructor
Product::Product(const Product& p) : name(p.name), price(p.price) 
{ cout << "copy constructor called\n"; }
//Copy assignment operator
Product& Product::operator=(const Product& p)
{
    cout << "copy assignment operator called\n";
    if (this == &p)
        return *this;
    name = p.name;
    price = p.price;
    return *this;
}
//Destructor
Product::~Product()
{
    cout << "destructor called\n";
}

//Move constructor
Product::Product(const Product&& p) : name(move(p.name)), price(move(p.price))
{
    cout << "move constructor called\n";
}
//Move assignment operator called
Product& Product::operator=(const Product&& p)
{
    cout << "move assignment operator called\n";
    if (this == &p)
        return *this;
    name = p.name;
    price = p.price;
    return *this;
}
//setters
void Product::setName(const string& name_) { name = name_; }
void Product::setPrice(double price_){ price = price_; }
//getters
const string& Product::getName() const {return name;}
double Product::getPrice() const {return price;}

