#ifndef Monster_H
#define Monster_H

#include "Coordinates.h";
#include "Projectile.h";

class Projectile; class Hero; class Game;

class Monster {
protected:
    int m_hp;
    int m_level;
    int m_damages;
    double m_speed;
    double m_actions;
    double m_size;
    double p_size;
    bool m_ranged;
    int m_focus;
    int m_id;
    Coordinates* m_position;

public:
    Monster(int l, Coordinates* c);
    int hpLeft() { return m_hp; }
    bool isRanged() { return m_ranged; }
    bool hit(Projectile p); // contact avec p, renvoie le bool correspondant et effectue les actions nescessaires
    bool act();
    bool attaquer(Hero h);
    void move();
    int damages() { return m_damages; }
    int focus() { return m_focus; }
    double projectileSize() { return p_size; }
    void refreshFocus(Hero h);
    Coordinates* position() { return m_position; }
};

class Boss: public Monster {
private:

public:
    Boss(int l, Coordinates* c);
};

#endif
