#ifndef _REPO_H_
#define _REPO_H_


#include <vector>
#include "product.h"

class RepoException
{
    std::string mesaj;

public:
    RepoException(std::string msg) : mesaj{msg} {};
    std::string getMsg() { return mesaj; }
};

class Repo
{
private:
    std::vector<Produs> v;
    std::string fName;
    std::string path_to_file;

public:
    void store(Produs a);

    void loadFromFile();

    void storeToFile(std::string path_to_file);

    std::vector<Produs> getAll(std::string path_to_file);

    Repo(std::string fName) : fName{fName} { loadFromFile(); }
};
#endif