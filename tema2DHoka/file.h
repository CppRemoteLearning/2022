#pragma once
#include <iostream>
#include <fstream>
#include "store.h"

//StoreSerializer
//StoreReadWrite
//StoreIO
//..
class StoreIO {
    public:
    StoreIO(std::string file_name);
    ~StoreIO() {}
    void read(Store& store);
    void write(Store& store);
    private:
    std::string name;
};