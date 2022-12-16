#include <iostream>
#include <string.h>

class Product{
    public:
        Product();

        Product(std::string name, float price, int quantity);

        Product(const Product& other); // Copy Constructor

        Product& operator=(const Product& other); // Copy Assignment Operator

        Product(Product&& other) noexcept; // Move Constructor

        Product& operator=(Product&& other) noexcept; // Move Assignment Operator

        ~Product(); // Destructor

        std::string getName();
        float getPrice();
        int getQuantity();

        void setName(std::string _name);
        void setPrice(float _price);
        void setQuantity(int _quantity);

        std::string toString();

    private:
        std::string name;
        float price;
        int quantity;
    };