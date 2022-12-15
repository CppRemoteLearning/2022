#include "headers/XmlParser.h"
#include "headers/Product.h"
#include "headers/ProductManager.h"

int main()
{
    //create the parser for the xml file
    XmlParser parser = XmlParser("file.xml");
    //this hash map will be used to output the xml file 
    std::map<std::string, std::pair<std::string, std::string>> out;
    parser.readProductInfo(out);
    //define the store 
    ProductManager store = ProductManager();
    //read products
    //auto will be of type std::pair<std::string, std::pair<std::string, std::string>>
    for (const auto &iter : out)
    {
        store.addProduct(Product(iter));
    }
    store.printProducts();
    store.removeProduct(store.getProduct(0));
    store.printProducts();
}
