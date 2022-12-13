#ifndef MANAGE_STORE_INCLUDE_PARSE_XML_H_
#define MANAGE_STORE_INCLUDE_PARSE_XML_H_

#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "product.h"

class ParseXML{
public:
	ParseXML();
	ParseXML(const ParseXML& other)=default;
	ParseXML(ParseXML&& other)=default;
	ParseXML& operator=(ParseXML const& other);
	~ParseXML();
	std::vector<Product> parse(std::vector<std::string> file_content);
	std::vector<Product> get_data();
private:
	std::string get_info(std::string row);
	Product convert_data(std::vector<std::string> temp_data);
	std::vector<Product> data;
};
#endif //MANAGE_STORE_INCLUDE_PARSE_XML_H_
