#ifndef Boss_H
#define Boss_H

class Boss {
private:
    int m_hp;
    int m_level;
    int m_speed;
    bool m_ranged;
    Coordinates m_position;

public:
    Boss(int l, Coordinates c);
    int hpLeft() { return m_hp; }
    bool isRanged() { return m_ranged; }
    bool hit(Projectile p); // contact avec p, renvoie le bool correspondant et effectue les actions nescessaires
    void attaquer(Hero h);
    Coordinates* position() { return &m_position; }
};

#endif