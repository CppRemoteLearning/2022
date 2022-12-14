#include "headers/XmlParser.h"
#include <iostream>

int main()
{
    XmlParser parser = XmlParser("file.xml");
    std::map<std::string, std::pair<std::string, std::string>> out;
    parser.readProductInfo(out);

    for (const auto &iter : out)
    {
        std::cout << iter.first << ": (price = " << iter.second.first << ", quantity = " << iter.second.second << ")\n";
    }
}