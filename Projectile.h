#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "Coordinates.h";
#include "Monster.h";
#include "Hero.h";

class Projectile {
private:
    Coordinates* p_position;
    int p_damages;
    bool p_players; //evitons le suicide et de pouvoir nous faire mal avec nos propres projectiles
    int p_direction; //le tir se déplace vers un point cardinal {N, NE, E, SE, S, SW, W, NW}
    double p_hitBox;

public:
    Projectile(Hero h, int d);
    Projectile(Monster m, int d);
    Projectile(Boss b, int d);
    Projectile(Monster m, int d, double size);
    Projectile(Boss b, int d, double size);
    Coordinates* getCoordinates() { return p_position; }
    int damages() { return p_damages; }
    bool playerProjectile() { return p_players; }
    void move();
};

#endif
