#ifndef OGUN_JEU_H
#define OGUN_JEU_H

#include <SDL2/SDL.h>
#include "Game.h";

int loadProjectilesMonstersDestrutiblesCoins(Game* jeu, int textures[], SDL_Renderer* ecran, SDL_Texture* textureTileSetV4, SDL_Texture* coin, SDL_Texture* heart, SDL_Texture* half);
int load(Game* jeu, int textures[], SDL_Renderer* ecran, SDL_Texture* textureTileSetV4, SDL_Texture* textureTileSetWallsV2, SDL_Texture* key);

#endif
