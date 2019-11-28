#include "Room.h"

class Level {
public:
  Level(int rooms, int d);
  int getNbRooms();
  int getDepth();

private:
  int nb_rooms;
  int depth;
  Room rooms[];
};
