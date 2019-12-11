#ifndef Level_H
#define Level_H

#include "Monster.h";
#include "Destructible.h";

class Level{
private:
  int l_depth;
  Monster* l_monsters;
  Destructible* l_crates;
  bool l_cleared;
  int** l_map;

public:
  Level(int d);
  bool isCleared() { return l_cleared; };
  int getDepth() { return l_depth; };
  int** getMap() { return l_map; };
  Monster* getMonsters(){ return l_monsters; };
  Destructible* getDestructibles(){ return l_crates; };
  void loadStage();
};

#endif
