#include <iostream>
#include <string.h>
#include <vector>
#include "../product/Product.h"

class Store {
    private:
        std::string name;
        std::vector<Product> products;

    public:
        Store();

        Store(std::string name, std::vector<Product> products);

        std::string getName();

        std::vector<Product> getProducts();

        void setName(std::string name);

        void setProducts(std::vector<Product> products);

        std::string toString();
};