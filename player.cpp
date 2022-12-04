#include "entity.h"
class Player : public virtual Entity {
    public:
    Player(string name) : Entity(name) {}
    void print() {
        printName();
        cout<<", un player\n";
    }
};