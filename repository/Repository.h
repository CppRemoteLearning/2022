#ifndef _PROGRAM_REPOSITORY_REPOSITORY_H_
#define _PROGRAM_REPOSITORY_REPOSITORY_H_
#include <vector>
#include "/home/bianca/2022/model/Product.h"

class Repository
{
private:
    std::vector<Product> v;
    std::string file;
public:
    Repository();
    Repository(std::string const& _file);
    Repository(Repository & r)=default;
    Repository(Repository && r)=default;
    void add(Product const& p);
    void remove(Product const& p);
    std::vector<Product> getAll();
    ~Repository();

};


#endif