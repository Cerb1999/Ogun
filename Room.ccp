#include "Layout.h";

class Room {
public:
    Room(int t, int index, int depth) {
        r_layout = Layout(depth, index);
        r_cleared = false;
        r_occupied = false;
        r_type = t;
    }
    int layout() {
        switch (r_type) {
            case 0: // standart room
            //spawn des mobs et du terrain en fonction du layout
            break;
            case 1: // item room
            //piedestal avec objet au centre de la piece, possibilité de faire spawn des mobs
            break;
            case 2: // shop
            //piedestaux avec hp, key et un objet ainsi que le prix de chacun, possibilité de faire spawn des mobs
            break;
            case 3: // boss room
            //mob avec un indice particulier, les mobs spawn durant le combat
            break;
        }
    }

    void clear() {
        r_cleared = true;
    }

    void enter() {
        r_occupied = true;
    }

    bool isClear() {
        return r_cleared;
    }

    bool isOccupied() {
        return r_occupied;
    }

    int index() {
        return r_index;
    }

private:
    Layout r_layout; //tableau 2D
    bool r_cleared;
    bool r_occupied;
    int r_type;
    int r_index;
};
