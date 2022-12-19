#include "ProductManager.h"
#include "XMLHandler.h"
#include <iostream>
#include <algorithm>

ProductManager::ProductManager(const ProductManager& other)
{
  std::cout << "ProductManager copy constructor called." << std::endl;
  productList_ = other.productList_;
}

ProductManager::ProductManager(ProductManager&& other)
{
  std::cout << "ProductManager move constructor called." << std::endl;
  productList_ = std::move(other.productList_);
}

ProductManager& ProductManager::operator=(const ProductManager& other)
{
  std::cout << "ProductManager copy assignment operator called" << std::endl;
  productList_ = other.productList_;
  return *this;
}

ProductManager& ProductManager::operator=(ProductManager&& other)
{
  std::cout << "ProductManager move assignment operator called" << std::endl;
  productList_ = std::move(other.productList_);
  return *this;
}

void ProductManager::addToStore(Product item)
{
  productList_.push_back(item);
}

void ProductManager::removeFromStore(Product item)
{
  auto it = std::find(productList_.begin(), productList_.end(), item);
  if (it != productList_.end())
  {
    productList_.remove(item);
  }
  else
  {
    std::cout << "No such item" << std::endl;
  }
}

void ProductManager::printProducts()
{
  std::list<Product>::const_iterator it;
  for (it = productList_.begin(); it != productList_.end(); ++it)
  {
    std::cout << "Name = "<< it->getName() << "\nPrice = " << it->getPrice() << std::endl;
  }
}

void ProductManager::saveToFile(std::string path_to_file)
{
  XMLHandler Handler = XMLHandler(path_to_file, productList_);
  Handler.writeToFile();
}

void ProductManager::readFromFile(std::string path_to_file)
{
  XMLHandler Handler = XMLHandler(path_to_file);
  Handler.readFromFile();
  std::vector<std::pair<std::string, double>> values = Handler.getValues();
  std::vector<std::pair<std::string, double>>::const_iterator it;
  
  for (it = values.begin(); it != values.end(); ++it)
  {
    productList_.push_back(Product(it->first, it->second));
  }
}