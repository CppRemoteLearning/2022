#ifndef STORE_MANAGER_INCLUDE_XML_PARSER_H_
#define STORE_MANAGER_INCLUDE_XML_PARSER_H_

#include <string>
#include <vector>

#include "product.h"

class XMLParser{
public:
  XMLParser();
  explicit XMLParser(std::vector<Product> const& data);
  XMLParser(XMLParser const& other);  //copy constructor
  XMLParser(XMLParser&& other);  // move constructor
  XMLParser& operator=(XMLParser const& other);  //copy asignment constructor
  XMLParser& operator=(XMLParser&& other);  //move asignment constructor
  ~XMLParser();
  std::vector<Product> Parse(std::vector<std::string> const& file_content);
  std::vector<Product> GetData() const;
private:
  bool CheckData(std::vector<std::string> const& data) const;
  std::string GetInfo(std::string const& row);
  Product ConvertData(std::vector<std::string> const& unconverted_data);
  std::vector<Product> data_;
};
#endif //STORE_MANAGER_INCLUDE_XML_PARSER_H_
