#ifndef MANAGE_STORE_INCLUDE_READ_WRITE_XML_H_
#define MANAGE_STORE_INCLUDE_READ_WRITE_XML_H_

#include <fstream>
#include <iostream>
#include <vector>

class ReadWriteXML{
public:
	ReadWriteXML()=default;
	ReadWriteXML(std::string const& path);
	ReadWriteXML(const ReadWriteXML& other)=default;
	ReadWriteXML(ReadWriteXML&& other)=default;
	ReadWriteXML& operator=(ReadWriteXML const& other);
	~ReadWriteXML();
	std::vector<std::string> read_file_content();
	void write_file_content();
	std::vector<std::string> get_file_content();
	bool set_file_path(std::string const& new_file_path);
private:
	bool exist(std::string const& path) const;
	bool open_file(std::ifstream& input_file) const;

	std::string file_path;
	std::vector<std::string> file_content;
};
#endif //MANAGE_STORE_INCLUDE_READ_WRITE_XML_H_
