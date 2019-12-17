#ifndef Coordinates_H
#define Coordinates_H

class Boss; class Hero; class Destructible; class Projectile; class Game;

class Coordinates {
private:
    int c_x;
    int c_y;
    int* g_map;

public:
    Coordinates(int x, int y, int* map);
    int* getMap() { return g_map; };
    int getX() { return c_x; };
    int getY() { ;return c_y; };
    void setX(int x);
    void setY(int y);
    bool contact(Coordinates* c, int hitBox);
    bool move(int direction, int id);
    bool murred(int d);
};

#endif
