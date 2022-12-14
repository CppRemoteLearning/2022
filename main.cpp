#include "model/Product.h"
#include "repository/Repository.h"
#include <iostream>

using namespace std;

/*Next step: to implement xml read/write class*/

int main(){
    Repository r;
    r.add(Product("Lemons", 133));
    r.add(Product("Yogurt", 55));

    for(auto p : r.getAll()){
        cout<<p.getName()<<" "<<p.getWeight()<<"\n";
    }
}