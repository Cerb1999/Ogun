typedef struct room {
  int layout[][];
  bool cleared;
  bool occupied;
  int type
} room;

room cons(int[][] lay, int t) {
  //room r = malloc;
  r.layout = lay;
  r.cleared = false;
  r.occupied = false;
  r.type = t;
  return r;
}

int layout(room r) {
  switch (r.type) {
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

void clear(room r) {
  r.cleared = true;
}

void enter(room r) {
  r.occupied = true;
}
