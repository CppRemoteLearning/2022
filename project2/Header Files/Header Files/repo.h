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

class repo
{
private:
    std::vector<Produs> v;
    std::string fName;
    std::string path_to_file;

public:
    void store(Produs a)
    {
        for (auto &s : v)
            if (s.getId() == a.getId())
                throw RepoException("Id existent!\n");
        v.push_back(a);
        storeToFile(path_to_file);
    };

    void loadFromFile();

    void storeToFile(std::string path_to_file);

    std::vector<Produs> getAll(std::string path_to_file);

    repo(std::string fName) : fName{fName} { loadFromFile(); }
};
#endif