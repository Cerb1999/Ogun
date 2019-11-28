#include "Coordinates.h";
//#include "Monster.h";

class Projectile {
public:
    //Projectile(Hero h, int d);
    Projectile(Monster h);

private:
    Coordinates position;
    int damages;
    bool players; //evitons le suicide et de pouvoir nous faire mal avec nos propres projectiles
    int direction; //le tir se déplace vers un point cardinal
};