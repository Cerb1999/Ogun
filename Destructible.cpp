#include "Destructible.h";

Destructible::Destructible(short x, short y, short* map) : d_coord(Coordinates(x,y,map)) {}

bool Destructible::hit(Projectile p) {
	bool res = false;
	if ( d_coord.contact(p.getCoordinates(), 1.)) {
		res = true;
	}
	return res;
}
