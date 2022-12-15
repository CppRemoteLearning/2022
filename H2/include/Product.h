#ifndef _PRODUCT_MANAGER_PRODUCT_H_
#define _PRODUCT_MANAGER_PRODUCT_H_

#include <string>

class Product
{
public:
  Product(std::string name, double price);
  ~Product() {}
  Product (const Product& other);
  Product (Product&& other);
  Product& operator=(const Product& other);
  Product& operator=(Product &&other);
  bool operator==(const Product& other);
  std::string getName() const;
  double getPrice() const;

private:
  std::string name_;
  double price_;
};

#endif