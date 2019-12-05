#ifndef Level_H
#define Level_H

//#include "Room.h";
#include "Monster.h";
#include "Destructible.h";

class Level {
private:
  //int l_nbRooms;
  int l_depth;
  Monster l_monsters[];
  Destructibles l_crates[];
  //Room* l_rooms;

public:
  Level(/*int rooms*/, int d);
  void loadLayout();
  //int getNbRooms() { return l_nbRooms; }
  int getDepth() { return l_depth; }
};

#endif
