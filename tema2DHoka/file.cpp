#include "file.h"
#include <string>
#include <regex>

StoreIO::StoreIO(std::string file_name) {
    name = file_name;
    std::cout << "StoreIO construct este apelat\n";
}

// voi desparti fiecare linie in cuvinte dupa separatorul spatii " "
std::vector<std::string> tokenize(const std::string str, const std::regex re) {
    std::sregex_token_iterator it{ str.begin(), str.end(), re, -1};
    std::vector<std::string> tokenized { it, {} };
    tokenized.erase(remove_if(tokenized.begin(), tokenized.end(), [](std::string const& s){
        return s.size() == 0;
    }),
    tokenized.end());
    return tokenized;
}

void StoreIO::read(Store& store) {
    std::ifstream my_file(name);
    std::string line;
    std::regex re(R"([\s]+)");
    if (my_file.is_open()) {
        while(getline(my_file, line)) {
            std::vector<std::string> tokenized = tokenize(line, re);
            std::string nume = tokenized[0];
            int cant = std::stoi(tokenized[1]);
            int pret = std::stoi(tokenized[2]);
            store.addProduct(Product(nume, cant, pret));
        }
        std::cout << "S-a citit din fisier\n";
    }
    else {
        std::cout << "Nu s-a deschis fisierul\n";
    }
    my_file.close();
}

void StoreIO::write(Store& store) {
    std::ofstream my_file(name);
    if (my_file.is_open()) {
        my_file.clear();
        if (!store.isEmpty()) {
        for (auto itr = store.getData().begin(); itr < store.getData().end(); ++itr) {
            my_file << itr->getNume() << " " << itr->getCantitate() << " " << itr->getPret() << std::endl;
        }
        // for (Product& product : store.getData()) {
        //     my_file << product.getNume() << " " << product.getCantitate() << " " << product.getPret() << endl;
        // }
        std::cout << "S-a scris in fisier\n";
        }
        else std::cout << "Store gol\nStore size: "<<store.size() << std::endl;
    }
    else std::cout << "Nu s-a deschis fisierul\n";
    my_file.close();
}