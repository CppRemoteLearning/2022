#include <XMLHandler.h>
#include <iostream>
#include <fstream>

XMLHandler::XMLHandler(std::string file)
{
  std::cout << "XMLHandler constructor called." << std::endl;
  path_to_file_ = file;
}

XMLHandler::XMLHandler(std::string file, std::vector<std::pair<std::string, double>> file_content)

{
  std::cout << "XMLHandler constructor called." << std::endl;
  path_to_file_ = file;
  file_content_ = file_content;
}


// XMLHandler::~XMLHandler()
// {
//   std::cout << "XMLHandler destructor called." << std::endl;
// }

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

std::vector<std::pair<std::string, double>> XMLHandler::readFromFile()
{
  std::cout << "XMLHandler::readFromFile called." << std::endl;
  std::ifstream xmlFile;
  std::string line;
  std::vector<std::pair<std::string, double>> values;
  std::pair<std::string, double> tempPair;
  xmlFile.open(path_to_file_);
  if (xmlFile.is_open())
  {
    while(getline(xmlFile, line))
    {
      if (line.find("<name>") != std::string::npos)
      {
        int beg = line.find("name") + 5;
        int end = line.find("</");
        tempPair.first = line.substr(beg, end-beg);
      }
      else if (line.find("price") != std::string::npos)
      {
        int beg = line.find("price") + 6;
        int end = line.find("</");
        tempPair.second = std::stod(line.substr(beg, end-beg));
        values.push_back(tempPair);
      }
    }
    xmlFile.close();
    file_content_ = values;
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
  xmlFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<Store>\n";
  for (auto it = file_content_.begin(); it != file_content_.end(); ++it)
  {
    xmlFile << "\t<product>\n\t\t<name>" << (*it).first << "</name>\n";
    xmlFile << "\t\t<price>" << (*it).second << "</price>\n\t</product>\n";
  }
  xmlFile << "</Store>";
}