#ifndef Monster_H
#define Monster_H

#include "Coordinates.h";
#include "Projectile.h";

class Monster {
protected:
    int m_hp;
    int m_level;
    int m_damages;
    int m_speed;
    double m_size;
    bool m_ranged;
    int m_focus;
    Coordinates* m_position;

public:
    Monster(int l, Coordinates* c);
    int hpLeft() { return m_hp; }
    bool isRanged() { return m_ranged; }
    bool hit(Projectile p); // contact avec p, renvoie le bool correspondant et effectue les actions nescessaires
    bool attaquer(Hero h);
    void move(Hero h);
    int focus() { return m_focus; }
    void refreshFocus(Hero h);
    Coordinates* position() { return m_position; }
};

#endif