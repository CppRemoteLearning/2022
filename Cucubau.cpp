#include "headers/MyString.h"
class Cucubau
{
    public:
    MyString* OneLiner;
    Cucubau(std::string newValue){
        OneLiner = new MyString(newValue);
    }
};