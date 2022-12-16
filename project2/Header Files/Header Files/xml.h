#ifndef _XML_H_
#define _XML_H_

#include "product.h"
#include <string>
#include <vector>
#include <utility>
#include <list>

class XMLHandler
{
public:
    XMLHandler(std::string file);
    XMLHandler(std::string file, std::vector<Produs> file_content);
    ~XMLHandler() {}
    std::vector<Produs> getValues() { return file_content_; }
    void readFromFile();
    void writeToFile();

private:
    std::string path_to_file_;
    std::vector<Produs> file_content_;
};

#endif