#include "../include/read_write_xml.h"

ReadWriteXML::ReadWriteXML(std::string const& path):file_path(path){}

ReadWriteXML& ReadWriteXML::operator=(ReadWriteXML const& other){
	if(this != &other){
		file_content = other.file_content;
	}
	return *this;
}

ReadWriteXML::~ReadWriteXML(){}

std::vector<std::string> ReadWriteXML::read_file_content(){
	std::ifstream input_file;
	if(open_file(input_file)){
		std::string row;
		while(getline(input_file, row))
			file_content.push_back(row);
	}
	return file_content;
}

std::vector<std::string> ReadWriteXML::get_file_content(){
	if(file_content.empty())
		std::cout << file_path << " file is empty!" << std::endl;
	return file_content;
}

bool ReadWriteXML::set_file_path(std::string const& new_file_path){
	if(exist(new_file_path)){
		file_path = new_file_path;
		return true;
	}
	throw std::invalid_argument(new_file_path + " invalide file path!" );
	return false;
}

bool ReadWriteXML::exist(std::string const& path) const{
	std::ifstream check_file(path);
	return check_file.is_open();
}

bool ReadWriteXML::open_file(std::ifstream& input_file) const{
	if(exist(file_path)){
		input_file.close();
		input_file.open(file_path, std::ifstream::in);
		return true;
	}
	throw std::invalid_argument(file_path + " invalid file path!");
	return false;
}
