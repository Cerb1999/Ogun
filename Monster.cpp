#include "Monster.h";

Monster::Monster(int l, Coordinates c) {
	m_level = l;
	m_ranged = l == 3 || l == 4;
	m_speed = 1 + (l != 1 || l != 4)*0.25;
	m_position = c;
}

Monster::hit(Projectile p) {

}

Monster::attaquer(Hero h) {
	
}
