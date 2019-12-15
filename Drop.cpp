#include "Drop.h";

Drop::Drop(double x, double y, int* map, bool potion):
	d_coord(Coordinates(x,y,map))
{
	d_potion = potion;
}

bool Drop::pickedUp(Hero* h) {
	bool res = false;
	if ( d_coord.contact(h->getCoordinates(), 0.)) {
		res = true;
	}
    return res;
}
