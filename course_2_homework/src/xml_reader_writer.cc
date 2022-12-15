#include "../include/xml_reader_writer.h"

XMLReaderWriter::XMLReaderWriter():path_(NULL),content_(std::vector<std::string>()){}

XMLReaderWriter::XMLReaderWriter(std::string const& path): path_(path){}

XMLReaderWriter::XMLReaderWriter(std::string const& path, std::vector<std::string> content)
    : path_(path), content_(content.begin(), content.end()){}

//copy constructor
XMLReaderWriter::XMLReaderWriter(XMLReaderWriter const& other)
    : path_(other.path_), content_(other.content_.begin(), other.content_.end()){}

//move constructor
XMLReaderWriter::XMLReaderWriter(XMLReaderWriter&& other) noexcept
   : path_(NULL), content_(std::vector<std::string>()){
  path_ = other.path_;
  content_.reserve(other.content_.capacity());

  for(auto const& iterator : other.content_)
    content_.push_back(iterator);

  other.path_ = std::string();
  other.content_.clear();
}

//copy asignment constructor
XMLReaderWriter& XMLReaderWriter::operator=(XMLReaderWriter const& other){
  if(this != &other){
    content_.clear();

    path_ = other.path_;
    content_.reserve(other.content_.capacity());

    for(auto const& iterator : other.content_)
      content_.push_back(iterator);
  }
  return *this;
}

//move asignment constructor
XMLReaderWriter& XMLReaderWriter::operator=(XMLReaderWriter&&  other) noexcept{
  if(this != &other){
    content_.clear();
    path_ = other.path_;
    content_.reserve(other.content_.capacity());

    for(auto const& iterator : other.content_)
      content_.push_back(iterator);

    other.path_ = std::string();
    other.content_.clear();
  }
  return *this;
}

XMLReaderWriter::~XMLReaderWriter(){}

std::vector<std::string> XMLReaderWriter::ReadFileContent(){
  std::ifstream input_file;
  if(OpenFile(input_file)){
    std::string row;
    while(getline(input_file, row))
      content_.push_back(row);
    }
  return content_;
}

std::vector<std::string> XMLReaderWriter::GetContent()const{
  if(content_.empty())
    std::cout << path_ << " file is empty!" << std::endl;
  return content_;
}

std::string XMLReaderWriter::GetPath() const{
  return path_;
}

bool XMLReaderWriter::SetPath(std::string const& path){
  try{
    if(Exist(path))
      return true;
    throw std::invalid_argument(path + " invalid file path!");
  }
  catch (const std::invalid_argument& event){
    std::cout << event.what();
    return false;
  }
}

bool XMLReaderWriter::Exist(std::string const& path) const{
  std::ifstream check_file(path, std::ifstream::in);
  return check_file.is_open();
}

bool XMLReaderWriter::OpenFile(std::ifstream& input_file) const{
  try{
    if(Exist(path_)){
      input_file.close();
      input_file.open(path_, std::ifstream::in);
      return true;
    }
    throw std::invalid_argument(path_ + " invalid file path!");
  }
  catch(const std::invalid_argument& event){
    std::cout << event.what();
    return false;
  }
}
