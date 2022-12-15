#ifndef STORE_INCLUDE_STORE_MANAGER_H_
#define STORE_INCLUDE_STORE_MANAGER_H_

#include <iostream>
#include <string>
#include <vector>

#include "xml_reader_writer.h"
#include "xml_parser.h"
#include "product.h"

class StoreManager{
public:
  StoreManager();
  explicit StoreManager(std::string name, std::vector<Product> data);
  StoreManager(std::string const& path);
  StoreManager(StoreManager const& other);  //copy constructor
  StoreManager(StoreManager&& other) noexcept;  //move constructor
  StoreManager& operator=(StoreManager const& other);  //copy assignment constructor
  StoreManager& operator=(StoreManager&& other) noexcept;  //move assignment constructor
  ~StoreManager();
  void LoadData(std::string const& path);
  StoreManager Add(Product const& product);
  StoreManager Add(std::vector<Product> const& products);
  StoreManager Remove(Product const& product);
  StoreManager Remove(std::vector<Product> const& products);
  StoreManager& operator+(Product const& product);
  StoreManager& operator+(std::vector<Product> const& products);
  StoreManager& operator-(Product const& product);
  StoreManager& operator-(std::vector<Product> const& products);
  std::vector<Product> GetData() const;
  void ShowInTable();
private:
  void PrintHeader();
  static void PrintRow(unsigned int&, std::string&, std::string&, unsigned int&, float&);
  std::vector<Product> data_;
  unsigned int no_of_products_;
  std::string name_;
};
#endif //STORE_INCLUDE_STORE_MANAGER_H_
