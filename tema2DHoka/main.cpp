#include "store.h"
#include "file.h"

int main() {
    StoreIO storeIO = StoreIO("/home/yuda/2022/tema2DHoka/date.txt");
    Store store;
    storeIO.read(store);
    cout << store;
    store.delProduct("paine");
    cout << store;
    storeIO.write(store);
    store.displayProduct("apa");
    return 0;
}