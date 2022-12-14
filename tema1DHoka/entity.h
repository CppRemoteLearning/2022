#include <iostream>
using namespace std;
#pragma once
class Entity {
    private:
    string name;
    public:
    Entity(string newName) : name(newName) {}
    void printName();
    virtual void print();};