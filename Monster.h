#ifndef Monster_H
#define Monster_H

#include "Coordinates.h";
#include "Projectile.h";

class Projectile; class Hero; class Game;

class Monster {
protected:
    short m_hp;
    short m_level;
    short m_damages;
    short m_speed;
    short m_actions;
    short m_size;
    short p_size;
    bool m_ranged;
    short m_focus;
    short m_id;
    Coordinates m_position;

public:
    Monster(short l, short x, short y, short* map);
    short hpLeft() { return m_hp; }
    bool alive() { return m_hp > 0; }
    bool isRanged() { return m_ranged; }
    bool hit(Projectile p); // contact avec p, renvoie le bool correspondant et effectue les actions nescessaires
    bool act();
    bool attaquer(Hero* h);
    void move();
    short damages() { return m_damages; }
    short focus() { return m_focus; }
    short monsterSize() { return m_size; }
    short projectileSize() { return p_size; }
    void refreshFocus(Hero* h);
    Coordinates* getCoordinates() { return &m_position; }
};

class Boss: public Monster {
private:

public:
    Boss(short l, short x, short y, short* map);
};

#endif
