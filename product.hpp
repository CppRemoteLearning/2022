#pragma once
#include <iostream>
#include <string>
using namespace std;

class Product {
    string name;
    double price;
    public:
    //Constructors
    Product();
    Product(string name_, double price_);
    //Copy constructor
    Product(const Product& p);

    //Copy assignment operator
    Product& operator=(const Product& p);
    //Destructor
    ~Product();

    //Move constructor
    Product(const Product&& p);

    //Move assignment operator called
    Product& operator=(const Product&& p);

    //setters
    void setName(const string& name_);
    void setPrice(double price_);

    //getters
    const string& getName() const;
    double getPrice() const;
};
