#pragma once
#include <iostream>
#include <vector>
#include "product.h"

class Store {
    public:
    friend std::ostream& operator<<(std::ostream& os, const Store& store_out);
    Store(std::vector<Product> data_);
    Store (const Store &other);
    Store& operator=(Store &other);
    Store() {}
    // MOVE CONSTRUCT
    Store(Store&& other) noexcept;
    Store* operator=(Store&& other) noexcept;
    ~Store();
    const std::vector<Product>& getData() const;
    int size();
    bool addProduct(Product p);
    bool delProduct(std::string product_name);
    bool isAlready(std::string product_name);
    bool isEmpty();
    bool displayProduct(std::string searchName);
    void display();
    private:
    std::vector<Product> data;
};