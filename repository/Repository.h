#ifndef _PROGRAM_REPOSITORY_REPOSITORY_H_
#define _PROGRAM_REPOSITORY_REPOSITORY_H_
#include <vector>
#include "/home/bianca/2022/model/Product.h"
#include <iostream>

class Repository
{

public:
    Repository()=default;
    Repository(std::string const& _file);
    Repository(const Repository & r)=default;
    Repository(Repository && r) noexcept =default;

    Repository &operator=(Repository const &r);
    Repository &operator=(Repository &&r) noexcept;

    void add(Product const& p);
    void remove(Product const& p);

    std::vector<Product> getProducts();
    std::string getFile();

    ~Repository()=default;

private:
    std::vector<Product> products;
    std::string file;
};


#endif