#include "Coordinates.h";
#include "Projectile.h";

class Monster {
public:
    Monster(int l, Coordinates c);
    int hpLeft() { return m_hp; }
    bool isRanged() { return m_ranged; }
    bool hit(Projectile p); // contact avec p, renvoie le bool correspondant et effectue les actions nescessaires
    void attaquer(Hero h);


private:
    int m_hp;
    int m_level;
    int m_speed;
    bool m_ranged;
    Coordinates m_position;
};
