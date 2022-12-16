#ifndef _SERVICE_H_
#define _SERVICE_H_

#include "repo.h"

class Service
{
private:
    Repo r;
    std::string path_to_file;
public:
    void add(int id, std::string a, std::string b, double pret, std::string path_to_file);

    Service(Repo r) : r{r}
    {
    }
    std::vector<Produs> getAll(std::string path_to_file) { return r.getAll(path_to_file); }
};

#endif