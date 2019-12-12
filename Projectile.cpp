#include "Projectile.h";

Projectile::Projectile(bool players, int direction, double size, int damages, Coordinates* position) {
	p_position = position;
	p_damages = damages;
	p_players = players;
	p_direction = direction;
	p_hitBox = size;
	move();
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
