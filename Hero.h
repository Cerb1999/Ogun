#include "Coordinates.h";
#include "Projectile.h";

class Hero {
public:
    Hero();
    int hpLeft();
    int damages();
    bool hit(Projectile p); // contact avec p, renvoie le bool correspondant et effectue les actions nescessaires
    bool hit(Monster m);
    void move();
    Coordinates position();

private:
    int hp;
    int speed;
    int damages;
    Coordinates position;
};
