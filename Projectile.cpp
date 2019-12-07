#include "Projectile.h";

Projectile::Projectile(Hero h, int d) {
	p_position = h.position();
	p_damages = h.damages();
	p_players = true;
	p_direction = d;
}

Projectile::Projectile(Monster m, int d) {
	p_position = m.position();
	p_damages = 1;
	p_players = false;
	p_direction = d;
}

Projectile::Projectile(Boss b, int d) {
	p_position = b.position();
	p_damages = 2;
	p_players = false;
	p_direction = d;
}

void Projectile::move() {
	double x = 0; double y = 0;
	switch (p_direction) {
		case 1:
			x = 1;
			break;
		case 2: 
			x = 1;
			y = 1;
			break;
		case 3:
			y = 1;
			break;
		case 4:
			x = -1;
			y = 1;
			break;
		case 5: 
			x = -1;
			break;
		case 6:
			x = -1;
			y = -1;
			break;
		case 7:
			y = -1;
			break;
		case 8:
			x = 1;
			y = -1;
			break;
	}
	p_position->move(x,y);
}