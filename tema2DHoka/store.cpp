#include "store.h"

std::ostream& operator<<(std::ostream& os, const Store& store_out) {
    os << "\n-------- Store content --------\n";
    for (auto itr = store_out.data.begin(); itr != store_out.data.end(); ++itr) {
        os << *itr;
    }
    return os;
}

Store::Store(std::vector<Product> data_) {
    data = data_;
    std::cout << "S-au construit datele unui store\n";
}

Store::Store(const Store& other) {
    data = other.data;
    std::cout << "S-au copiat datele unui store\n";
}

Store& Store::operator=(Store& other) {
    std::cout << "S-a atribuit data unui store\n";
        data = other.getData();
        return *this;
}

Store::Store(Store&& other) noexcept {
    std::cout << "Move constructor apelat\n";
        data=other.getData();
        // other.~Store();
}

Store* Store::operator=(Store&& other) noexcept {
    std::cout << "Move assignment operator apelat\n";
        if (this != &other) {
            data.clear();
            data = other.getData();
            // other.~Store();
        }
        return this;
}

Store::~Store() {
    data.clear();
}

const std::vector<Product>& Store::getData() const {
    return data;
}

int Store::size() {
    return data.size();
}

bool Store::isAlready(std::string product_name) {
    for (auto itr = data.begin(); itr != data.end() ;++itr) {
        if(itr->getNume() == product_name)
            return true;
    }
    return false;
}

bool Store::isEmpty() {
    return size() < 1;
}

bool Store::addProduct(Product p) {
    if(!isAlready(p.getNume())) {
        data.push_back(p);
        std::cout << "Produs adaugat\n";
        return true;
    }
    std::cout << "Produsul exista deja\n";
    return false;
}
bool Store::delProduct(std::string product_name) {
    for (auto itr = data.begin(), end_itr = data.end(); itr!=end_itr; ++itr) {
        if(itr->getNume() == product_name) {
            data.erase(itr);
            std::cout << "Produs sters\n";
            return true;
        }
    }
    std::cout << "Produs negasit\n";
    return false;
}

bool Store::displayProduct(std::string searchName) {
    for (auto itr = data.begin(); itr < data.end(); ++itr) {
        if (itr->getNume() == searchName) {
            std::cout << "Produsul cautat -> ";
            itr->display();
            return true;
        }
    }
    return false;
}

void Store::display() {
    for (auto itr = data.begin(); itr != data.end(); ++itr) {
            itr->display();
        }
}