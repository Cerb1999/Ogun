#include "Hero.h";
#include "Monster.h";
#include "Level.h";

class Game{
public:
    Game();
    void spawnMonsters(Layout l);

private:
    Hero player;
    Level floor;
    Room activeRoom;
    Monster monsters[];
};