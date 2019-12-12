#include "Game.h";


Game::Game(int startLevel): 
	floor(Level(startLevel)), boss(Boss(startLevel, floor.bossPosition())),  player(Hero(floor.heroPosition()))
{
	Coordinates::setMap(floor.getMap());
	monsters = floor.getMonsters();
}

void Game::play() {
	while(player.alive()) {
		for (Monster m : monsters) {
			if (m.act()) {
				if (m.attaquer(player)) {
						projectiles.push_back(Projectile(false, m.focus(), m.projectileSize(), m.damages(), m.position()));				
				}
			}		
		}
	}
}
