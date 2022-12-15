#include "XMLObject.hpp"

const std::vector<Product> XMLReader::read()
{
            std::ifstream file(fname);
            std::string xmlString((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            
            if (file)
                std::cout << "file '" << fname << "' opened\n";
            else
                std::cout << "file '" << fname << "' not found\n";
            std::vector<Product> products;
            
            rapidxml::xml_document<> doc;
            doc.parse<0>(&xmlString[0]);
            rapidxml::xml_node<>* rootNode = doc.first_node();
            if (rootNode)
                for (rapidxml::xml_node<>* node = rootNode->first_node("product"); node; node = node->next_sibling("product"))
                {   
                    Product prod(node->first_node("name")->value(), atof(node->first_node("price")->value()));
                    products.push_back(prod);
                }
            else
                std::cout << "root node null\n";
            if (products.size()>1)
                std::cout << "products vector created\n";
            return products;
}
