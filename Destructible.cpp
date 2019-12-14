#include "Destructible.h";

Destructible::Destructible(Coordinates c) {
	d_coord = &c;
}

bool Destructible::hit(Projectile p) {
	bool res = false;
	if ( d_coord->contact(p.getCoordinates(), 1.)) {
		res = true;
	}
	return res;
}
