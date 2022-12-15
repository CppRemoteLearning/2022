#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "store.hpp"
#include "product.hpp"
class XMLReader {
        std::string fname;
    public:
        XMLReader();
        XMLReader(std::string name_) : fname(name_) {}
        const std::vector<Product> read();
};