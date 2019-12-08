#include "Monster.h";

Monster::Monster(int l, Coordinates* c) {
	m_level = l;
	m_damages = 1;
	m_size = 1.;
	m_ranged = l == 3 || l == 4;
	m_speed = 1 + (l != 1 || l != 4)*0.25;
	m_position = c;
}

bool Monster::hit(Projectile p) {
	return m_position->contact(p.getCoordinates());
}

bool Monster::attaquer(Hero h) {
	bool res = false;
	if (m_ranged) {
		refreshFocus(h);
		res = true;
	} else {
		if (m_position->contact(h.position, m_size)) {
			h.die(m_damages);
		} else {
			refreshFocus(h);
			move(h);
		}
	}
	return res;
}

void Monster::move(Hero h) {
	double x = 0; double y = 0;
	switch (m_focus) {
		case 1:
			y = 1;
			break;
		case 2: 
			x = 1;
			y = 1;
			break;
		case 3:
			x = 1;
			break;
		case 4:
			x = 1;
			y = -1;
			break;
		case 5: 
			y = -1;
			break;
		case 6:
			x = -1;
			y = -1;
			break;
		case 7:
			x = -1;
			break;
		case 8:
			x = -1;
			y = 1;
			break;
	}
	m_position->move(x,y);
}

void Monster::refreshFocus(Hero h) {
	if ( m_position->getX() == h.position()->getX() ) {
			if ( m_position->getY() > h.position()->getY() ) {
				m_focus = 5;
			} else {
				m_focus = 1;
			}
		} else if ( m_position->getX() > h.position()->getX() ) {
			if ( m_position->getY() == h.position()->getY() ) {
				m_focus = 7;
			} else if ( m_position->getY() > h.position()->getY() ) {
				m_focus = 6;
			} else {
				m_focus = 8;
			}
		} else {
			if ( m_position->getY() == h.position()->getY() ) {
				m_focus = 3;
			} else if ( m_position->getY() > h.position()->getY() ) {
				m_focus = 4;
			} else {
				m_focus = 2;
			}
		}
}