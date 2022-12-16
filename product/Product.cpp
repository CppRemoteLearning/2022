#include "Product.h"
#include <iostream>
#include <string.h>

Product::Product(): name("-"), price(0), quantity(0) {}

Product::Product(std::string name, float price, int quantity): name(name), price(price), quantity(quantity) {
    std::cout << "Product created: Name = " << name << ", Price = " << price << ", Quantity = " << quantity << std::endl; 
} 

Product::Product(const Product &p): name(p.name), price(p.price), quantity(p.quantity) {}  // Copy Constructor

Product::Product(Product&& p) = default; // Move Constructor

Product& Product::operator=(const Product &p) { // Copy Assignment Operator
    name = p.name;
    price = p.price;
    quantity = p.quantity;
    return *this;
} 

Product& Product::operator=(Product &&p) = default;  // Move Assignment Operator

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

void Product::setName(std::string name) {
    name = name;
}

void Product::setPrice(float price) {
    price = price;
}

void Product::setQuantity(int quantity) {
    quantity = quantity;
}

std::string Product::toString() {
    return "Product: Name = " + name + ", Price = " + std::to_string(price) + ", Quantity = " + std::to_string(quantity) + "\n";
}