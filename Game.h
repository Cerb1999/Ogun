#ifndef Game_H
#define Game_H

#include "Hero.h";
#include "Monster.h";
#include "Destructible.h";
#include "Projectile.h"
#include "Level.h";

class Game{
public:
    Game();
    void spawnMonsters(Layout l);

private:
    Hero player;
    Level floor;
    Monster* monsters;
    Boss boss;
    Projectile projectiles[];
    Destructible destructibles[];
};

#endif
