#include "headers/XmlParser.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

XmlParser& XmlParser::operator=(const XmlParser& other)
{
    if(this != &other)
    {
        //we are able to acces other.filepath although  filepath is private because 
        //the special member functions have acces to the private members of the class
        filePath = other.filePath;
    }
    return *this;
}

XmlParser& XmlParser::operator=(XmlParser&& other)
{
    if(this != &other)
    {
        filePath = std::move(other.filePath);
    }
    return *this;
}

void XmlParser::readProductInfo(std::map<std::string, std::pair<std::string, std::string>> &productInfo)
{
    std::ifstream file(filePath);
    std::string line;
    if (!file.is_open())
    {
        std::cout << "file not opened";
        return;
    }    
    std::string name, price, quantity;
    while (getline(file, line))
    {
        // if the line contains the closing tag /product, we add the variables into the colection and reset them
        if (line.find("</product>") != std::string::npos)
        {
            productInfo[name] = std::pair<std::string, std::string>(price, quantity);
            name = "";
            price = "";
            quantity = "";
        }
        // if the line contains the word product we can skip over it
        if (line.find("product") != std::string::npos)
        {
            continue;
        }
        // check to see if the line contains any tag (name price quantity)
        if (line.find("<name>") != std::string::npos)
        {
            int pos = line.find(">") + 1;
            name = line.substr(pos, line.find("</name>") - pos);
        }
        else if (line.find("<price>") != std::string::npos)
        {
            int pos = line.find(">") + 1;
            price = line.substr(pos, line.find("</price>") - pos);
            // price = std::stod(line.substr(pos, line.find("</price>") - pos));
        }
        else if (line.find("<quantity>") != std::string::npos)
        {
            int pos = line.find(">") + 1;
            quantity = line.substr(pos, line.find("</quantity>") - pos);
            // quantity = strtod(num.c_str(),nullptr);
        }
    }
}