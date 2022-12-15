#include <vector>
class ProductManager{
    public:
        //constructor
        ProductManager();
        //copy constructor
        ProductManager(const ProductManager& other);
        //move constructor
        ProductManager(const ProductManager&& other);
        //copy assignment operator
        ProductManager& operator=(const ProductManager& other);
        //move assignment operator
        ProductManager& operator=(ProductManager&& other);
        //destructor
        ~ProductManager();    
        
    private:
        //we forward declare the class Product
        //it will be included in cpp 
        std::vector<class Product> Products;
};