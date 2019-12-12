#include "Coordinates.h"

Coordinates::Coordinates(double x, double y) {
    c_x = x;
    c_y = y;
}

void Coordinates::setX(double x) {
    c_x = x;
}

void Coordinates::setY(double y) {
    c_y = y;
}

void Coordinates::move(double x, double y) {
    double nextX = c_x + x; double nextY = c_y + y;
    int** map = Coordinates::getMap();
    double destTile = map[int(nextX)][int(nextY)];
    if ( destTile == 1 || (destTile > 6 && destTile <= 10) ) {
        map[int(c_x)][int(c_y)] = 1;
        setX(nextX);
        setY(nextY);
    }
}

bool Coordinates::contact(Coordinates* c, double hitBox) {
    return (c_x >= c->getX()-hitBox && c_x <= c->getX()+hitBox && c_y >= c->getY()-hitBox && c_y <= c->getY()+hitBox);
}
