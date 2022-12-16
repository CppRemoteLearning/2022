#include <iostream>
// #include "../product/Product.h"
#include "../store/Store.h"

int main() {
    Product p1 = Product("Ciocan", 10.25, 12);
    Product p2 = Product("Surubeltina", 5.65, 3);
    Product p3 = Product("Boloboc", 7.85, 10);
    Product p4 = Product("Topor", 15.55, 4);
    Product p5 = Product("Lopata", 12.35, 6);

    std::cout << p2.toString() << p4.toString();

    std::vector<Product> products1;
    products1.push_back(p1);
    products1.push_back(p2);
    products1.push_back(p5);
    products1.push_back(p4);

    std::string stringOfProducts = "";
    for(Product product : products1) {
        stringOfProducts += product.toString();
    }
    std::cout << stringOfProducts;

    Store s1 = Store("Store1", products1);
    std::cout << s1.toString();


    return 0;
}