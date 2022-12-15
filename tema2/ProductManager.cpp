#include "headers/ProductManager.h"
#include "headers/Product.h"

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