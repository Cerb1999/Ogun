#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include "fonctions_SDL.h"
#include "jeu.h"
#include "Game.h"

using namespace std;

int main(int argc, char *argv[])
{
	int textures[19*8];

	ifstream infile("textures/texture_coordinates.txt");
	
	int i = -1; int j = -1;
	while(infile){
        j = -1;
		string s;
		if(!getline(infile, s)) break;
		i++;
		istringstream ss(s);
		 	
		while(ss){
			j++;
			if(i == 19) i = -1;
			string s;
			if(!getline(ss,s,','))break;
            long val;
            istringstream(s) >> val;
			textures[i*8+j] = val;
		}
	}
	 

    SDL_Window* fenetre;
    SDL_Event evenements;
    SDL_Renderer* ecran;
    bool terminer = false;

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    fenetre = SDL_CreateWindow("Ogun", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL)
    {
        printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture* fondMenu = charger_image("textures/background/ogun-background-menu.bmp", ecran);
    SDL_Texture* fondJeu = charger_image("textures/background/background-menu.bmp", ecran);

    Uint8 r = 255; Uint8 g = 255; Uint8 b = 0;
    SDL_Rect SrcR;
    SrcR.x = 0; SrcR.y = 0; SrcR.w = 1920; SrcR.h = 1080;
    SDL_Rect DestR;
    DestR.x = 0; DestR.y = 0; DestR.w = 1920; DestR.h = 1080;

 

    bool run = false;
    Game* jeu;

    while(!terminer)
    {
        SDL_RenderClear(ecran);
        if (!run) {
            SDL_RenderCopy(ecran, fondMenu, &SrcR, &DestR);
        } else {
            SDL_RenderCopy(ecran, fondJeu, &SrcR, &DestR);
            load(jeu, textures, ecran);
/*
            loadProjectilesMonstersDestrutiblesCoins(jeu, textures, ecran);
*/
        }
        while( SDL_PollEvent( &evenements ) )
			switch(evenements.type)
			{
				case SDL_QUIT:
					terminer = true; break;
				case SDL_KEYDOWN:
					switch(evenements.key.keysym.sym){
				        case SDLK_ESCAPE: {
                            SDL_DestroyRenderer(ecran);
                            SDL_DestroyWindow(fenetre);
                            SDL_Quit();
                            terminer = true;
                            break;
                        }
				        case SDLK_SPACE: {
                            if(run) break;
                            if (run == false) run = true;
                            Game g = Game(1);
                            jeu = &g;
                            //loadMap(jeu->depth(), jeu->level().getMap(), textures, ecran, fenetre);
                            break;
                        }
                        case SDLK_z: {
                            if (!run) break;
                            jeu->play(1, 0);
                            break;
                        }
                        case SDLK_s: {
                            if (!run) break;
                            jeu->play(5, 0);
                            break;
                        }
                        case SDLK_q: {
                            if (!run) break;
                            jeu->play(7, 0);
                            break;
                        }
                        case SDLK_d: {
                            if (!run) break;
                            jeu->play(3, 0);
                            break;
                        }
                        case SDLK_UP: {
                            if (!run) break;
                            jeu->play(0, 1);
                            break;
                        }
                        case SDLK_DOWN: {
                            if (!run) break;
                            jeu->play(0, 5);
                            break;
                        }
                        case SDLK_LEFT: {
                            if (!run) break;
                            jeu->play(0, 7);
                            break;
                        }
                        case SDLK_RIGHT: {
                            if (!run) break;
                            jeu->play(0, 3);
                            break;
                        }
					}
            }
        SDL_RenderPresent(ecran);
        SDL_Delay(200);
    }

/*    SDL_DestroyRenderer(ecran);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();*/
    return 0;
}

int load(Game* jeu, int textures[], SDL_Renderer* ecran){
    Uint8 r = 255; Uint8 g = 255; Uint8 b = 0;
    SDL_Texture* textureTileSetV4 = charger_image_transparente("textures/game/0x72_16x16DungeonTileset.v4.bmp", ecran, r, g, b);
    SDL_Texture* textureTileSetWallsV2 = charger_image_transparente("textures/game/0x72_16x16DungeonTileset_walls.v2.bmp", ecran, r, g, b);
    SDL_Texture* heart = charger_image_transparente("textures/2dheart/heart.bmp", ecran, r, g, b);
    SDL_Texture* half = charger_image_transparente("textures/game/half.bmp", ecran, r, g, b);
    SDL_Texture* key = charger_image_transparente("textures/2dcoinchests/Key.bmp", ecran, r, g, b);

    int depth = jeu->depth();

    int countBoss = 0;
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 52; ++j) {
            switch(jeu->level().getMap()[i * 52 + j]){
                case 0:
                    break;
                case 1:{
                    SDL_Rect sSol; sSol.x = textures[0*8+0]; sSol.y = textures[0*8+1]; sSol.w = textures[0*8+2]; sSol.h = textures[0*8+3];
                    SDL_Rect dSol; dSol.x = 400 + j * 30, dSol.y = 200 + i * 30, dSol.w = textures[0*8+6], dSol.h = textures[0*8+6];
                    SDL_RenderCopy(ecran, textureTileSetWallsV2, &sSol, &dSol);
                    break;
                }
                case 2:{
                    SDL_Rect sMur; sMur.x = textures[1*8+0]; sMur.y = textures[1*8+1]; sMur.w = textures[1*8+2]; sMur.h = textures[1*8+3];
                    SDL_Rect dMur; dMur.x = 400 + j * 30, dMur.y = 200 + i * 30, dMur.w = textures[1*8+6], dMur.h = textures[1*8+6];
                    SDL_RenderCopy(ecran, textureTileSetV4, &sMur, &dMur);
                    break;
                }
                case 3:{
                    countBoss++;
                    SDL_Rect sSol; sSol.x = textures[0*8+0]; sSol.y = textures[0*8+1]; sSol.w = textures[0*8+2]; sSol.h = textures[0*8+3];
                    SDL_Rect dSol; dSol.x = 400 + j * 30, dSol.y = 200 + i * 30, dSol.w = textures[0*8+6], dSol.h = textures[0*8+6];
                    SDL_RenderCopy(ecran, textureTileSetWallsV2, &sSol, &dSol);
                    break;
                }
                case 4:{
                    SDL_Rect sSol; sSol.x = textures[0*8+0]; sSol.y = textures[0*8+1]; sSol.w = textures[0*8+2]; sSol.h = textures[0*8+3];
                    SDL_Rect dSol; dSol.x = 400 + j * 30, dSol.y = 200 + i * 30, dSol.w = textures[0*8+6], dSol.h = textures[0*8+6];
                    SDL_RenderCopy(ecran, textureTileSetWallsV2, &sSol, &dSol);
                    break;
                }
                case 5:{
                    SDL_Rect sSol; sSol.x = textures[0*8+0]; sSol.y = textures[0*8+1]; sSol.w = textures[0*8+2]; sSol.h = textures[0*8+3];
                    SDL_Rect dSol; dSol.x = 400 + j * 30, dSol.y = 200 + i * 30, dSol.w = textures[0*8+6], dSol.h = textures[0*8+6];
                    SDL_RenderCopy(ecran, textureTileSetWallsV2, &sSol, &dSol);
                    break;
                }
                case 6:{
                    SDL_Rect sSol; sSol.x = textures[0*8+0]; sSol.y = textures[0*8+1]; sSol.w = textures[0*8+2]; sSol.h = textures[0*8+3];
                    SDL_Rect dSol; dSol.x = 400 + j * 30, dSol.y = 200 + i * 30, dSol.w = textures[0*8+6], dSol.h = textures[0*8+6];
                    SDL_RenderCopy(ecran, textureTileSetWallsV2, &sSol, &dSol);

                    SDL_Rect sPorteFerm; sPorteFerm.x = textures[8*8+0]; sPorteFerm.y = textures[8*8+1]; sPorteFerm.w = textures[8*8+2]; sPorteFerm.h = textures[8*8+3];
                    SDL_Rect dPorteFerm; dPorteFerm.x = 401 + j * 30, dPorteFerm.y = 178 + i * 30, dPorteFerm.w = textures[8*8+6], dPorteFerm.h = textures[8*8+6];
                    SDL_RenderCopy(ecran, textureTileSetWallsV2, &sPorteFerm, &dPorteFerm);
                    break;
                }
                case 7:{
                    SDL_Rect sSol; sSol.x = textures[0*8+0]; sSol.y = textures[0*8+1]; sSol.w = textures[0*8+2]; sSol.h = textures[0*8+3];
                    SDL_Rect dSol; dSol.x = 400 + j * 30, dSol.y = 200 + i * 30, dSol.w = textures[0*8+6], dSol.h = textures[0*8+6];
                    SDL_RenderCopy(ecran, textureTileSetWallsV2, &sSol, &dSol);

                    SDL_Rect sPiege; sPiege.x = textures[10*8+0]; sPiege.y = textures[10*8+1]; sPiege.w = textures[10*8+2]; sPiege.h = textures[10*8+3];
                    SDL_Rect dPiege; dPiege.x = 402 + j * 30, dPiege.y = 212 + i * 30, dPiege.w = textures[10*8+6], dPiege.h = textures[10*8+6];
                    SDL_RenderCopy(ecran, textureTileSetV4, &sPiege, &dPiege);
                    break;
                }
                case 8:{
                    SDL_Rect sSol; sSol.x = textures[0*8+0]; sSol.y = textures[0*8+1]; sSol.w = textures[0*8+2]; sSol.h = textures[0*8+3];
                    SDL_Rect dSol; dSol.x = 400 + j * 30, dSol.y = 200 + i * 30, dSol.w = textures[0*8+6], dSol.h = textures[0*8+6];
                    SDL_RenderCopy(ecran, textureTileSetWallsV2, &sSol, &dSol);
                    break;
                }
                case 9:{
                    SDL_Rect sSol; sSol.x = textures[0*8+0]; sSol.y = textures[0*8+1]; sSol.w = textures[0*8+2]; sSol.h = textures[0*8+3];
                    SDL_Rect dSol; dSol.x = 400 + i * 30, dSol.y = 200 + j * 30, dSol.w = textures[0*8+6], dSol.h = textures[0*8+6];
                    SDL_RenderCopy(ecran, textureTileSetWallsV2, &sSol, &dSol);

                    SDL_Rect sCle; sCle.x = textures[12*8+0]; sCle.y = textures[12*8+1]; sCle.w = textures[12*8+2]; sCle.h = textures[12*8+3];
                    SDL_Rect dCle; dCle.x = 400 + i * 30, dCle.y = 200 + j * 30, dCle.w = textures[12*8+6], dCle.h = textures[12*8+6];
                    SDL_RenderCopy(ecran, key, &sCle, &dCle);
                    break;
                }
            }
        }
    }
    return 0;
}

