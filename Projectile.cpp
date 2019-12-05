#include "Projectile.h";

Projectile::Projectile(Hero h, int d) {
	p_position = h.position();
	p_damages = h.damages();
	p_players = true;
	p_direction = d;
}
