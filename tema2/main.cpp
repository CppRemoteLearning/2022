#include "headers/XmlParser.h"
#include <iostream>

int main(){
    XmlParser parser = XmlParser("file.xml");
    std::map<std::string, std::pair<std::string, std::string>> out;
    parser.readProductInfo(out);
    std::cout<<out["Product1"].first;
}