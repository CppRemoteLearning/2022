#include "headers/XmlParser.h"
#include "headers/Product.h"
#include <iostream>

int main()
{
    XmlParser parser = XmlParser("file.xml");
    std::map<std::string, std::pair<std::string, std::string>> out;
    parser.readProductInfo(out);

    for (const std::pair<std::string, std::pair<std::string, std::string>> &iter : out)
    {
        Product pro = Product(iter);
        std::cout << iter.first << ": (price = " << iter.second.first << ", quantity = " << iter.second.second << ")\n";
    }
}