#include "Game.h";


Game::Game(int startLevel): 
	floor(Level(startLevel)), player(Hero(floor.heroPosition()))
{
	delete(&exit);
	exit = floor.exitPosition();
	floor.loadStage();
	monsters = floor.getMonsters();
	monsters.push_back(Boss(startLevel, floor.bossPosition()));
}

bool Game::play(int moveDirection, int fireDirection) {
	if (floor.isCleared() && player.position()->contact(exit,0.) ) {
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
	if(player.alive()) {
		player.move(moveDirection);
		if (fireDirection > 0 && fireDirection < 9) {
			projectiles.push_back(*player.fire(fireDirection));
		}
		std::vector<Monster>::iterator ti = monsters.begin();
		while (ti != monsters.end()) {
			if (!ti->alive()) {
				ti = monsters.erase(ti);
			}
			if (ti->act()) {
				if (ti->attaquer(player)) {
					projectiles.push_back(Projectile(false, ti->focus(), ti->projectileSize(), ti->damages(), ti->position()));
				}
			}
			ti++;
		}
		std::vector<Projectile>::iterator it = projectiles.begin();
		while (it != projectiles.end()) {
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
			}
		}
	}
}
