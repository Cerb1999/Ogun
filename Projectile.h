#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "Coordinates.h";
#include "Monster.h";
#include "Hero.h";

class Projectile {
private:
    Coordinates p_position;
    int p_damages;
    bool p_players; //evitons le suicide et de pouvoir nous faire mal avec nos propres projectiles
    int p_direction; //le tir se déplace vers un point cardinal {N, NE, E, SE, S, SW, W, NW}
    int p_hitbox;

public:
    Projectile(bool players, int direction, int size, int damages, int x, int y, int* map);
    Coordinates* getCoordinates() { return &p_position; }
    int damages() { return p_damages; }
    bool playerProjectile() { return p_players; }
    int getDirection() { return p_direction; }
    int hitBox() { return p_hitbox; }
    void move();
    bool murred() { return p_position.murred(p_direction); }
};

#endif
