#include "Product.h"
#include <sstream>

Product::Product(std::string _name, int _weight): name(_name), weight(_weight)
{
}

Product &Product::operator=(Product const &p){
    if(this == &p) {
        return *this;
    }
    this->name = p.name;
    this->weight = p.weight;
    return *this;
}

Product &Product::operator=(Product &&p) noexcept
{
    if(this == &p) {
        return *this;
    }
    this->name = std::move(p.name); 
    this->weight = p.weight;
    return *this;
}

bool Product::operator==(Product const &p) const{
    return this->name == p.name && this->weight == p.weight;
}

std::ostream &operator<<(std::ostream &writer, const Product &product)
{
    writer << product.getName() << ", ";
    writer << product.getWeight();

    return writer;
}

std::istream &operator>>(std::istream &reader, Product &product)
{
    std::string line;
    std::getline(reader, line);
    if (line.empty())
        return reader;
    std::stringstream stream(line);

    std::string _name;
    std::string _weight;

    std::getline(stream, _name, ',');
    std::getline(stream, _weight, ',');
    
    product = Product(_name, std::stoi(_weight));
    return reader;
}

std::string Product::getName() const {
    return this->name;
}

int Product::getWeight() const {
    return this->weight;
}

void Product::setName(std::string _name)
{
    this->name = _name;
}

void Product::setWeight(int _weight)
{
    this->weight = _weight;
}

Product::~Product()
{
}

