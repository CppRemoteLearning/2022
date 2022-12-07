#include <iostream>

class Dog {
    char Sound[10]="woof!";
    public:
    Dog();
    void makeSound()
    {
        std::cout << Sound;
    }
};