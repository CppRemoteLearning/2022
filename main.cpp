#include "files/cat.cpp"
#include "files/animal.h"
#include <iostream>

int main(){
    Cat c = Cat("Garfield");
    std::cout<<c.getName()<<" says: ";
    c.saySomething();
}