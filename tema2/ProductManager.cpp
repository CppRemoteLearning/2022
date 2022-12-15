#include "headers/ProductManager.h"
#include "headers/Product.h"
#include <iostream>

ProductManager::ProductManager()
{
    Products = std::vector<Product>();
}
ProductManager::ProductManager(const ProductManager& other)
{
    Products = other.Products;
}
ProductManager::ProductManager(const ProductManager&& other)
{
    Products = std::move(other.Products);
}
ProductManager& ProductManager::operator=(const ProductManager& other)
{
    Products = other.Products;
    return *this;
}
ProductManager& ProductManager::operator=(ProductManager&& other)
{
    Products = std::move(other.Products);
    return *this;
}
ProductManager::~ProductManager()
{
    Products.clear();
}

void ProductManager::addProduct(const Product& product)
{
    Products.push_back(product);
}
void ProductManager::removeProduct(const Product& product)
{
    //find the product in vector
    for(auto it = Products.begin(); it!=Products.end();++it)
    {
        if(&*it == &product)
        {
            Products.erase(it);
            return;
        }
    }
}
int ProductManager::getNumProducts() const
{
    return Products.size();
}
Product& ProductManager::getProduct(int index)
{
    return Products[index];
}

void ProductManager::printProducts() const
{
    for(auto const iter : Products)
    {
        std::cout<<iter<<"\n";
    }
}
