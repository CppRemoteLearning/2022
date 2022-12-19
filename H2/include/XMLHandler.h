#ifndef _PRODUCT_MANAGER_XML_HANDLER_H_
#define _PRODUCT_MANAGER_XML_HANDLER_H_

#include "Product.h"
#include <vector>
#include <utility>
#include <list>

class XMLHandler
{
public:
  XMLHandler(std::string file): path_to_file_(file) {}
  XMLHandler(std::string file, std::vector<std::pair<std::string, double>> file_content):
                                        path_to_file_(file), file_content_(file_content) {}
  XMLHandler(std::string file, std::list<Product> file_content);
  ~XMLHandler() = default;
  XMLHandler (const XMLHandler& other);
  XMLHandler (XMLHandler&& other);
  XMLHandler& operator=(const XMLHandler& other);
  XMLHandler& operator=(XMLHandler &&other);
  std::vector<std::pair<std::string, double>> getValues() {return file_content_;}
  void readFromFile();
  void writeToFile();

private:
  std::string path_to_file_;
  std::vector<std::pair<std::string, double>> file_content_;
};

#endif