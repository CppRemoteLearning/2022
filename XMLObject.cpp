#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

class XMLReader {
    private:
    public:
        XMLReader(const std::string& filename)
        {
            std::ifstream file(filename);
            std::string xmlString((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

            rapidxml::xml_document<> doc;
            doc.parse<0>(&xmlString[0]);

            rapidxml::xml_node<>* rootNode = doc.first_node();
            for (auto node = rootNode->first_node(); node; node = node->next_sibling())
            {
                if (strcmp(node->name(), "products") == 0)
                    {
                        for (auto productNode = node->first_node(); productNode; productNode = productNode->next_sibling())
                        {
                            if (strcmp(productNode->name(), "name") == 0)
                            {
                                std::string name = productNode->value();
                                std::cout << "Name: " << std::endl;
                            }
                        }
                    }
            }

        }
};