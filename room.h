#ifndef Room_H
#define Room_H

#include "Layout.h"; 

class Room {
private:
  Room* r_next;
  Room* r_previous;
  Layout r_layout; //tableau 2D
  bool r_cleared;
  bool r_occupied;
  int r_type;
  int r_id;

public:
 Room(int t, int index, int depth);
 static Room* rooms(int nbRooms, int depth);
 bool cleared() { return r_cleared; } 
 bool occupied() { return r_occupied; }
 int index() { return r_id; }
 Layout layout() { return r_layout; }
 void clear();
 void enter();
 void setPrevious(Room* r);
 void setNext(Room* r);
};

#endif