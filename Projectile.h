#ifndef Projectile_H
#define Projectile_H

#include "Coordinates.h";
#include "Monster.h";
#include "Hero.h";
#include "Boss.h";

class Projectile {
private:
    Coordinates* p_position;
    int p_damages;
    bool p_players; //evitons le suicide et de pouvoir nous faire mal avec nos propres projectiles
    int p_direction; //le tir se déplace vers un point cardinal

public:
    Projectile(Hero h, int d);
    Projectile(Monster m, int d);
    Projectile(Boss b, int d);
    Coordinates* getCoordinates() { return p_position; }
    int damages() { return p_damages; }
    bool playerProjectile() { return p_players; }
    void move();
};

#endif