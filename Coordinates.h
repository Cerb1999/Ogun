#ifndef Coordinates_H
#define Coordinates_H

class Boss; class Hero; class Destructible; class Projectile; class Game;

class Coordinates {
private:
    double c_x;
    double c_y;
    int* g_map;

public:
    Coordinates(double x, double y, int* map);
    double getX() { return c_x; };
    double getY() { return c_y; };
    void setX(double x);
    void setY(double y);
    bool contact(Coordinates* c, double hitBox);
    void move(int direction, int id);
};

#endif
