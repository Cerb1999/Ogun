#include "Game.h";
#include <stdio.h>
#include <iostream>
#include <windows.h>

using namespace std; 

Game::Game(int startLevel): 
	floor(Level(startLevel))
{
	floor.loadStage();
	Hero h = Hero(floor.heroPosition());
	player = &h;
	exit = floor.exitPosition();
	monsters = floor.getMonsters();
	monsters.push_back(Boss(startLevel, floor.bossPosition()));
}

bool Game::play(int moveDirection, int fireDirection) {
	cout << "play";
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
		std::vector<Coin>::iterator fi = coins.begin();
		while (fi != coins.end() ) {
			if (fi->pickedUp(player)) {
				fi = coins.erase(fi);
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
	}
}
