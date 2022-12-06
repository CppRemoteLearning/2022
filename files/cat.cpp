#include "animal.h"
#include <string>
#include <iostream>
class Cat : public virtual Animal {
public:
    Cat(std::string _name): Animal(_name) {}
    void saySomething() { std::cout<<"Miau\n"; }
};