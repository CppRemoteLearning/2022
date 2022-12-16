#include "../include/xml_reader_writer.h"

XMLReaderWriter::XMLReaderWriter():path_(std::string()),content_(std::vector<std::string>()){}

XMLReaderWriter::XMLReaderWriter(std::string const& path): path_(path){}

XMLReaderWriter::XMLReaderWriter(std::string const& path, std::vector<std::string> content)
    : path_(path), content_(content.begin(), content.end()){}

//copy constructor
XMLReaderWriter::XMLReaderWriter(XMLReaderWriter const& other)
    : path_(other.path_), content_(other.content_.begin(), other.content_.end()){}

//move constructor
XMLReaderWriter::XMLReaderWriter(XMLReaderWriter&& other): path_(other.path_){
  content_.reserve(other.content_.capacity());

  for(auto const& iterator : other.content_)
    content_.push_back(iterator);
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
XMLReaderWriter& XMLReaderWriter::operator=(XMLReaderWriter&&  other){
  if(this != &other){
    content_.clear();
    path_ = other.path_;
    content_.reserve(other.content_.capacity());

    for(auto const& iterator : other.content_)
      content_.push_back(iterator);
  }
  return *this;
}

XMLReaderWriter::~XMLReaderWriter(){
  if(!content_.empty()){
    content_.clear();
    path_ = std::string();
  }
}

std::vector<std::string> XMLReaderWriter::ReadContent(){
  std::ifstream input_file;
  if(OpenFile(input_file)){
    std::string row;
    while(getline(input_file, row))
      content_.push_back(row);
    }
  return content_;
}

void XMLReaderWriter::WriteContent(std::vector<Product> const& data, std::string const& name){
  try{
    if(Exist(path_))
      throw std::invalid_argument(path_ + " invalid file path!");

    std::ofstream output_file(path_);
    output_file << "<?xml version='1.0' encoding='UTF-8'?>\n";
    output_file << "<" << name << ">\n";

    for(auto iterator : data)
      WriteProduct(output_file, iterator);
    
    output_file << "</" << name << ">";
    output_file.close();
  }
  catch(const std::invalid_argument& event){
    std::cout << event.what() << std::endl;
    std::cout << "There is another file with the same name!" << std::endl;
  }
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
    std::cout << event.what() << std::endl;
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
    std::cout << event.what() << std::endl;
    return false;
  }
}

void XMLReaderWriter::WriteProduct(std::ofstream& output_file, Product const& product){
  output_file << "\t<product>\n";
  output_file << "\t\t<id>" << product.GetId() << "</id>\n";
  output_file << "\t\t<name>" << product.GetName() << "</name>\n";
  output_file << "\t\t<category>" << product.GetCategory() << "</category>\n";
  output_file << "\t\t<quantity>" << product.GetQuantity() << "</quantity>\n";
  output_file << "\t\t<price>" << product.GetPrice() << "</price>\n";
  output_file << "\t</product>\n";
}
