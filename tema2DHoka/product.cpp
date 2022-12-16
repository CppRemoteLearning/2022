#include "product.h"

Product::Product(std::string nume_produs, int cantitate_produs, int pret_produs) {
    nume = nume_produs;
    cant = cantitate_produs;
    pret = pret_produs;
    std::cout << "S-a construit produsul " << nume << std::endl;
}

Product::Product(const Product& other) {
    nume = other.nume;
    cant = other.cant;
    pret = other.pret;
    std::cout << "Copy construct este apelat\n";
}

Product& Product::operator=(const Product& other) {
    std::cout<<"S-a atribuit produsul " << other.nume << std::endl;
        nume = other.nume;
        cant = other.cant;
        pret = other.pret;
        return *this;
}

const std::string& Product::getNume() const { return nume; }
const int& Product::getCantitate() const {    return cant; }
const int& Product::getPret() const { return pret; }

void Product::setNume(std::string nume_nou) { nume = nume_nou; }
void Product::setCantitate(int cant_noua) { cant = cant_noua; }
void Product::setPret(int pret_nou) { pret = pret_nou; }
void Product::display() { std::cout << "nume: " << nume << " cant: " << cant << " pret: " << pret << std::endl; }

std::ostream& operator<<(std::ostream& os, const Product& product_out) {
        // afisare in flux
        os << "nume: " << product_out.getNume() << " | cant: " << product_out.getCantitate() << " | pret: " << product_out.getPret() << std::endl;
        return os;
    }