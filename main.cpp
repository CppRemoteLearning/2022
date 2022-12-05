#include "entity.h"
#include "player.cpp"
int main() {
    Player p1 = Player("David");
    Player p2 = Player("Gicu");
    Entity e = Entity("Alin");
    p1.print();
    p2.print();
    e.print();
    return 0;}