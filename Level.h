#ifndef Level_H
#define Level_H

#include <vector>;
#include "Monster.h";
#include "Destructible.h";
#include "Drop.h";

class Level {
private:
  short l_depth;
  std::vector<Monster> l_monsters;
  std::vector<Destructible> l_crates;
  std::vector<Drop> l_drop;
  bool l_cleared;
  short* l_map;
  short h_x;
  short h_y;
  short b_x;
  short b_y;
  short e_x;
  short e_y;

public:
  Level(short d);
  bool isCleared() { l_cleared = l_monsters.size() == 0;return l_cleared; };
  short getDepth() { return l_depth; };
  short* getMap() { return l_map; };
  std::vector<Monster> getMonsters() { return l_monsters; };
  std::vector<Destructible> getDestructibles() { return l_crates; };
  std::vector<Drop> getDrops() { return l_drop; };
  void SetHero();
  short HeroX() { return h_x; }
  short HeroY() { return h_y; }
  short BossX() { return b_x; }
  short BossY() { return b_y; }
  short ExitX() { return e_x; }
  short ExitY() { return e_y; }
  void loadStage();
};

#endif
