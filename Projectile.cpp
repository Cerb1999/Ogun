#include "Projectile.h";

Projectile::Projectile(bool players, int direction, double size, int damages, double x, double y, int* map) :
	p_position(Coordinates(x,y,map))
{
	p_damages = damages;
	p_players = players;
	p_direction = direction;
	p_hitbox = size;
	move();
}

void Projectile::move() {
	p_position.move(p_direction, 0);
}
