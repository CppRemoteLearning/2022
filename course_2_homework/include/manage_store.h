#ifndef MANAGE_STORE_INCLUDE_MANAGE_STORE_H_
#define MANAGE_STORE_INCLUDE_MANAGE_STORE_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "read_write_xml.h"
#include "parse_xml.h"
#include "product.h"

class ManageStore{
public:
	ManageStore();
	ManageStore(std::string const& path);
	ManageStore(const ManageStore& other)=default;
	ManageStore(ManageStore&& other)=default;
	ManageStore& operator=(ManageStore const& other);
	~ManageStore();
	void load_data(std::string const& path);
	ManageStore add(Product const& product);
	ManageStore add(std::vector<Product> const& products_list);
	ManageStore remove(Product const& product);
	ManageStore remove(std::vector<Product> const& prodcuts_list);
	ManageStore& operator+(Product const& product);
	ManageStore& operator+(std::vector<Product> const& products_list);
	ManageStore& operator-(Product const& product);
	ManageStore& operator-(std::vector<Product> const& prodcuts_list);
	std::vector<Product> get_data();
	void display();
private:
	void print_header();
	std::vector<Product> data;
};
#endif //MANAGE_STORE_INCLUDE_MANAGE_STORE_H_
