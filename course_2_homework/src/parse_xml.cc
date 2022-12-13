#include "../include/parse_xml.h"

ParseXML::ParseXML():data(std::vector<Product>()){}

ParseXML& ParseXML::operator=(ParseXML const& other){
	if(this != &other)
		data = other.data;
	return *this;
}

ParseXML::~ParseXML(){}

std::vector<Product> ParseXML::parse(std::vector<std::string> file_content){
	std::vector<std::string>::size_type size = file_content.size();
	std::vector<std::string> unconverted_data;
	bool flag = false;
	for(unsigned int index=0; index<size; index++){
		if(file_content[index].find("<product>") != std::string::npos)
			flag=true;
		
		while(flag){
			index++;

			if(file_content[index].find("</product>") != std::string::npos){
				data.push_back(convert_data(unconverted_data));
				unconverted_data.clear();
				flag=false;
				continue;
			}
			unconverted_data.push_back(get_info(file_content[index]));
		}
	}
	return data;
}

std::vector<Product> ParseXML::get_data(){
	return data;
}

std::string ParseXML::get_info(std::string row){
	unsigned int pos1 = row.find(">",0,1);
	unsigned int pos2 = row.find("<",pos1,1);
	return row.substr(pos1+1, pos2-pos1-1);
}

Product ParseXML::convert_data(std::vector<std::string> temp_data){
	std::tuple<unsigned int, std::string, std::string, std::string, float> temp;

	temp = {std::stoul(temp_data[0]),temp_data[1], temp_data[2], temp_data[3], std::stof(temp_data[4])};

	Product product(temp);
	return product;
}
