#ifndef Destructible_H
#define Destructible_H

#include "Coordinates.h";
#include "Projectile.h";

class Level; class Game;

class Destructible {
private: 
  Coordinates* d_coord;
  
public:
Destructible(Coordinates c);
bool hit(Projectile p); 

};

#endif
