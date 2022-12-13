#include "../include/manage_store.h"

ManageStore::ManageStore(){}

ManageStore::ManageStore(std::string const& path){
	load_data(path);
}

ManageStore& ManageStore::operator=(ManageStore const& other){
	if(this != &other){
		data = other.data;
	}
	return *this;
}

ManageStore::~ManageStore(){}

void ManageStore::load_data(std::string const& path){
	ReadWriteXML xml(path);
	ParseXML parser;
	data = parser.parse(xml.read_file_content());
}

ManageStore ManageStore::add(Product const& product){
	return (*this) + product;
}

ManageStore ManageStore::add(std::vector<Product> const& prodcuts_list){
	return (*this) + prodcuts_list;
}

ManageStore ManageStore::remove(Product const& product){
	return (*this) - product;
}

ManageStore ManageStore::remove(std::vector<Product> const& products_list){
	return (*this) - products_list;
}

ManageStore& ManageStore::operator+(Product const& product){
	data.push_back(product);
	return *this;
}

ManageStore& ManageStore::operator+(std::vector<Product> const& prodcuts_list){
	for(auto iterator : prodcuts_list)
		(*this)+iterator;
	return *this;
}

ManageStore& ManageStore::operator-(Product const& product){
	for(unsigned int index=0; index < data.size(); index++)
		if(data[index]==product){
			data.erase(data.begin()+index);
			break;
		}
		
	return *this;
}

ManageStore& ManageStore::operator-(std::vector<Product> const& products_list){
	for(auto iterator : products_list)
		(*this)-iterator;
	return *this;
}


std::vector<Product> ManageStore::get_data(){
	return data;
}

void ManageStore::display(){
	if(data.empty()){
		std::cout << "No data was loaded. Load data first!\n";
		return;
	}

	print_header();
	for(auto iterator : data)
		iterator.print();
	std::cout << std::endl;
}

void ManageStore::print_header(){
	std::cout << "Id" << std::setw(30) << "Name" << std::setw(30)  << "Category" << std::setw(30) << "Origin" << std::setw(30) << "Prince" << std::endl;
}
