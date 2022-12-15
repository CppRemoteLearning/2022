#include "../include/store_manager.h"

#include <algorithm>
#include <iomanip>

StoreManager::StoreManager():data_(std::vector<Product>()),no_of_products_(0),name_(std::string()){}

StoreManager::StoreManager(std::string name, std::vector<Product> data)
    : name_(name), data_(data.begin(), data.end()){
  no_of_products_ = data_.capacity(); 
}

StoreManager::StoreManager(std::string const& path){
  LoadData(path);
}

//copy constructor
StoreManager::StoreManager(StoreManager const& other)
    : no_of_products_(other.no_of_products_), data_(other.data_.begin(), other.data_.end()),
      name_(other.name_){}

//move constructor
StoreManager::StoreManager(StoreManager&& other) noexcept
    : data_(std::vector<Product>()), no_of_products_(0), name_(std::string()){
  no_of_products_ = other.no_of_products_;
  name_ = other.name_;
  data_.reserve(no_of_products_);

  for(auto iterator : other.data_)
    data_.push_back(iterator);

  other.no_of_products_ = 0;
  other.name_ = std::string();
  other.data_.clear();
}

//copy asignment constructor
StoreManager& StoreManager::operator=(StoreManager const& other){
  if(this != &other){
    data_.clear();

    no_of_products_ = other.no_of_products_;
    name_ = other.name_;
    data_.reserve(no_of_products_);

    for(auto const& iterator : other.data_)
	    data_.push_back(iterator);
  }
  return *this;
}

//move asignment constructor
StoreManager& StoreManager::operator=(StoreManager&& other) noexcept{
  if(this != &other){
    data_.clear();
    no_of_products_ = other.no_of_products_;
    name_ = other.name_;
    data_.reserve(no_of_products_);

    for(auto const& iterator : other.data_)
	    data_.push_back(iterator);

    other.no_of_products_ = 0;
    other.name_ = std::string();
    other.data_.clear();
  }
  return *this;
}

StoreManager::~StoreManager(){
  if(!data_.empty()){
    data_.clear();
    no_of_products_ = 0;
    name_ = std::string();
  }
}

void StoreManager::LoadData(std::string const& path){
  XMLReaderWriter xml(path);
  XMLParser parser;
  data_ = parser.Parse(xml.ReadFileContent());
}

StoreManager StoreManager::Add(Product const& product){
  return (*this) + product;
}

StoreManager StoreManager::Add(std::vector<Product> const& products){
  return (*this) + products;
}

StoreManager StoreManager::Remove(Product const& product){
  return (*this) - product;
}

StoreManager StoreManager::Remove(std::vector<Product> const& products){
  return (*this) - products;
}

StoreManager& StoreManager::operator+(Product const& product){
  data_.push_back(product);
  return *this;
}

StoreManager& StoreManager::operator+(std::vector<Product> const& products){
  for(auto iterator : products)
    (*this)+iterator;
  return *this;
}

StoreManager& StoreManager::operator-(Product const& product){
  auto iterator = std::find(data_.begin(), data_.end(), product);
  data_.erase(iterator);
  data_.shrink_to_fit(); //remove unused capacity afeter deletion
  return *this;
}

StoreManager& StoreManager::operator-(std::vector<Product> const& products){
  for(auto iterator : products)
    (*this)-iterator;
  return *this;
}

std::vector<Product> StoreManager::GetData()const{
  return data_;
}

void StoreManager::ShowInTable(){
  if(data_.empty()){
    std::cout << "No data was loaded. Load data first!\n";
      return;
  }

  PrintHeader();
  for(auto iterator : data_)
    iterator.visit(PrintRow);
}

void StoreManager::PrintRow(unsigned int& id, std::string& name, std::string& category,
	        	    unsigned int& quantity, float& price){
  std::cout << std::left << std::setw(10) << id;
  std::cout << std::left << std::setw(20) << name;
  std::cout << std::left << std::setw(20) << category;
  std::cout << std::left << std::setw(15) << quantity;
  std::cout << std::left << std::setw(10) << price << std::endl; 
}

void StoreManager::PrintHeader(){
  std::cout << "\n\n";
  std::cout << std::left << std::setw(10) << "id";
  std::cout << std::left << std::setw(20) << "name";
  std::cout << std::left << std::setw(20) << "category";
  std::cout << std::left << std::setw(15) << "quantity";
  std::cout << std::left << std::setw(10) << "price" << std::endl;
  std::cout << std::string(75,'-') << std::endl;
}
