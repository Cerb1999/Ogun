#ifndef Level_H
#define Level_H

#include <vector>;
#include "Monster.h";
#include "Destructible.h";

class Level {
private:
  int l_depth;
  std::vector<Monster> l_monsters;
  std::vector<Destructible> l_crates;
  bool l_cleared;
  int** l_map;

public:
  Level(int d);
  bool isCleared();
  int getDepth() { return l_depth; };
  std::vector<Monster> getMonsters(){ return l_monsters; };
  std::vector<Destructible> getDestructibles(){ return l_crates; };
  Coordinates* heroPosition();
  Coordinates* bossPosition();
  void loadStage();
};

#endif
