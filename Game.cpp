#include "Game.h";


Game::Game(int startLevel): 
	floor(Level(startLevel)), boss(Boss(startLevel, floor.bossPosition())),  player(Hero(floor.heroPosition()))
{
	monsters = floor.getMonsters();
}

void Game::play(int direction) {
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
		for (Projectile p : projectiles) {	
			p.move();
      if (!p.playerProjectile()) {
				player.hit(p);
			}	else {
				for (Monster m : monsters) {
					m.hit(p);
				}
			}	
		}
	}
}
