#include "Coin.h";

Coin::Coin(Coordinates c) {
	c_coord = &c;
}

bool Coin::pickedUp(Hero* h) {
	bool res = false;
	if ( c_coord->contact(h->getCoordinates(), 0.)) {
		res = true;
	}
    return res;
}
