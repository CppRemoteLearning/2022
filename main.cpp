#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
    string name;
    double price;
    public:
    //Constructors
    Product();
    Product(string name_, double price_) : name(name_), price(price_) {}

    //Copy constructor
    Product(const Product& p) : name(p.name), price(p.price) 
    { cout << "copy constructor called\n"; }

    //Copy assignment operator
    Product& operator=(const Product& p)
    {
        if (this == &p)
            return *this;
        cout << "copy assignment operator called\n";
        name = p.name;
        price = p.price;
        return *this;
    }

    //Destructor
    ~Product()
    {
        cout << "destructor called\n";
    }
    
    //Move constructor
    Product(const Product&& p) : name(move(p.name)), price(move(p.price))
    {
        cout << "move constructor called\n";
    }
};

int main()
{
    Product p1("lapte", 3.5);
    Product p2(p1);
}