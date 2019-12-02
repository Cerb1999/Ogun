#include "Level.h";
#include "Room.h";

Level::Level(int nbRooms, int d) {
    l_nbRooms = nbRooms;
    l_depth = d;
    l_rooms = Room::rooms(nbRooms, d);
}