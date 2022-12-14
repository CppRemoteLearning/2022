#pragma once
#include <iostream>
#include <fstream>
#include "store.h"
using namespace std;

//StoreSerializer
//StoreReadWrite
//StoreIO
//..
class StoreIO {
    string name;
    public:
    StoreIO(string file_name) : name(file_name) {}
    void read(Store& store);
    void write(Store& store);
};