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

}