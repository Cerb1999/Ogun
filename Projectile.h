#include "Coordinates.h";
//#include "Monster.h";

class Projectile {
public:
    Projectile(Hero h, int d);
    Projectile(Monster h);
    Coordinates getCoordinates() { return p_position; }

private:
    Coordinates p_position;
    int p_damages;
    bool p_players; //evitons le suicide et de pouvoir nous faire mal avec nos propres projectiles
    int p_direction; //le tir se déplace vers un point cardinal
};
