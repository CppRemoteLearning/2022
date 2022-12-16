#include "Product.h"

Product::Product(): name("-"), price(0), quantity(0) {}

Product::Product(std::string name, float price, int quantity): name(name), price(price), quantity(quantity) {
    std::cout << "Product created: Name = " << name << ", Price = " << price << ", Quantity = " << quantity << std::endl; 
} 

Product::Product(const Product &other): name(other.name), price(other.price), quantity(other.quantity) {}  // Copy Constructor

Product::Product(Product&& other) noexcept { // Move Constructor
    this->name = std::move(other.name);
    this->price = std::move(other.price);
    this->quantity = std::move(other.quantity);
}

Product &Product::operator=(const Product &other) { // Copy Assignment Operator
    this->name = other.name;
    this->price = other.price;
    this->quantity = other.quantity;
    return *this;
} 

Product& Product::operator=(Product&& other) noexcept { // Move Assignment Operator
    this->name = std::move(other.name);
    this->price = std::move(other.price);
    this->quantity = std::move(other.quantity);
    return *this;
}

Product::~Product() {}  // Destructor

std::string Product::getName() {
    return name;
}

float Product::getPrice() {
    return price;
}

int Product::getQuantity() {
    return quantity;
}

void Product::setName(std::string _name) {
    name = _name;
}

void Product::setPrice(float _price) {
    price = _price;
}

void Product::setQuantity(int _quantity) {
    quantity = _quantity;
}

std::string Product::toString() {
    return "Product: Name = " + name + ", Price = " + std::to_string(price) + ", Quantity = " + std::to_string(quantity) + "\n";
}