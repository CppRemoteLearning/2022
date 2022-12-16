#include "model/Product.h"
#include "repository/Repository.h"
#include "readWrite/ReadWrite.h"
#include <iostream>

int main(){
    std::string _file = "/home/bianca/2022/file.txt";
    Repository r(_file);
    ReadWrite rw(r);
    rw.read();

    for(auto p : r.getProducts()){
        std::cout<<p.getName()<<" "<<p.getWeight()<<"\n";
    }

    r.add(Product("salad", 25));

    rw.write();
}