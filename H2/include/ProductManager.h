#ifndef _PRODUCT_MANAGER_PRODUCT_MANAGER_H_
#define _PRODUCT_MANAGER_PRODUCT_MANAGER_H_

#include "Product.h"
#include <list>
#include <iostream>

class ProductManager
{
private:
  std::list<ProductManager> productList;
public:
  ProductManager(std::list<ProductManager> prods);
  ~ProductManager();
  ProductManager(const ProductManager& other) = default;
  ProductManager(ProductManager&& other) = default;
  ProductManager& operator=(const ProductManager& other);
  ProductManager& operator=(ProductManager &&other);
  bool operator==(const ProductManager& other);
  std::ostream& operator<<(std::ostream& os);
};

#endif