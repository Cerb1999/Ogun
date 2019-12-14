#include "Monster.h";

Monster::Monster(int l, Coordinates* c) {
	m_level = l;
	m_level = 2 + l;
	m_damages = 1;
	m_size = 1.;
	p_size = 1 + l == 5;
	m_ranged = l == 3 || l == 5;
	m_speed = 1 + (l != 1 || l != 4)*0.5;
	m_actions = m_speed;
	m_position = c;
	m_id = 3;
}

bool Monster::hit(Projectile p) {
	return m_position->contact(p.getCoordinates(), p.hitBox()+monsterSize());
}

bool Monster::act() {
	bool res = false;
	m_actions += m_speed;
	if (m_actions >= 2.5) { 
		m_actions -= 2.5;
		res = true;
	}
	return res;
}

bool Monster::attaquer(Hero* h) {
	bool res = false;
	if (m_ranged) {
		refreshFocus(h);
		res = true;
	} else {
		if (m_position->contact(h->position(), monsterSize())) {
			h->die(m_damages);
		} else {
			refreshFocus(h);
			move();
		}
	}
	return res;
}

void Monster::move() {
	m_position->move(m_focus, m_id);
}

void Monster::refreshFocus(Hero* h) {
	if ( m_position->getX() == h->position()->getX() ) {
			if ( m_position->getY() > h->position()->getY() ) {
				m_focus = 5;
			} else {
				m_focus = 1;
			}
		} else if ( m_position->getX() > h->position()->getX() ) {
			if ( m_position->getY() == h->position()->getY() ) {
				m_focus = 7;
			} else if ( m_position->getY() > h->position()->getY() ) {
				m_focus = 6;
			} else {
				m_focus = 8;
			}
		} else {
			if ( m_position->getY() == h->position()->getY() ) {
				m_focus = 3;
			} else if ( m_position->getY() > h->position()->getY() ) {
				m_focus = 4;
			} else {
				m_focus = 2;
			}
		}
}

Boss::Boss(int l, Coordinates* c) : Monster(l,c) {
	m_level = l;
	m_hp = 10 + 2*l;
	m_damages = 2.;
	m_ranged = l == 3 || l == 4;
	m_size = 2;
	p_size = 1 + l == 5;
	m_speed = 1 + (l != 1 || l != 4)*0.5;
	m_position = c;
	m_id = 4;
}
