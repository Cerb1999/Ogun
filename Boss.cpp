#include "Boss.h"

Boss::Boss(int l, Coordinates* c) : Monster(l,c) {
	m_level = l;
    m_damages = 2.;
	m_ranged = l == 3 || l == 4;
	m_speed = 1 + (l != 1 || l != 4)*0.25;
	m_position = c;
}