#include "include/XMLHandler.h"
#include "include/Product.h"
#include "include/ProductManager.h"
#include <string>
#include <vector>
#include <utility>
#include <iostream>


int main()
{
  ProductManager Store;
  Store.addToStore(Product("Mouse", 150.0));
  Store.addToStore(Product("Keyboard", 175.76));
  Store.addToStore(Product("Monitor", 330.23));
  Store.printProducts();
  Store.removeFromStore(Product("Mouse", 150.0));
  Store.printProducts();
  Store.saveToFile("../storeTest.xml");

  ProductManager Store2;
  Store2.readFromFile("../store.xml");
  Store2.printProducts();

}  
