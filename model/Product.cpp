#include "Product.h"

Product::Product(std::string _name, int _weight): name(_name), weight(_weight)
{
}

Product& Product::operator=(Product const& p){
    this->name = p.name;
    this->weight = p.weight;
    return *this;
}


bool Product::operator==(Product const& p) const{
    return this->name == p.name && this->weight == p.weight;
}

std::string Product::getName(){
    return this->name;
}

int Product::getWeight(){
    return this->weight;
}

Product::~Product()
{
}

