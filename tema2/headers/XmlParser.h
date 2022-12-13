#include <iostream>
#include <fstream>
#include <string>
#include <map>

class XmlParser
{
private:
    // xml file path
    std::string filePath;

public:
    XmlParser(std::string file) : filePath(file){};
    // function to read the xml file and return a map containg all its data
    void readProductInfo(std::map<std::string, std::pair<double, int>> &productInfo);
};