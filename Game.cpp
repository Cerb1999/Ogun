#include "Game.h";


Game::Game() {
	floor = Level(1);
	Coordinates::setMap(level.getMap());
	player = Hero(floor.heroPosition());
	monsters = floor.getMonsters();
	boss = Boss(1, floor.bossPosition());
}

void Game::play() {
	while(player.alive()) {
		for (Monster m : monsters) {
			if (m.act()) {
				if (m.attaquer(player)) {
						projectiles.push_back(new Projectile(false, m.focus(), m.projectileSize(), m.damages(), m.position()));				
				}
			}		
		}
	}
}
