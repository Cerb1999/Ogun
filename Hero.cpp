#include "Hero.h"
#include <stdlib.h>

Hero::Hero(double x, double y, int* map) :
    h_position(Coordinates(x,y,map))
{
    h_hp = 6;
    h_speed = 1;
    h_damages = 1;
    
    h_focus = 3;
}

int Hero::damages() {
    return h_damages;
}

bool Hero::hit(Projectile p) {
    return h_position.contact(p.getCoordinates(), p.hitBox());
}

void Hero::move(int d) {
	if ( d > 0 && d < 9) {
        h_focus = d;
        if (h_position.move(d, 1)) {
            h_hp -= 1;
        } //move based on keyboard input
	}
}

void Hero::die(int damages) {
    h_hp -= damages;
}

void Hero::fire(int direction) {
    h_focus = direction;
}

void Hero::heal() {
    h_hp++;
}
