#include "Hero.h"

Hero::Hero(double x, double y) {
    h_hp = 6;
    h_speed = 1;
    h_damages = 1;
    h_position = &Coordinates(x,y);
}

int Hero::hpLeft() {
    return h_hp;
}

int Hero::damages() {
    return h_damages;
}

bool Hero::hit(Projectile p) {
    return h_position->contact(p.getCoordinates());
}

bool Hero::hit(Monster m) {
    return h_position->contact(m.position());
}

void Hero::move() {
    //h_position->move(); //move based on keyboard input
}