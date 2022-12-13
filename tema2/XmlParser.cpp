#include "headers/XmlParser.h"

void XmlParser::readProductInfo(std::map<std::string, std::pair<double, int>> &productInfo)
    {
        std::ifstream file(filePath);
        std::string line;
        while (getline(file, line))
        {
            std::string name;
            double price;
            int quantity;
            // if the line contains the closing tag /product, we add the variables into the colection and reset them
            if (line.find("</product>") != std::string::npos)
            {
                productInfo[name] = std::pair<double, int>(price, quantity);
                name = "";
                price = 0;
                quantity = 0;
            }
            //if the line contains the word product we can skip over it 
            if(line.find("product") != std::string::npos)
            {
                continue;
            }
            // check to see if the line contains any tag (name price quantity)
            if (line.find("<name>") != std::string::npos)
            {
                name = line.substr(6, line.size() - 13);
            }
            else if (line.find("<price>") != std::string::npos)
            {
                price = std::stod(line.substr(7, line.size() - 15));
            }
            else if (line.find("<quantity>") != std::string::npos)
            {
                quantity = std::stoi(line.substr(10, line.size() - 19));
            }
        }
    }