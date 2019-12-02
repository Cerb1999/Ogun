#include "Coordinates.h";

Coordinates::Coordinates(double x, double y) {
    setX(x);
    setY(y);
}

void Coordinates::setX(double x) {
    c_x = x;
}

void Coordinates::setY(double y) {
    c_y = y;
}

void Coordinates::move(double x, double y) {
    setX(x + c_x);
    setY(y + c_y);
}