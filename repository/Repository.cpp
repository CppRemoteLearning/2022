#include "Repository.h"
#include <string>

Repository::Repository(std::string const &_file) : file(_file)
{
}

Repository &Repository::operator=(Repository const &r)
{
    if(this == &r) {
        return *this;
    }
    
    this->file = r.file;
    this->products = r.products;

    return *this;
}

Repository &Repository::operator=(Repository &&r) noexcept
{
    if(this == &r) {
        return *this;
    }

    this->file = std::move(r.file);
    this->products = r.products;

    return *this;
}

void Repository::add(Product const &p)
{
    this->products.push_back(p);
}

void Repository::remove(Product const& p){
    for(auto it = this->products.begin(); it != this->products.end(); ++it){
        if(*it == p){
            this->products.erase(it);
            break;
        }
    }
}

std::vector<Product> Repository::getProducts(){
    return this->products;
}

std::string Repository::getFile()
{
    return this->file;
}
