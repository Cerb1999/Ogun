#ifndef Game_H
#define Game_H

#include <vector>
#include "Hero.h";
#include "Monster.h";
#include "Destructible.h";
#include "Projectile.h";
#include "Level.h";
#include "Coin.h";

class Game{
private:
	Level floor;
	Hero* player;
	Coordinates* exit;
	std::vector<Monster> monsters;
	std::vector<Projectile> projectiles;
	std::vector<Destructible> destructibles;
	std::vector<Coin> coins;

public:
	Game(int startLevel);
	bool play(int movementDirection, int fireDirection);
	int depth() { return floor.getDepth(); }
	Level level() { return floor; };
	std::vector<Monster> getMonsters() { return monsters; }
	std::vector<Projectile> getProjectiles() { return projectiles; }
	std::vector<Destructible> getDestructibles() { return destructibles; }
	std::vector<Coin> getCoins() { return coins; }
	Hero* getPlayer() { return player; }
};

#endif
