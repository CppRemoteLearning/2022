#include <iostream>
#include <string.h>

class Product{
    private:
        std::string name;
        float price;
        int quantity;

    public:
        Product();

        Product(std::string name, float price, int quantity);

        Product(const Product &p); // Copy Constructor

        Product& operator=(const Product &p); // Copy Assignment Operator

        Product(Product&& p); // Move Constructor

        Product& operator=(Product &&p); // Move Assignment Operator

        ~Product(); // Destructor

        std::string getName();
        float getPrice();
        int getQuantity();

        void setName(std::string _name);
        void setPrice(float _price);
        void setQuantity(int _quantity);

        std::string toString();
    };