#include "Game.h";


Game::Game(int startLevel): 
	floor(Level(startLevel)), boss(Boss(startLevel, floor.bossPosition())),  player(Hero(floor.heroPosition()))
{
	monsters = floor.getMonsters();
}

bool Game::play(int direction) {
	if(player.alive()) {
		player.move(direction); 
		for (Monster m : monsters) {
			if (m.act()) {
				if (m.attaquer(player)) {
					projectiles.push_back(Projectile(false, m.focus(), m.projectileSize(), m.damages(), m.position()));				
				}
			}		
		}
		if (boss.act()) {
			if (boss.attaquer(player)) {
				projectiles.push_back(Projectile(false, boss.focus(), boss.projectileSize(), boss.damages(), boss.position()));				
			}
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
				/*for (Destructible d : destructibles) {
					if (d.hit(it)) {
						it = projectiles.erase(it);
					} else {
						it++;
					}
				}*/
			}
		}
	}
}
