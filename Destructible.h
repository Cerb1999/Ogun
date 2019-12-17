#ifndef Destructible_H
#define Destructible_H

#include "Coordinates.h";
#include "Projectile.h";

class Level; class Game;

class Destructible {
private: 
  Coordinates d_coord;
  
public:
Destructible(short x, short y, short* map);
bool hit(Projectile p);
Coordinates* getCoordinates() { return &d_coord; } 

};

#endif
