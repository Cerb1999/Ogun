#include "Coordinates.h"

Coordinates::Coordinates(double x, double y, int** map) {
    c_x = x;
    c_y = y;
		g_map = map;
}

void Coordinates::setX(double x) {
    c_x = x;
}

void Coordinates::setY(double y) {
    c_y = y;
}

bool Coordinates::contact(Coordinates* c, double hitBox) {
    return (c_x >= c->getX()-hitBox && c_x <= c->getX()+hitBox && c_y >= c->getY()-hitBox && c_y <= c->getY()+hitBox);
}

void Coordinates::move(int direction, int id) {
	double x = 0; double y = 0;
	switch (direction) {
		case 1:
			y = 1;
			break;
		case 2: 
			x = 1;
			y = 1;
			break;
		case 3:
			x = 1;
			break;
		case 4:
			x = 1;
			y = -1;
			break;
		case 5: 
			y = -1;
			break;
		case 6:
			x = -1;
			y = -1;
			break;
		case 7:
			x = -1;
			break;
		case 8:
			x = -1;
			y = 1;
			break;
	}
  double nextX = c_x + x; double nextY = c_y + y;
  int destTile = g_map[int(nextX)][int(nextY)];
  if ( destTile == 1 || (destTile > 6 && destTile <= 10) ) {
			if (id == 3 || id == 4) {
				g_map[int(nextX)][int(nextY)] = id;      
				g_map[int(c_x)][int(c_y)] = 1;
			}
      setX(nextX);
      setY(nextY);
  }
}
