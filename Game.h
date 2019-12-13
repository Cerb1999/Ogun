#ifndef Game_H
#define Game_H

#include <vector>;
#include "Hero.h";
#include "Monster.h";
#include "Destructible.h";
#include "Projectile.h"
#include "Level.h";

class Game{
private:
	Hero player;
	Level floor;
	Coordinates* exit;
	std::vector<Monster> monsters;
	std::vector<Projectile> projectiles;
	//std::vector<Destructible> destructibles;

public:
	Game(int startLevel);
	bool play(int movementDirection, int fireDirection);
	int depth() { return floor.getDepth(); }	
	std::vector<Monster> getMonsters() { return monsters; }
	std::vector<Projectile> getProjectiles() { return projectiles; }
};

#endif
