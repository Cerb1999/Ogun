#ifndef Coin_H
#define Coin_H

#include "Coordinates.h";
#include "Hero.h";

class Level; class Game;

class Coin {
private: 
  Coordinates* c_coord;
  
public:
Coin(Coordinates c);
bool pickedUp(Hero* h);
Coordinates* getCoordinates() { return c_coord; }

};

#endif