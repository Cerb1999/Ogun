#include "Room.h";
#include <cstdlib>;

Room::Room(int t, int index, int depth) {
        r_layout = Layout(depth, t);
        r_id = index;
        r_cleared = false;
        r_occupied = false;
        r_type = t;
}

Room* Room::rooms(int nbRooms, int depth) {
    Room* prev; Room* actual; int type; bool rewarded = false; Room* first;
    for (int i = 0; i < nbRooms; i++ ) {
        if (i == nbRooms-1) {
            type = 2;
        } else if ( !rewarded ) {
            type = rand()%2;
            rewarded = (type == 1); 
        } else {
            type = 0;
        }
        if ( i > 0) {
            prev = actual;
        } 
        actual = &Room(type, i, depth);
        if (i > 0) {
            prev->setNext(actual);
            actual->setPrevious(prev);
        } else {
            first = actual;
        }
    }
    return first;
}

void Room::clear() {
    r_cleared = true;
}

void Room::enter() {
    r_occupied = true;
}

void Room::setNext(Room* r) {
    r_next = r;
}

void Room::setPrevious(Room* r) {
    r_previous = r;
}