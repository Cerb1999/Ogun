#ifndef Level_H
#define Level_H

#include <vector>;
#include "Monster.h";
#include "Destructible.h";
#include "Drop.h";

class Level {
private:
  int l_depth;
  std::vector<Monster> l_monsters;
  std::vector<Destructible> l_crates;
  std::vector<Drop> l_drop;
  bool l_cleared;
  int* l_map;


public:
  Level(int d);
  bool isCleared() { l_cleared = l_monsters.size() == 0;return l_cleared; };
  int getDepth() { return l_depth; };
  int* getMap() { return l_map; };
  std::vector<Monster> getMonsters() { return l_monsters; };
  std::vector<Destructible> getDestructibles() { return l_crates; };
  std::vector<Drop> getDrops() { return l_drop; };
  Coordinates* heroPosition();
  Coordinates* bossPosition();
  Coordinates* exitPosition();
  void loadStage();
};

#endif
