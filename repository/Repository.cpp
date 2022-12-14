#include "Repository.h"
#include <string>

Repository::Repository() {}

Repository::~Repository() {}

void Repository::add(Product const& p){
    this->v.push_back(p);
}

void Repository::remove(Product const& p){
    for(auto it = this->v.begin(); it != this->v.end(); it++){
        if(*it == p){
            this->v.erase(it);
            break;
        }
    }
}

std::vector<Product> Repository::getAll(){
    return this->v;
}