#include "store.hpp"

    Store::Store(std::string name_) : name(name_) 
    {}
    Store::Store(std::string name_, std::vector<Product> p) : name(name_), products(p) 
    {}

    //Copy constructor
    Store::Store(const Store& s) : name(s.name), products(s.products)
    {
        std::cout << "copy constructor called";
    }

    //Copy assignment operator
    Store& Store::operator=(const Store& s)
    {
        std::cout << "copy assignment operator called\n";
        if (this == &s)
            {
                return *this;
            }

        name = s.name;
        products=s.products;
        return *this;
    }

    //Destructor
    Store::~Store()
    {
        std::cout << "destructor called\n";
    }

    //Move constructor
    Store::Store(const Store&& s) : name(move(s.name)), products(move(s.products))
    {
        std::cout << "move constructor called\n";
    }

    //Move assignment operator
    Store& Store::operator=(const Store&& s)
    {
        std::cout << "move assignment operator called\n";
        if (this == &s)
            {
                return *this;
            }
        
        name = s.name;
        products=s.products;
        return *this;
    }

    //setters
    void Store::setName(std::string name_) 
    {
        name = name_;
    }
    void Store::setProducts(std::vector<Product> p) 
    {
        products = p;
    }

    //getters
    const std::string& Store::getName() 
    { 
        return name; 
    }

    const std::vector<Product>& Store::getProducts() 
    { 
        return products; 
    }

    void Store::addProducts(const Product p)
    {
        products.push_back(p);
    }

    void Store::printProducts()
    {
        for (auto i : products)
            {
                std::cout << i.getName() << ' ' << i.getPrice() << '\n';
            }
    }
