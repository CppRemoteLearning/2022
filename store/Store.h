#include "../product/Product.h"
#include <vector>

class Store {
    public:
        Store();

        Store(std::string name, std::vector<Product> products);

        std::string getName();

        std::vector<Product> getProducts();

        void setName(std::string _name);

        void setProducts(std::vector<Product> _products);

        std::string toString();

    private:
        std::string name;
        std::vector<Product> products;
};