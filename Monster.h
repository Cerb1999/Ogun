#include "Coordinates.h";
#include "Projectile.h";

class Monster {
public:
    Monster(int l);
    int hpLeft();
    bool isRanged();
    bool hit(Projectile p); // contact avec p, renvoie le bool correspondant et effectue les actions nescessaires
    void move();


private:
    int hp;
    int level;
    int speed;
    bool ranged;
    Coordinates position;
};