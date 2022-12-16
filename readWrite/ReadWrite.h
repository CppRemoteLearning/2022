#ifndef _PROJECT_READWRITE_READWRITE_H_
#define _PROJECT_READWRITE_READWRITE_H_

#include <string>
#include "/home/bianca/2022/model/Product.h"
#include "/home/bianca/2022/repository/Repository.h"
#include <fstream>

class ReadWrite
{

public:
    ReadWrite(Repository &_repository);

    void read();
    void write();

    ~ReadWrite();

private:
    Repository &repository;
    
};


#endif