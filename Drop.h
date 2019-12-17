#ifndef Drop_H
#define Drop_H

#include "Coordinates.h";
#include "Hero.h";

class Level; class Game;

class Drop {
private: 
  Coordinates d_coord;
  bool d_potion;
  
public:
Drop(short x, short y, short* map, bool potion);
bool pickedUp(Hero* h);
Coordinates* getCoordinates() { return &d_coord; }
bool isAPotion() { return d_potion; }

};

#endif