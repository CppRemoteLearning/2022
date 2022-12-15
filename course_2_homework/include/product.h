#ifndef MANAGE_STORE_INCLUDE_PRODUCT_H_
#define MANAGE_STORE_INCLUDE_PRODUCT_H_

#include <iostream>
#include <string>
#include <tuple>

class Product{
public:
  Product();
  explicit Product(unsigned int id, std::string name, std::string category,
		   unsigned int quantity, float price);
  Product(Product const& other);  //copy constructor
  Product(Product&& other) noexcept; //move constructor
  Product& operator=(Product const& other); //copy asignment constructor
  Product& operator=(Product&& other) noexcept; //move asignment constructor
  ~Product();
  bool operator==(Product const& other) const;
  bool operator<(Product const& other) const;
  unsigned int GetId() const;
  std::string GetName() const;
  std::string GetCategory() const;
  unsigned int GetQuantity() const;
  float GetPrice() const;
  void SetId(unsigned int const& id);
  void SetName(std::string const& name);
  void SetCategory(std::string const& category);
  void SetQuantity(unsigned int const& quantity);
  void SetPrice(float const& price);
  void visit(void (*f)(unsigned int&,std::string&,std::string&,unsigned int&,float&));
private:
  unsigned int id_;
  std::string name_;
  std::string category_;
  unsigned int quantity_;
  float price_;
};
#endif //MANAGE_STORE_INCLUDE_PRODUCT_H_
