#include "store.h"
#include "file.h"

int main() {
    StoreIO storeIO = StoreIO("/home/yuda/2022/tema2DHoka/date.txt");
    Store store;
    storeIO.read(store);
    std::cout << store;
    store.delProduct("paine");
    std::cout << store;
    storeIO.write(store);
    store.displayProduct("apa");
    Product a = Product("ceva",1,2);
    Product b = Product(a);
    std::cout<<b;
    return 0;
}