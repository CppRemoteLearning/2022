#include "../include/product.h"

Product::Product()
    : id_(0), name_(std::string()), category_(std::string()), quantity_(0), price_(0){}

Product::Product(unsigned int id, std::string name, std::string category, 
		 unsigned int quantity, float price)
    : id_(id), name_(name), category_(category), quantity_(quantity), price_(price){}

//copy constructor
Product::Product(const Product& other)
    : id_(other.id_), name_(other.name_), category_(other.category_),
      quantity_(other.quantity_), price_(other.price_){}

//move constructor
Product::Product(Product&& other)
    : id_(other.id_), name_(other.name_), category_(other.category_),
      quantity_(other.quantity_), price_(other.price_){}

//copy asignment constructor
Product& Product::operator=(Product const& other){
  if(this != &other){
    id_ = other.id_;
    name_ = other.name_;
    category_ = other.category_;
    quantity_ = other.quantity_;
    price_ = other.price_;
  }
  return *this;
}

//move asignment constructor
Product& Product::operator=(Product&& other){
  if(this != &other){
    id_ = other.id_;
    name_ = other.name_;
    category_ = other.category_;
    quantity_ = other.quantity_;
    price_ = other.price_;
  }
  return *this;
}

Product::~Product(){}

bool Product::operator==(Product const& other) const{
  if((id_ == other.id_) && (name_ == other.name_) && (category_ == other.category_) &&
     (quantity_ == other.quantity_) && (price_ == other.price_))
    return true;
  return false;
}

bool Product::operator<(Product const& other) const{
  if(name_ < other.name_)
    return true;
  return false;
}

unsigned int Product::GetId() const{
  return id_;
}

std::string Product::GetName() const{
  return name_;
}

std::string Product::GetCategory() const{
  return category_;
}

unsigned int Product::GetQuantity() const{
  return quantity_;
}

float Product::GetPrice() const{
  return price_;
}

void Product::SetId(unsigned int const& id){
  id_ = id;
}

void Product::SetName(std::string const& name){
  name_ = name;
}

void Product::SetCategory(std::string const& category){
  category_ = category;
}

void Product::SetQuantity(unsigned int const& quantity){
  quantity_ = quantity;
}

void Product::SetPrice(float const& price){
  price_ = price;
}

void Product::visit(std::function<void(unsigned int&, std::string&, std::string&,
		    unsigned int&, float&)> f){
  f(id_, name_, category_, quantity_, price_);
}
