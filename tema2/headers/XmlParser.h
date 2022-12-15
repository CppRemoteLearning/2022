#include <string>
#include <map>

class XmlParser
{
private:
    // xml file path
    std::string filePath;

public:
    XmlParser(std::string file) : filePath(file){}
    ~XmlParser(){}
    //copy constructor 
    XmlParser(const XmlParser& other):filePath(other.filePath){}
    //copy assigment operator
    XmlParser& operator=(const XmlParser& other);
    //move constructor
    XmlParser(XmlParser&& other): filePath(std::move(other.filePath)){}
    //move assigment operator
    XmlParser& operator=(XmlParser&& other);
    // function to read the xml file and return a map containg all its data
    void readProductInfo(std::map<std::string, std::pair<std::string, std::string>> &productInfo);
};
