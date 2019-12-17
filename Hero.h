#ifndef HERO_H_
#define HERO_H_

//#include "Coordinates.h";
#include "Projectile.h";

class Game; class Level; class Boss; class Monster; class Drop;

class Hero {
private:
    short h_hp;
    short h_speed;
    short h_damages;
    Coordinates h_position;
    short h_focus;

public:
    Hero(short x, short y, short* map);
    short hpLeft(){ return h_hp; };
    short damages();
    void fire(short direction);
    bool hit(Projectile p); // contact avec p, renvoie le bool correspondant et effectue les actions nescessaires
    bool contact(Monster m);
    void move(short direction);
    void die(short damages);
    bool alive() { return h_hp > 0; }
    Coordinates* getCoordinates() { return &h_position; }
    char* toString() { return "je suis vivant"; }
    void heal() ;
    short focus() { return h_focus; }
};

#endif
