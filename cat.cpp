#include <iostream>

class Cat {
    char Sound[10]="meow!";
    public:
    Cat();
    void makeSound()
    {
        std::cout << Sound;
    }
};