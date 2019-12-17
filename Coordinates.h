#ifndef Coordinates_H
#define Coordinates_H

class Boss; class Hero; class Destructible; class Projectile; class Game;

class Coordinates {
private:
    short c_x;
    short c_y;
    short* g_map;

public:
    Coordinates(short x, short y, short* map);
    short getX() { return c_x; };
    short getY() { return c_y; };
    short* getMap() { return g_map; };
    void setX(short x);
    void setY(short y);
    bool contact(Coordinates* c, short hitBox);
    bool move(short direction, short id);
    bool murred(short d);
};

#endif
