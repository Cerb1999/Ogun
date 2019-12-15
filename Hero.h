#ifndef HERO_H_
#define HERO_H_

//#include "Coordinates.h";
#include "Projectile.h";

class Game; class Level; class Boss; class Monster; class Coin;

class Hero {
private:
    int h_hp;
    int h_speed;
    int h_damages;
    Coordinates* h_position;

public:
    Hero(Coordinates* c);
    int hpLeft(){ return h_hp; };
    int damages();
    Projectile* fire(int direction);
    bool hit(Projectile p); // contact avec p, renvoie le bool correspondant et effectue les actions nescessaires
    bool contact(Monster m);
    void move(int direction);
    void die(int damages);
    bool alive() { return h_hp > 0; }
    Coordinates* getCoordinates() { return h_position; }
    char* toString() { return "je suis vivant"; }
    void heal() ;
};

#endif
