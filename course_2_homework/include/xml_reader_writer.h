#ifndef STORE_INCLUDE_XML_READER_WRITER_H_
#define STORE_INCLUDE_XML_READER_WRITER_H_

#include <fstream>
#include <iostream>
#include <vector>

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
  std::vector<std::string> ReadFileContent();
  void WriteFileContent();
  std::vector<std::string> GetContent() const;
  std::string GetPath() const;
  bool SetPath(std::string const& path);
   bool Exist(std::string const& path) const;
private:
 
  bool OpenFile(std::ifstream& input_file) const;
  std::string path_;
  std::vector<std::string> content_;
};
#endif //STORE_INCLUDE_XML_READER_WRITER_H_
