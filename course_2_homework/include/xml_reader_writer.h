#ifndef STORE_INCLUDE_XML_READER_WRITER_H_
#define STORE_INCLUDE_XML_READER_WRITER_H_

#include <fstream>
#include <iostream>
#include <vector>

#include "product.h"

class XMLReaderWriter{
public:
  XMLReaderWriter();
  XMLReaderWriter(std::string const& path);
  XMLReaderWriter(std::string const& path, std::vector<std::string> content);
  XMLReaderWriter(XMLReaderWriter const& other);  //copy constructor
  XMLReaderWriter(XMLReaderWriter&& other) noexcept; //move constructor
  XMLReaderWriter& operator=(XMLReaderWriter const& other);  //copy asignment constructor
  XMLReaderWriter& operator=(XMLReaderWriter&& other) noexcept; //move asignment constructor
  ~XMLReaderWriter();
  std::vector<std::string> ReadContent();
  void WriteContent(std::vector<Product> const& data, std::string const& name);
  std::vector<std::string> GetContent() const;
  std::string GetPath() const;
  bool SetPath(std::string const& path);
private:
  bool Exist(std::string const& path) const;
  bool OpenFile(std::ifstream& input_file) const;
  void WriteProduct(std::ofstream& output_file, Product const& product);
  std::string path_;
  std::vector<std::string> content_;
};
#endif //STORE_INCLUDE_XML_READER_WRITER_H_
