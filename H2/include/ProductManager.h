#ifndef _PRODUCT_MANAGER_PRODUCT_MANAGER_H_
#define _PRODUCT_MANAGER_PRODUCT_MANAGER_H_

#include "Product.h"
#include <list>
#include <string>

class ProductManager
{
public:
  ProductManager() = default;
  ProductManager(std::list<Product> prods): productList_(prods) {}
  ~ProductManager() = default;
  ProductManager(const ProductManager& other);
  ProductManager(ProductManager&& other);
  ProductManager& operator=(const ProductManager& other);
  ProductManager& operator=(ProductManager&& other);
  void removeFromStore(Product item);
  void addToStore(Product item);
  void saveToFile(std::string path_to_file);
  void printProducts();
  void readFromFile(std::string path_to_file);

private:
  std::list<Product> productList_;
};

#endif