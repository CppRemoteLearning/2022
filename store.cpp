#include "store.hpp"

    Store::Store(string name_) : name(name_) {};
    Store::Store(string name_, vector<Product> p) : name(name_), products(p) {}

    //Copy constructor
    Store::Store(const Store& s) : name(s.name), products(s.products)
    {
        cout << "copy constructor called";
    }

    //Copy assignment operator
    Store& Store::operator=(const Store& s)
    {
        cout << "copy assignment operator called\n";
        if (this == &s)
            return *this;

        name = s.name;
        products=s.products;
        return *this;
    }

    //Destructor
    Store::~Store()
    {
        cout << "destructor called\n";
    }

    //Move constructor
    Store::Store(const Store&& s) : name(move(s.name)), products(move(s.products))
    {
        cout << "move constructor called\n";
    }

    //Move assignment operator
    Store& Store::operator=(const Store&& s)
    {
        cout << "move assignment operator called\n";
        if (this == &s)
            return *this;
        
        name = s.name;
        products=s.products;
        return *this;
    }

    //setters
    void Store::setName(string name_) {name = name_;}
    void Store::setProducts(vector<Product> p) {products = p;}

    //getters
    const string& Store::getName() { return name; }
    const vector<Product>& Store::getProducts() { return products; }

    //function to add products to the store's inventory
    //TO DO: add code to read from a file
    void Store::addProducts()
    {
        
        Product product("", 0);
        //testing purposes
        for (int i=0; i<10; i++)
            {
                product.setName("lapte");
                product.setPrice(i+i/0.33);
                products.push_back(product);
            }
    }

    void Store::printProducts()
    {
        for (int i=0; i<products.size(); i++)
        {
            cout << products[i].getName() << ' ';
            cout << products[i].getPrice() << '\n';
        }
    }
