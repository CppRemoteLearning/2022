#include "store.hpp"
#include "XMLObject.hpp"

int main()
{
    XMLReader reader("../data.xml");
    Store store("Market", reader.read());

    store.printProducts();
}