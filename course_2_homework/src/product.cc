#include "../include/product.h"

Product::Product():data(std::tuple<unsigned int, std::string, std::string, std::string, float>()){}

Product::Product(std::tuple<unsigned int, std::string, std::string, std::string, float> new_data){
	if(data != new_data)
		data = new_data;
}

Product& Product::operator=(Product const& other){
	if(this != & other){
		data = other.data;
	}
	return *this;
}

Product::~Product(){}

bool Product::operator==(Product const& other) const{
	if(data == other.data)
		return true;
	return false;
}

auto Product::get_data() -> std::tuple<unsigned int, std::string, std::string, std::string, float>{
	return data;
}

void Product::print(){
	std::cout << std::get<0>(data) << std::setw(30);
	std::cout << std::get<1>(data) << std::setw(30);
	std::cout << std::get<2>(data) << std::setw(30);
	std::cout << std::get<3>(data) << std::setw(30);
	std::cout << std::get<4>(data) << std::endl;
}
