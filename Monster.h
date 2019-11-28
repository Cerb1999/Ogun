#include "Coordinates.h";
#include "Projectile.h";

class Monster {
public:
    Monster(int l);
    int hpLeft();
    bool isRanged();
    bool hit(Projectile p); // contact entre m et p, renvoie le bool corespondant et effectue les actions nescessaires sur m et p  

private:
    int hp;
    int level;
    bool ranged;
    Coordinates position;
};