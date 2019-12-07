#ifndef Hero_H
#define Hero_H

#include "Coordinates.h";
#include "Projectile.h";

class Hero {
private:
    int h_hp;
    int h_speed;
    int h_damages;
    Coordinates* h_position;

public:
    Hero(double x, double y);
    int hpLeft();
    int damages();
    bool hit(Projectile p); // contact avec p, renvoie le bool correspondant et effectue les actions nescessaires
    bool hit(Monster m);
    void move();
    Coordinates* position() { return h_position; }
};

#endif