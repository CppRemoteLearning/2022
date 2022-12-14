#include <string>

class Product
{
private:
    std::string Name;
    double Price;
    int Quantity;

public:
    // constructor
    Product(const std::string &name, double price, int quantity) : Name(name), Price(price), Quantity(quantity) {}
    // custom constructor for std::pair argument
    Product(const std::pair<const std::string, std::pair<std::string, std::string>> value)
        :Product(value.first, std::stod(value.second.first), std::stoi(value.second.second)){}

    // Copy constructor
    Product(const Product &other) : Name(other.Name), Price(other.Price), Quantity(other.Quantity) {}
    // Move constructor
    Product(const Product &&other) : Name(other.Name), Price(other.Price), Quantity(other.Quantity) {}
    // Copy assigment operator
    Product &operator=(const Product &other);
    // Move assigment operator
    Product &operator=(Product &&other);
    // Destructor
    ~Product() {}
};
