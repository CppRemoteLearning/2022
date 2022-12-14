#ifndef _PROJECT_MODEL_PRODUCT_H_
#define _PROJECT_MODEL_PRODUCT_H_

#include <string>

class Product
{
private:
    std::string name;
    int weight;
public:
    Product(std::string _name, int _weight);
    //copy constructor
    Product(const Product & p)=default;
    //move constructor 
    Product(Product&& p)=default; 
    Product& operator=(Product const &p); 
    bool operator==(Product const& p) const;
    std::string getName();
    int getWeight();
    ~Product();
};

#endif 