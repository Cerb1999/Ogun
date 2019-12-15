#ifndef Destructible_H
#define Destructible_H

#include "Coordinates.h";
#include "Projectile.h";

class Level; class Game;

class Destructible {
private: 
  Coordinates d_coord;
  
public:
Destructible(double x, double y, int* map);
bool hit(Projectile p);
Coordinates* getCoordinates() { return &d_coord; } 

};

#endif
