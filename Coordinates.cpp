#include <iostream>
#include "Coordinates.h"

Coordinates::Coordinates(int x, int y, int* map) {
    c_x = x;
    c_y = y;
    g_map = map;
}

void Coordinates::setX(int x) {
    c_x = x;
}

void Coordinates::setY(int y) {
    c_y = y;
}


bool Coordinates::contact(Coordinates* c, int hitBox) {
    return (c_x >= c->getX()-hitBox && c_x <= c->getX()+hitBox && c_y >= c->getY()-hitBox && c_y <= c->getY()+hitBox);
}

bool Coordinates::move(int direction, int id) {
	bool res = false;
	int x = 0; int y = 0;
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
  int nextX = c_x + x; int nextY = c_y + y;
  int destTile = g_map[nextX*52+nextY];
  if ( destTile == 1 || (destTile >= 6 && destTile < 10) ) {
			if (id == 3 || id == 4) {
				g_map[nextX*52+nextY] = id;
				g_map[c_x*52+c_y] = 1;
			}
			if (id == 1) {
				if (destTile == 7) {
					res = true;
				} else {
					g_map[c_x*52+c_y] = 1;
				}
			}
      setX(nextX);
      setY(nextY);
  }
  return res;
}

bool Coordinates::murred(int d) {
	int x = 0; int y = 0;
	switch (d) {
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
	int nextX = c_x + x; int nextY = c_y + y;
	int destTile = g_map[nextX*52+nextY];
	return (destTile == 1);
}