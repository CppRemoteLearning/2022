#include <XMLHandler.h>
#include <iostream>
#include <fstream>

XMLHandler::XMLHandler(std::string file, std::list<Product> file_content)
{
  path_to_file_ = file;
  std::list<Product>::const_iterator it;
  for (it = file_content.begin(); it != file_content.end(); ++it)
  {
    file_content_.push_back(std::make_pair(it->getName(), it->getPrice()));
  }
}

XMLHandler::XMLHandler(const XMLHandler& other)
{
  std::cout << "XMLHandler copy constructor called." << std::endl;
  path_to_file_ = other.path_to_file_;
  file_content_ = other.file_content_;
}

XMLHandler::XMLHandler(XMLHandler&& other)
{
  std::cout << "XMLHandler move constructor called." << std::endl;
  path_to_file_ = std::move(other.path_to_file_);
  file_content_ = std::move(other.file_content_);
}

// can I used std::swap?
XMLHandler& XMLHandler::operator=(const XMLHandler& other)
{
  std::cout << "XMLHandler copy assignment operator called" << std::endl;
  path_to_file_ = other.path_to_file_;
  file_content_ = other.file_content_;
  return *this;
}

XMLHandler& XMLHandler::operator=(XMLHandler&& other)
{
  std::cout << "XMLHandler move assignment operator called" << std::endl;
  path_to_file_ = std::move(other.path_to_file_);
  file_content_ = std::move(other.file_content_);
  return *this;
}

void XMLHandler::readFromFile()
{
  std::cout << "XMLHandler::readFromFile called." << std::endl;
  std::ifstream xmlFile;
  xmlFile.open(path_to_file_);
  if (xmlFile.is_open())
  {
    std::string line;
    while(getline(xmlFile, line))
    {
      if (line.find("<name>") != std::string::npos)
      {
        int beg = line.find("name") + 5;
        int end = line.find("</");
        //overkill
        file_content_.push_back(std::make_pair(line.substr(beg, end-beg), 0.0));
      }
      else if (line.find("price") != std::string::npos)
      {
        int beg = line.find("price") + 6;
        int end = line.find("</");
        //overkill
        file_content_[file_content_.size()-1].second = std::stod(line.substr(beg, end-beg));
      }
    }
    xmlFile.close();
  }
  else
  {
    std::cout << "Cannot open the file." << std::endl;
  }
}

void XMLHandler::writeToFile()
{
  std::cout << "XMLHandler::writeToFile called." << std::endl;
  std::ofstream xmlFile;
  xmlFile.open(path_to_file_, std::ofstream::out | std::ofstream::trunc);
  if (xmlFile.is_open()){
    xmlFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<Store>\n";
    std::vector<std::pair<std::string, double>>::const_iterator it;
    for (it = file_content_.begin(); it != file_content_.end(); ++it)
    {
      xmlFile << "\t<product>\n\t\t<name>" << it->first << "</name>\n";
      xmlFile << "\t\t<price>" << it->second << "</price>\n\t</product>\n";
    }
    xmlFile << "</Store>";
    xmlFile.close();
  }
  else
  {
    std::cout << "Cannot open the file." << std::endl;
  }
}