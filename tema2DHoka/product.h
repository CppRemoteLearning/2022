#pragma once
#include <iostream>
using namespace std;

class Product {
    string nume;
    int cant; // cantitate
    int pret;
    public:
    Product(string& nume_produs, int& cantitate_produs, int& pret_produs) : nume(nume_produs), cant(cantitate_produs), pret(pret_produs) {
        cout << "S-a construit produsul " << nume << endl;
    }
    Product (const Product &other) {
        cout << "Copy construct este apelat\n";
        nume = other.nume;
        cant = other.cant;
        pret = other.pret;
    }
    Product& operator=(const Product &other) {
        cout<<"S-a atribuit produsul " << nume << endl;
        nume = other.nume;
        cant = other.cant;
        pret = other.pret;
        return *this;
    }
    friend ostream& operator<<(ostream& os, Product& product_out) {
        // afisare in flux
        os << "nume: " << product_out.getNume() << " | cant: " << product_out.getCantitate() << " | pret: " << product_out.getPret() << endl;
        return os;
    }
    ~Product() {}
    // getteri
    string& getNume() {  return nume; }
    int& getCantitate() {    return cant; }
    int& getPret() { return pret; }
    Product& getProduct() {  return *this; }
    // setteri
    void setNume(string nume_nou) { nume = nume_nou; }
    void setCantitate(int cant_noua) { cant = cant_noua; }
    void setPret(int pret_nou) { pret = pret_nou; }
    void display() { cout << "nume: " << nume << " cant: " << cant << " pret: " << pret << endl; }
};