#include "Drop.h";

Drop::Drop(Coordinates* c, bool potion) {
	d_coord = c;
	d_potion = potion;
}

bool Drop::pickedUp(Hero* h) {
	bool res = false;
	if ( d_coord->contact(h->getCoordinates(), 0.)) {
		res = true;
	}
    return res;
}
