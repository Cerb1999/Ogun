#include "Game.h";
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std; 

Game::Game(int startLevel): 
	floor(Level(startLevel))
{
	score = 0;
	floor.loadStage();
	Hero h = Hero(floor.heroPosition());
	player = &h;
	exit = floor.exitPosition();
	monsters = floor.getMonsters();
	monsters.push_back(Boss(startLevel, floor.bossPosition()));
	drops = floor.getDrops();
}

bool Game::play(int moveDirection, int fireDirection) {
	cout << "play";
	bool res = true;
	if (floor.isCleared() && player->getCoordinates()->contact(exit,0.) ) {
		cout << "player at exit";
		int tmp = floor.getDepth()+1;
		delete(&floor);
		floor = Level(tmp);
		floor.loadStage();
		delete(&player);
		delete(exit);
		exit = floor.exitPosition();
		monsters.clear();
		monsters = floor.getMonsters();
		monsters.push_back(Boss(tmp, floor.bossPosition()));
		projectiles.clear();
	}
	cout << player->getCoordinates()->getX();
	if(player->alive()) {
		cout << "player alive";
		player->move(moveDirection);
		if (fireDirection > 0 && fireDirection < 9) {
			projectiles.push_back(*player->fire(fireDirection));
		}
		std::vector<Drop>::iterator fi = drops.begin();
		while (fi != drops.end() ) {
			if (fi->pickedUp(player)) {
				fi = drops.erase(fi);
				if (fi->isAPotion()) {
					player->heal();
				} else {
					score++;
				}
			} else {	
				fi++;
			}
		}
		std::vector<Monster>::iterator ti = monsters.begin();
		while (ti != monsters.end()) {
			if (!ti->alive()) {
				ti = monsters.erase(ti);
			}
			if (ti->act()) {
				if (ti->attaquer(player)) {
					projectiles.push_back(Projectile(false, ti->focus(), ti->projectileSize(), ti->damages(), ti->getCoordinates()));
				}
			}
			ti++;
		}
		std::vector<Projectile>::iterator it = projectiles.begin();
		while (it != projectiles.end()) {
			if (it->murred()) {
				it = projectiles.erase(it);
			} else {
				it->move();
				if (!it->playerProjectile()) {
					if (player->hit(*it)) {
						it = projectiles.erase(it);
					} else {
						it++;
					}
				} else {
					for (Monster m : monsters) {
						if (m.hit(*it)) {
							it = projectiles.erase(it);
						} else {
							it++;
						}
					}
					std::vector<Destructible>::iterator ti = destructibles.begin();
					while (ti != destructibles.end() ) {
						if (ti->hit(*it)) {
							int random = rand()%2;
							bool res = false;
							if (random == 1) { res = true; }
							drops.push_back(Drop(ti->getCoordinates(), res));
							it = projectiles.erase(it);
							ti = destructibles.erase(ti);
						} else {
							it++;
						}
						ti++;
					}
				}
			}
		}
	} else { res = false;}
	return res;
}