int loadProjectilesMonstersDestrutiblesCoins(Game* jeu, int textures[], SDL_Renderer* ecran){
    Uint8 r = 255; Uint8 g = 255; Uint8 b = 0;

    SDL_Texture* textureTileSetV4 = charger_image_transparente("textures/game/0x72_16x16DungeonTileset.v4.bmp", ecran, r, g, b);
    SDL_Texture* coin = charger_image_transparente("textures/2dcoinchests/Coin.bmp", ecran, r, g, b);

    int depth = jeu->depth();
    Coordinates* hPos = jeu->getPlayer()->getCoordinates();
    vector<Destructible> destructibles = jeu->getDestructibles();
    vector<Projectile> projectiles = jeu->getProjectiles();
    vector<Coin> coins = jeu->getCoins();
    vector<Monster> monsters = jeu->getMonsters();


    std::vector<Projectile>::iterator it = projectiles.begin();
    while (it != projectiles.end()) {
        SDL_Rect sProjEnnemi; sProjEnnemi.x = textures[14*8+0]; sProjEnnemi.y = textures[14*8+1]; sProjEnnemi.w = textures[14*8+2]; sProjEnnemi.h = textures[14*8+3];
        SDL_Rect dProjEnnemi; dProjEnnemi.x = 400 + it->getCoordinates()->getX() * 30, dProjEnnemi.y = 200 + it->getCoordinates()->getY() * 30, dProjEnnemi.w = textures[14*8+6], dProjEnnemi.h = textures[14*8+6];
        SDL_RenderCopy(ecran, textureTileSetV4, &sProjEnnemi, &dProjEnnemi);
        it++;
    }

    std::vector<Monster>::iterator ti = monsters.begin();
    while (ti != monsters.end()) {
        int size = 1;
        if(ti->monsterSize() == 2) size = 1.5;
        SDL_Rect sMoBoss; sMoBoss.x = textures[(depth+1)*8+0]; sMoBoss.y = textures[(depth+1)*8+1]; sMoBoss.w = textures[(depth+1)*8+2]; sMoBoss.h = textures[(depth+1)*8+3];
        SDL_Rect dMoBoss; dMoBoss.x = 400 + ti->getCoordinates()->getX() * size * 30, dMoBoss.y = 198 + ti->getCoordinates()->getY() * size * 30, dMoBoss.w = textures[(depth+1)*8+6], dMoBoss.h = textures[(depth+1)*8+6];
        SDL_RenderCopy(ecran, textureTileSetV4, &sMoBoss, &dMoBoss);
        ti++;
    }

    std::vector<Destructible>::iterator at = destructibles.begin();
    while (at != destructibles.end()) {
        SDL_Rect sDestructible; sDestructible.x = textures[7*8+0]; sDestructible.y = textures[0*8+1]; sDestructible.w = textures[7*8+2]; sDestructible.h = textures[7*8+3];
        SDL_Rect dDestructible; dDestructible.x = 400 + at->getCoordinates()->getX(), dDestructible.y = 200 + at->getCoordinates()->getY() * 30, dDestructible.w = textures[7*8+6], dDestructible.h = textures[7*8+6];
        SDL_RenderCopy(ecran, textureTileSetV4, &sDestructible, &dDestructible);
        at++;
    }

    std::vector<Coin>::iterator ta = coins.begin();
    while (ta != coins.end()) {
        SDL_Rect sCoin; sCoin.x = textures[11*8+0]; sCoin.y = textures[11*8+1]; sCoin.w = textures[11*8+2]; sCoin.h = textures[11*8+3];
        SDL_Rect dCoin; dCoin.x = 400 + ta->getCoordinates()->getX() * 30, dCoin.y = 200 + ta->getCoordinates()->getY() * 30, dCoin.w = textures[11*8+6], dCoin.h = textures[11*8+6];
        SDL_RenderCopy(ecran, coin, &sCoin, &dCoin);
        ta++;
    }
    return 0;
}
