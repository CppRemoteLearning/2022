#ifndef MANAGE_STORE_INCLUDE_PRODUCT_H_
#define MANAGE_STORE_INCLUDE_PRODUCT_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <tuple>

class Product{
public:
	Product();
	Product(std::tuple<unsigned int, std::string, std::string, std::string, float>);
	Product(const Product& other)=default;
	Product(Product&& other)=default;
	Product& operator=(Product const& other);
	~Product();
	bool operator==(Product const& other) const;
	auto get_data() -> std::tuple<unsigned int, std::string, std::string, std::string, float>;
	void print();
private:
	std::tuple<unsigned int, std::string, std::string, std::string, float> data;
};
#endif //MANAGE_STORE_INCLUDE_PRODUCT_H_
