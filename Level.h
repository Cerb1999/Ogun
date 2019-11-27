#include "room.h"

typedef struct level {
  int nb_rooms;
  int depth;
  room rooms[];
};
