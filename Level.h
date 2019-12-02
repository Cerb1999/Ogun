#ifndef Level_H
#define Level_H

#include "Room.h";

class Level {
private:
  int l_nbRooms;
  int l_depth;
  Room* l_rooms;

public:
  Level(int rooms, int d);
  int getNbRooms() { return l_nbRooms; }
  int getDepth() { return l_depth; }
};

#endif