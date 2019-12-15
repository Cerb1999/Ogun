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
  double h_x;
  double h_y;
  double b_x;
  double b_y;
  double e_x;
  double e_y;

public:
  Level(int d);
  bool isCleared() { l_cleared = l_monsters.size() == 0;return l_cleared; };
  int getDepth() { return l_depth; };
  int* getMap() { return l_map; };
  std::vector<Monster> getMonsters() { return l_monsters; };
  std::vector<Destructible> getDestructibles() { return l_crates; };
  std::vector<Drop> getDrops() { return l_drop; };
  void SetHero();
  double HeroX() { return h_x; }
  double HeroY() { return h_y; }
  double BossX() { return b_x; }
  double BossY() { return b_y; }
  double ExitX() { return e_x; }
  double ExitY() { return e_y; }
  void loadStage();
};

#endif
