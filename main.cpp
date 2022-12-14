#include "store.hpp"
#include "XMLObject.hpp"

/*
TO DO

1. Implement xml read-write classes
2. Create the game loop
*/

int main()
{
    //Store store("Markt");
    //store.addProducts(); //TO DO: pass an argument to xml file
    //store.printProducts();
    XMLReader reader;
    reader.read("data.xml");
}