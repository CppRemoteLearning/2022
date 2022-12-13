#include <iostream>
#include <vector>
#include <string>
#include "xmlClass.hpp"

using namespace std;

/*
TO DO

1. Implement xml read-write classes
2. Make a separate hpp file for each class, for a cleaner code
3. Create the game loop

*/

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
        cout << "copy assignment operator called\n";
        if (this == &p)
            return *this;
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

    //Move assignment operator called
    Product& operator=(const Product&& p)
    {
        cout << "move assignment operator called\n";
        if (this == &p)
            return *this;
        name = p.name;
        price = p.price;
        return *this;
    }

    //setters
    void setName(const string& name_) { name = name_; }
    void setPrice(double price_){ price = price_; }

    //getters
    const string& getName() const {return name;}
    double getPrice() const {return price;}


};

class Store {
    string name;
    vector<Product> products;
    public:
    //Constructors
    Store();
    Store(string name_) : name(name_) {};
    Store(string name_, vector<Product> p) : name(name_), products(p) {}

    //Copy constructor
    Store(const Store& s) : name(s.name), products(s.products)
    {
        cout << "copy constructor called";
    }

    //Copy assignment operator
    Store& operator=(const Store& s)
    {
        cout << "copy assignment operator called\n";
        if (this == &s)
            return *this;

        name = s.name;
        products=s.products;
        return *this;
    }

    //Destructor
    ~Store()
    {
        cout << "destructor called\n";
    }

    //Move constructor
    Store(const Store&& s) : name(move(s.name)), products(move(s.products))
    {
        cout << "move constructor called\n";
    }

    //Move assignment operator
    Store& operator=(const Store&& s)
    {
        cout << "move assignment operator called\n";
        if (this == &s)
            return *this;
        
        name = s.name;
        products=s.products;
        return *this;
    }

    //setters
    void setName(string name_) {name = name_;}
    void setProducts(vector<Product> p) {products = p;}

    //getters
    const string& getName() { return name; }
    const vector<Product>& getProducts() { return products; }

    //function to add products to the store's inventory
    //TO DO: add code to read from a file
    void addProducts()
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

    //function to show products of the store's inventory
    void printProducts()
    {
        for (int i=0; i<products.size(); i++)
        {
            cout << products[i].getName() << ' ';
            cout << products[i].getPrice() << '\n';
        }
    }
};


int main()
{
    //vector<Product> products;
    //Product product("lapte", 3.99);
    //products.push_back(product);
    //Store store("Markt", products);
    Store store("Markt");
    store.addProducts(); //pass an argument to xml file
    store.printProducts();

}