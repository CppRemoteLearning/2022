#include "ReadWrite.h"

ReadWrite::ReadWrite(Repository &_repository) : repository(_repository)
{
}

void ReadWrite::read()
{
    std::ifstream fin(repository.getFile());
	Product product;
	while (fin >> product){
		repository.add(product);
    }
	fin.close();
}

void ReadWrite::write()
{
    std::ofstream fout(repository.getFile());
    for(auto product : repository.getProducts()) {
        fout << product << '\n';
    }

}

ReadWrite::~ReadWrite()
{
}
