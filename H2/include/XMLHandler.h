#ifndef _PRODUCT_MANAGER_XML_HANDLER_H_
#define _PRODUCT_MANAGER_XML_HANDLER_H_

#include "Product.h"
#include <string>
#include <vector>
#include <utility>

class XMLHandler
{
private:
  std::string path_to_file;
  std::vector<std::pair<std::string, double>> file_content;
public:
  XMLHandler();
  ~XMLHandler();
  XMLHandler (const XMLHandler& other) = default;
  XMLHandler (XMLHandler&& other) = default;
  XMLHandler& operator=(const XMLHandler& other);
  XMLHandler& operator=(XMLHandler &&other);
  std::vector<std::pair<std::string, double>> readFromFile(std::string path_to_file);
  void writeToFile(std::string path_to_file, std::vector<std::pair<std::string, double>> file_content);
};

#endif