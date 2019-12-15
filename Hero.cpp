#include "Hero.h"
#include <stdlib.h>

Hero::Hero(Coordinates* c) {
    h_hp = 6;
    h_speed = 1;
    h_damages = 1;
    h_position = (Coordinates*) malloc (2*sizeof(double)+sizeof(int*));
    h_position = c;
}

int Hero::hpLeft() {
    return h_hp;
}

int Hero::damages() {
    return h_damages;
}

bool Hero::hit(Projectile p) {
    return h_position->contact(p.getCoordinates(), p.hitBox());
}

void Hero::move(int d) {
	if ( d > 0 && d < 9) {
		h_position->move(d, 1); //move based on keyboard input
	}
}

void Hero::die(int damages) {
    h_hp -= damages;
}

Projectile* Hero::fire(int direction) {
    Projectile p = Projectile(true, direction, 1, h_damages, h_position);
    return &p; 
}

void Hero::heal() {
    h_hp++;
}
