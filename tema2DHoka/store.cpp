#include "store.h"

bool Store::isAlready(string product_name) {
    for (auto itr = data.begin(); itr != data.end() ;++itr) {
        if(itr->getNume() == product_name)
            return true;
    }
    return false;
}

bool Store::addProduct(Product p) {
    if(!isAlready(p.getNume())) {
        data.push_back(p);
        cout << "Produs adaugat\n";
        return true;
    }
    cout << "Produsul exista deja\n";
    return false;
}
bool Store::delProduct(string product_name) {
    for (auto itr = data.begin(), end_itr = data.end(); itr!=end_itr; ++itr) {
        if(itr->getNume() == product_name) {
            data.erase(itr);
            cout << "Produs sters\n";
            return true;
        }
    }
    cout << "Produs negasit\n";
    return false;
}

bool Store::displayProduct(string searchName) {
    for (auto itr = data.begin(); itr < data.end(); itr++) {
        if (itr->getNume() == searchName) {
            cout << "Produsul cautat -> ";
            itr->display();
            return true;
        }
    }
    return false;
}