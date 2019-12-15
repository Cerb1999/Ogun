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
    int m_speed;
    int m_actions;
    int m_size;
    int p_size;
    bool m_ranged;
    int m_focus;
    int m_id;
    Coordinates m_position;

public:
    Monster(int l, int x, int y, int* map);
    int hpLeft() { return m_hp; }
    bool alive() { return m_hp > 0; }
    bool isRanged() { return m_ranged; }
    bool hit(Projectile p); // contact avec p, renvoie le bool correspondant et effectue les actions nescessaires
    bool act();
    bool attaquer(Hero* h);
    void move();
    int damages() { return m_damages; }
    int focus() { return m_focus; }
    int monsterSize() { return m_size; }
    int projectileSize() { return p_size; }
    void refreshFocus(Hero* h);
    Coordinates* getCoordinates() { return &m_position; }
};

class Boss: public Monster {
private:

public:
    Boss(int l, int x, int y, int* map);
};

#endif
