#ifndef Game_H
#define Game_H

#include <vector>;
#include "Hero.h";
#include "Monster.h";
#include "Destructible.h";
#include "Projectile.h"
#include "Level.h";

class Game{
public:
    Game();
    void play();

private:
    Hero player;
    Level floor;
    std::vector<Monster> monsters;
    Boss boss;
    std::vector<Projectile> projectiles;
    std::vector<Destructible> destructibles;
};

#endif
