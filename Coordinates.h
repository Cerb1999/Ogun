#ifndef Coordinates_H
#define Coordinates_H

class Boss; class Hero; class Destructible; class Projectile; class Game;

class Coordinates {
private:
    double c_x;
    double c_y;
    static int** g_map;

public:
    Coordinates(double x, double y);
    static void setMap(int** env) { g_map = env; };
    static int** getMap() { return g_map; };
    double getX() { return c_x; };
    double getY() { return c_y; };
    void setX(double x);
    void setY(double y);
    void move(double x, double y);
    bool contact(Coordinates* c, double hitBox);
};

#endif
