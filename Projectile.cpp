#include "Projectile.h";

Projectile::Projectile(bool players, int direction, double size, int damages, Coordinates* position) {
	p_position = position;
	p_damages = damages;
	p_players = players;
	p_direction = direction;
	p_hitbox = size;
	move();
}

void Projectile::move() {
	p_position->move(p_direction);
}
