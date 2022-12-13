#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "product.hpp"
using namespace std;

class Store {
    string name;
    vector<Product> products;
    public:
    //Constructors
    Store();
    Store(string name_);
    Store(string name_, vector<Product> p);

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
    void setName(string name_);
    void setProducts(vector<Product> p);

    //getters
    const string& getName();
    const vector<Product>& getProducts();

    //TO DO: add code to read from a file
    void addProducts();
    void printProducts();
};