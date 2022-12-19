#include <iostream>

#include "../include/xml_parser.h"

XMLParser::XMLParser():data_(std::vector<Product>()){}

XMLParser::XMLParser(std::vector<Product> const& data):data_(data.begin(), data.end()){}

//copy constructor
XMLParser::XMLParser(XMLParser const& other):data_(other.data_.begin(), other.data_.end()){}

//move constructor
XMLParser::XMLParser(XMLParser&& other): data_(other.data_.begin(), other.data_.end()){}

//copy asignment constructor
XMLParser& XMLParser::operator=(XMLParser const& other){
  if(this != &other){
    data_ = other.data_;
  }
  return *this;
}

//move asignment constructor
XMLParser& XMLParser::operator=(XMLParser&& other){
  if(this != &other){
    data_ = other.data_;
  }
  return *this;
}

XMLParser::~XMLParser(){}

std::vector<Product> XMLParser::Parse(std::vector<std::string> const& file_content){
  std::vector<std::string> unconverted_data;
  bool flag = false;
  auto iterator = file_content.begin();
  while(iterator!=file_content.end()){
    if(iterator->find("<product>") != std::string::npos)
      flag=true;		
    while(flag){
      iterator++;
      if(iterator->find("</product>") != std::string::npos){
	if(CheckData(unconverted_data))
	  data_.push_back(ConvertData(unconverted_data));
        unconverted_data.clear();
        flag=false;
        continue;
      }
      unconverted_data.push_back(GetInfo(*iterator));
    }
    iterator++;
  } 
  return data_;
}

std::vector<Product> XMLParser::GetData() const{
  return data_;
}

std::string XMLParser::GetInfo(std::string const& row){
  unsigned int pos1 = row.find(">",0,1);
  unsigned int pos2 = row.find("<",pos1,1);
  return row.substr(pos1+1, pos2-pos1-1);
}

Product XMLParser::ConvertData(std::vector<std::string> const& unconverted_data){
  Product product;
  product.SetId(std::stoul(unconverted_data[0]));
  product.SetName(unconverted_data[1]);
  product.SetCategory(unconverted_data[2]);
  product.SetQuantity(std::stoul(unconverted_data[3]));
  product.SetPrice(std::stof(unconverted_data[4]));
  return product;
}

bool XMLParser::CheckData(std::vector<std::string> const& data) const{
  if(data.size()==5){
    return true;
  }
  return false;
}
