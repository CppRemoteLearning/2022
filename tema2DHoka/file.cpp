#include "file.h"
#include <string>
#include <regex>

// voi desparti fiecare linie in cuvinte dupa separatorul spatii " "
vector<string> tokenize(const string str, const regex re) {
    sregex_token_iterator it{ str.begin(), str.end(), re, -1};
    vector<string> tokenized { it, {} };
    tokenized.erase(remove_if(tokenized.begin(), tokenized.end(), [](string const& s){
        return s.size() == 0;
    }),
    tokenized.end());
    return tokenized;
}

void StoreIO::read(Store& store) {
    ifstream my_file(name);
    string line;
    regex re(R"([\s]+)");
    if (my_file.is_open()) {
        while(getline(my_file, line)) {
            vector<string> tokenized = tokenize(line, re);
            string nume = tokenized[0];
            int cant = stoi(tokenized[1]);
            int pret = stoi(tokenized[2]);
            store.addProduct(Product(nume, cant, pret));
        }
        cout << "S-a citit din fisier\n";
    }
    else cout << "Nu s-a deschis fisierul\n";
    my_file.close();
}

void StoreIO::write(Store& store) {
    ofstream my_file(name);
    if (my_file.is_open()) {
        my_file.clear();
        if (!store.isEmpty()) {
        // for (auto itr = store.getData().begin(); itr < store.getData().end() ;itr++) {
        //     my_file << itr->getNume() << " " << itr->getCantitate() << " " << itr->getPret() << endl;
        // }
        for (Product& product : store.getData()) {
            my_file << product.getNume() << " " << product.getCantitate() << " " << product.getPret() << endl;
        }
        cout << "S-a scris in fisier\n";
        }
        else cout << "Store gol\nStore size: "<<store.size() << endl;
    }
    else cout << "Nu s-a deschis fisierul\n";
    my_file.close();
}