#ifndef OGUN_JEU_H
#define OGUN_JEU_H

#include <SDL2/SDL.h>
#include "Game.h";

//int loadMap(int depth, int* map, int textures[], SDL_Renderer* ecran, SDL_Window* fenetre);
int loadProjectilesMonstersDestrutiblesCoins(Game* jeu, int textures[], SDL_Renderer* ecran);
int load(Game* jeu, int textures[], SDL_Renderer* ecran);

#endif
