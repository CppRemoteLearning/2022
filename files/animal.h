#ifndef PROJECT_FILES_ANIMAL_H_ // cannot use 2022 instead of PROJECT
#define PROJECT_FILES_ANIMAL_H_
#include <string>
class Animal {
private: std::string name;
public: Animal(std::string _name); 
    std::string getName(); 
    virtual void saySomething();
};
#endif 