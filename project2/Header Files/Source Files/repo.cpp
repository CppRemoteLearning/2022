#include "repo.h"
#include <algorithm>
#include <fstream>
#include "xml.h"

void repo::loadFromFile()
{
    v.clear();
    std::ifstream fin(fName);
    std::string nume, tip;
    int id;
    double pret;
    while (fin >> id)
    {
        fin >> nume >> tip >> pret;
        Produs a{id, nume, tip, pret};
        v.push_back(a);
    }
    fin.close();
}
void repo::storeToFile(std::string path_to_file)
{
    XMLHandler Handler = XMLHandler(path_to_file, v);
    Handler.writeToFile();
}
std::vector<Produs> repo::getAll(std::string path_to_file)
{
    
    XMLHandler Handler = XMLHandler(path_to_file);
    Handler.readFromFile();
    std::vector<Produs> values = Handler.getValues();

    for (auto it = values.begin(); it != values.end(); ++it)
    {
        v.push_back((Produs) *it);
    }

    return v;
}

