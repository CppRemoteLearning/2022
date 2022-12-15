#pragma once
#include <iostream>

class Product {
    public:
    friend std::ostream& operator<<(std::ostream& os, const Product& product_out);
    Product(std::string nume_produs, int cantitate_produs, int pret_produs);
    Product (const Product &other);
    Product& operator=(const Product& other);
    ~Product() {}
    // getteri
    const std::string& getNume() const;
    const int& getCantitate() const;
    const int& getPret() const;
    // setteri
    void setNume(std::string nume_nou);
    void setCantitate(int cant_noua);
    void setPret(int pret_nou);
    void display();
    private:
    std::string nume;
    int cant; // cantitate
    int pret;
};