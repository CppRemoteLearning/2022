#include "Store.h"
#include <iostream>
#include <string.h>
#include <vector>

Store::Store() {
    name = "-";
}

Store::Store(std::string name, std::vector<Product> products) {
    name = name;
    products = products;
    std::cout << "Store created: Name = " << name << std::endl;
}

std::string Store::getName() {
    return name;
}

std::vector<Product> Store::getProducts() {
    return products;
}

void Store::setName(std::string name) {
    name = name;
}

void Store::setProducts(std::vector<Product> products) {
    products = products;
}

std::string Store::toString() {
    std::string stringOfProducts;
    for(Product product : products) {
        stringOfProducts += product.toString();
    }
    std::cout << stringOfProducts;
    return "Store: Name = " + name + stringOfProducts;
}

