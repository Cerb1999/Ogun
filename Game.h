#ifndef Game_H
#define Game_H

#include <vector>
#include "Hero.h"
#include "Monster.h"
#include "Destructible.h"
#include "Projectile.h"
#include "Level.h"
#include "Drop.h"

class Game{
private:
	Level floor;
	Hero player;
	Boss boss;
	Coordinates exit;
	std::vector<Monster> monsters;
	std::vector<Projectile> projectiles;
	std::vector<Destructible> destructibles;
	std::vector<Drop> drops;
	short score;

public:
	Game(short startLevel);
	bool play(short movementDirection, short fireDirection);
	short depth() { return floor.getDepth(); }
	Level level() { return floor; };
	std::vector<Monster> getMonsters() { return monsters; }
	std::vector<Projectile> getProjectiles() { return projectiles; }
	std::vector<Destructible> getDestructibles() { return destructibles; }
	std::vector<Drop> getDrops() { return drops; }
	Hero* getPlayer() { return &player; }
	short getScore() { return score; }
};

#endif
