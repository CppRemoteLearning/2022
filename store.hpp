#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "product.hpp"

class Store {
    public:
        //Constructors
        Store();
        Store(std::string name_);
        Store(std::string name_, std::vector<Product> p);

        //Copy constructor
        Store(const Store& s);

        //Copy assignment operator
        Store& operator=(const Store& s);

        //Destructor
        ~Store();

        //Move constructor
        Store(const Store&& s);

        //Move assignment operator
        Store& operator=(const Store&& s);

        //setters
        void setName(std::string name_);
        void setProducts(std::vector<Product> p);

        //getters
        const std::string& getName();
        const std::vector<Product>& getProducts();

        void addProducts(const Product p);
        void printProducts();
        
    private:
        std::string name;
        std::vector<Product> products;
};