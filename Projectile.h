#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "Coordinates.h";
#include "Monster.h";
#include "Hero.h";

class Projectile {
private:
    Coordinates p_position;
    short p_damages;
    bool p_players; //evitons le suicide et de pouvoir nous faire mal avec nos propres projectiles
    short p_direction; //le tir se déplace vers un poshort cardinal {N, NE, E, SE, S, SW, W, NW}
    short p_hitbox;

public:
    Projectile(bool players, short direction, short size, short damages, short x, short y, short* map);
    Coordinates* getCoordinates() { return &p_position; }
    short damages() { return p_damages; }
    bool playerProjectile() { return p_players; }
    short getDirection() { return p_direction; }
    short hitBox() { return p_hitbox; }
    void move();
    bool murred() { return p_position.murred(p_direction); }
};

#endif
