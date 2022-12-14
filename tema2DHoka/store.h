#pragma once
#include <iostream>
#include <vector>
#include "product.h"
using namespace std;

class Store {
    vector<Product> data;
    public:
    Store(vector<Product> data_) : data(data_) {
        cout << "S-au construit datele unui store\n";
    }
    Store (const Store &other) : data(other.data) {
        cout << "S-au copiat datele unui store\n";
    }
    Store& operator=(Store &other) {
        cout << "S-a atribuit data unui store\n";
        data = other.getData();
        return *this;
    }
    Store() {}
    // MOVE CONSTRUCT
    Store(Store&& other) noexcept {
        cout << "Move constructor apelat\n";
        data=other.getData();
        // other.~Store();
    }
    Store* operator=(Store&& other) noexcept {
        cout << "Move assignment operator apelat\n";
        if (this != &other) {
            data.clear();
            data = other.getData();
            // other.~Store();
        }
        return this;
    }
    vector<Product>& getData() { return data; }
    int size() {
        return data.size();
    }
    bool addProduct(Product p);
    bool delProduct(string product_name);
    bool isAlready(string product_name);
    bool isEmpty() {    return size() < 1; }

    bool displayProduct(string searchName);

    friend ostream& operator<<(ostream& os, Store& store_out) {
        os << "\n-------- Store content --------\n";
        for (auto itr = store_out.data.begin(); itr != store_out.data.end(); ++itr) {
            os << *itr;
        }
        return os;
    }
    void display() {
        for (auto itr = data.begin(); itr != data.end(); itr++) {
            itr->display();
        }
    }
    ~Store() {data.clear();}
};