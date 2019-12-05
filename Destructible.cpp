#include "Destructible.h";

Destructible::Destructible(Coordinates c) {
	d_coord = &c;
}

Destructible::hit(Projectile p) {
	bool res = false;
	if ( d_coord.contact(p.getCoordinates()) ) {
		res = true;
	}
}
