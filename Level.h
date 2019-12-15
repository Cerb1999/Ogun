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
  int h_x;
  int h_y;
  int b_x;
  int b_y;
  int e_x;
  int e_y;

public:
  Level(int d);
  bool isCleared() { l_cleared = l_monsters.size() == 0;return l_cleared; };
  int getDepth() { return l_depth; };
  int* getMap() { return l_map; };
  std::vector<Monster> getMonsters() { return l_monsters; };
  std::vector<Destructible> getDestructibles() { return l_crates; };
  std::vector<Drop> getDrops() { return l_drop; };
  void SetHero();
  int HeroX() { return h_x; }
  int HeroY() { return h_y; }
  int BossX() { return b_x; }
  int BossY() { return b_y; }
  int ExitX() { return e_x; }
  int ExitY() { return e_y; }
  void loadStage();
};

#endif
