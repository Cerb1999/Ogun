#include "Game.h";


Game::Game(int startLevel): 
	floor(Level(startLevel)), player(Hero(floor.heroPosition()))
{
	floor.loadStage();
	monsters.push_back(Boss(startLevel, floor.bossPosition()));
	monsters = floor.getMonsters();
}

bool Game::play(int moveDirection, int fireDirection) {
	if(player.alive()) {
		player.move(moveDirection);
		if (fireDirection > 0 && fireDirection < 9) {
			projectiles.push_back(*player.fire(fireDirection));
		} 
		for (Monster m : monsters) {
			if (m.act()) {
				if (m.attaquer(player)) {
					projectiles.push_back(Projectile(false, m.focus(), m.projectileSize(), m.damages(), m.position()));				
				}
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
