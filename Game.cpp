#include "Game.h";
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std; 

Game::Game(int startLevel): 
	floor(Level(startLevel)), player(Hero(floor.HeroX(), floor.HeroY(), floor.getMap())), boss(Boss(startLevel, floor.BossX(), floor.BossY(), floor.getMap())), exit(Coordinates(floor.ExitX(), floor.ExitY(), floor.getMap()))
{
	score = 0;
	monsters = floor.getMonsters();
	monsters.push_back(boss);
	destructibles = floor.getDestructibles();
	drops = floor.getDrops();
}

bool Game::play(int moveDirection, int fireDirection) {
	cout << "play\n";
	bool res = true;
	if (floor.isCleared() && player.getCoordinates()->contact(&exit,0.) ) {
		if ( floor.getDepth() == 5) {
			res = false;
		} else {
			cout << "player at exit\n";
			int tmp = floor.getDepth()+1;
			delete(&floor);
			floor = Level(tmp);
			floor.loadStage();
			delete(&player);
			delete(&exit);
			exit = Coordinates(floor.ExitX(), floor.ExitY(), floor.getMap());
			monsters.clear();
			monsters = floor.getMonsters();
			boss = Boss(tmp, floor.BossX(), floor.BossY(), floor.getMap());
			monsters.push_back(boss);
			projectiles.clear();
		}
	}
	if(player.alive()) {
		cout << "player alive\n";
		if (moveDirection > 0 && moveDirection < 9) {
			player.move(moveDirection);
		}
		if (fireDirection > 0 && fireDirection < 9) {
			player.fire(fireDirection);
			int x = player.getCoordinates()->getX(); int y = player.getCoordinates()->getY();
			projectiles.push_back(Projectile(true,player.focus(),1.,player.damages(),x,y, floor.getMap()));
		}
		cout << "player moved or fired\n";
		std::vector<Drop>::iterator fi = drops.begin();
		while (fi != drops.end() ) {
			if (fi->pickedUp(&player)) {
				fi = drops.erase(fi);
				if (fi->isAPotion()) {
					player.heal();
				} else {
					score++;
				}
			} else {	
				fi++;
			}
		}
		std::vector<Monster>::iterator ti = monsters.begin();
		cout << "x = " << ti->getCoordinates()->getX() << " y = " << ti->getCoordinates()->getY() << "\n";
		while (ti != monsters.end()) {
			if (!ti->alive()) {
				ti = monsters.erase(ti);
			}
			if (ti->act()) {
				if (ti->attaquer(&player)) {
					projectiles.push_back(Projectile(false, ti->focus(), ti->projectileSize(), ti->damages(), ti->getCoordinates()->getX(), ti->getCoordinates()->getY(), floor.getMap()));
				}
			}
			ti++;
		}
		cout << "after monster\n";
		std::vector<Projectile>::iterator it = projectiles.begin();
		while (it != projectiles.end()) {
			if (it->murred()) {
				it = projectiles.erase(it);
			} else {
				it->move();
				if (!it->playerProjectile()) {
					if (player.hit(*it)) {
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
							drops.push_back(Drop(ti->getCoordinates()->getX(), ti->getCoordinates()->getY(), floor.getMap(), res));
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
