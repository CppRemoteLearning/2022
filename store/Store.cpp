#include "Store.h"

Store::Store() {
    name = "-";
}

Store::Store(std::string givenName, std::vector<Product> givenProducts) {
    name = givenName;
    products = givenProducts;
    std::string productNames;
    for(Product product : products) {
        productNames += product.getName() + " ";
    }
    std::cout << "Store created: Name = " << name << ", Products = " << productNames << std::endl;
}

std::string Store::getName() {
    return name;
}

std::vector<Product> Store::getProducts() {
    return products;
}

void Store::setName(std::string _name) {
    name = name;
}

void Store::setProducts(std::vector<Product> _products) {
    products = products;
}

std::string Store::toString() {
    std::string stringOfProducts;
    for(Product product : products) {
        stringOfProducts += product.toString();
    }
    return "Store: Name = " + name + ", containing the following products:\n" + stringOfProducts;
}