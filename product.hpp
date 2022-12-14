#pragma once
#include <iostream>
#include <string>


class Product {
    private:
        std::string name;
        double price;
    public:
        //Constructors
        Product();
        Product(std::string name_, double price_);
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
        void setName(const std::string& name_);
        void setPrice(double price_);

        //getters
        const std::string& getName() const;
        double getPrice() const;
};
