#include "Destructible.h";

Destructible::Destructible(double x, double y, int* map) : d_coord(Coordinates(x,y,map)) {}

bool Destructible::hit(Projectile p) {
	bool res = false;
	if ( d_coord.contact(p.getCoordinates(), 1.)) {
		res = true;
	}
	return res;
}
