#ifndef _PROJECT_MODEL_PRODUCT_H_
#define _PROJECT_MODEL_PRODUCT_H_

#include <string>
#include <istream>

class Product
{

public:
    Product()=default;
    Product(std::string _name, int _weight);
    //copy constructor
    Product(const Product & p)=default;
    //move constructor 
    Product(Product&& p) noexcept =default; 

    //copy operator
    Product& operator=(Product const &p); 
    //move operator
    Product& operator=(Product &&p) noexcept;

    bool operator==(Product const& p) const;
    
    friend std::ostream& operator<<(std::ostream& writer, const Product &product);
    friend std::istream& operator>>(std::istream& reader, Product &product);

    std::string getName() const;
    int getWeight() const;
    void setName(std::string _name);
    void setWeight(int _weight);

    ~Product();
    
private:
    std::string name;
    int weight;
};

#endif 