#include"entity.h"
void Entity::printName() {
    cout<<"Sunt " << name;
}
void Entity::print() {
    printName();
    cout<<", o entitate\n";
}