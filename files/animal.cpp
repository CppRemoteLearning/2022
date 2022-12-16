#include "animal.h"
#include <string>
#include "iostream"

Animal::Animal(std::string _name): name(_name) {}

std::string Animal::getName() {return name;}

void Animal::saySomething() {}