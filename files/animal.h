#pragma once
#include <string>
class Animal {
private:
    std::string name;
public:
    Animal(std::string _name);
    std::string getName(); 
    virtual void saySomething();
};