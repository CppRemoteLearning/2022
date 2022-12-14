#ifndef _PRODUCT_MANAGER_PRODUCT_H_
#define _PRODUCT_MANAGER_PRODUCT_H_

#include <string>

class Product
{
private:
  std::string name;
  double price;
public:
  Product(std::string name, double price);
  ~Product();
  Product (const Product& other) = default;
  Product (Product&& other) = default;
  Product& operator=(const Product& other);
  Product& operator=(Product &&other);
  bool operator==(const Product& other);
  std::string getName();
  double getPrice();
};

#endif