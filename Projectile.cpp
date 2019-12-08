#include "Projectile.h";

Projectile::Projectile(Hero h, int d) {
	p_position = h.position();
	p_damages = h.damages();
	p_players = true;
	p_direction = d;
	p_hitBox = 1;
}

Projectile::Projectile(Monster m, int d) {
	p_position = m.position();
	p_damages = 1;
	p_players = false;
	p_direction = d;
	p_hitBox = 1;
}

Projectile::Projectile(Boss b, int d) {
	p_position = b.position();
	p_damages = 2;
	p_players = false;
	p_direction = d;
	p_hitBox = 1;
}

Projectile::Projectile(Monster m, int d, double size) {
	p_position = m.position();
	p_damages = 1;
	p_players = false;
	p_direction = d;
	p_hitBox = size;
}

Projectile::Projectile(Boss b, int d, double size) {
	p_position = b.position();
	p_damages = 2;
	p_players = false;
	p_direction = d;
	p_hitBox = size;
}

void Projectile::move() {
	double x = 0; double y = 0;
	switch (p_direction) {
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
	p_position->move(x,y);
}