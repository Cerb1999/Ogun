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
				m.attaquer(
			}		
		}
	}
}
