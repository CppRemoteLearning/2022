#include "Product.h"
#include <iostream>
#include <utility>

Product::Product(std::string name, double price)
{
  std::cout << "Product constructor called." << std::endl;
  name_ = name;
  price_ = price;
}

Product::Product(const Product& other)
{
  std::cout << "Product copy constructor called." << std::endl;
  name_ = other.name_;
  price_ = other.price_;
}

Product::Product(Product&& other)
{
  std::cout << "Product move constructor called." << std::endl;
  name_ = std::move(other.name_);
  price_ = std::move(other.price_);
}

Product& Product::operator=(const Product& other)
{
  std::cout << "Product copy assignment operator called" << std::endl;
  name_ = other.name_;
  price_ = other.price_;
  return *this;
}

Product& Product::operator=(Product &&other)
{
  std::cout << "Product move assignment operator called" << std::endl;
  name_ = std::move(other.name_);
  price_ = std::move(other.price_);
  return *this;
}

bool Product::operator==(const Product& other)
{
  return name_ == other.name_ && price_ ==other.price_;
}

std::string Product::getName() const
{
  return name_;
}

double Product::getPrice() const
{
  return price_;
}