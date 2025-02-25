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
	short textures[19*8];

	ifstream infile("textures/texture_coordinates.txt");
	
	short i = -1; short j = -1;
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
    SDL_Rect SrcR; SrcR.x = 0; SrcR.y = 0; SrcR.w = 1920; SrcR.h = 1080;
    SDL_Rect DestR; DestR.x = 0; DestR.y = 0; DestR.w = 1920; DestR.h = 1080;

    SDL_Texture* textureTileSetWallsV2 = charger_image_transparente("textures/game/0x72_16x16DungeonTileset_walls.v2.bmp", ecran, r, g, b);
    SDL_Texture* key = charger_image_transparente("textures/2dcoinchests/Key.bmp", ecran, r, g, b);
    SDL_Texture* textureTileSetV4 = charger_image_transparente("textures/game/0x72_16x16DungeonTileset.v4.bmp", ecran, r, g, b);
    SDL_Texture* coin = charger_image_transparente("textures/2dcoinchests/Coin.bmp", ecran, r, g, b);
    SDL_Texture* heart = charger_image_transparente("textures/2dheart/heart.bmp", ecran, r, g, b);
    SDL_Texture* half = charger_image_transparente("textures/2dheart/half.bmp", ecran, r, g, b);


    bool run = false;
    Game* jeu;

    while(!terminer)
    {
        SDL_RenderClear(ecran);
        if (!run) {
            SDL_RenderCopy(ecran, fondMenu, &SrcR, &DestR);
        } else {
            SDL_RenderCopy(ecran, fondJeu, &SrcR, &DestR);

            load(jeu, textures, ecran, textureTileSetV4, textureTileSetWallsV2, key);
            loadProjectilesMonstersDestrutiblesCoins(jeu, textures, ecran, textureTileSetV4, coin, heart, half);
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
                            if (!run) run = true;
                            Game g = Game(1);
                            jeu = &g;
                            SDL_Delay(500);
                            break;
                        }
                        case SDLK_z: {
                            if (!run) break;
                            terminer = !jeu->play(1, 0);
                            break;
                        }
                        case SDLK_s: {
                            if (!run) break;
                            terminer = !jeu->play(5, 0);
                            break;
                        }
                        case SDLK_q: {
                            if (!run) break;
                            terminer = !jeu->play(7, 0);
                            break;
                        }
                        case SDLK_d: {
                            if (!run) break;
                            terminer = !jeu->play(3, 0);
                            break;
                        }
                        case SDLK_UP: {
                            if (!run) break;
                            terminer = !jeu->play(0, 1);
                            break;
                        }
                        case SDLK_DOWN: {
                            if (!run) break;
                            terminer = !jeu->play(0, 5);
                            break;
                        }
                        case SDLK_LEFT: {
                            if (!run) break;
                            terminer = !jeu->play(0, 7);
                            break;
                        }
                        case SDLK_RIGHT: {
                            if (!run) break;
                            terminer = !jeu->play(0, 3);
                            break;
                        }
					}
            }
        SDL_RenderPresent(ecran);
        SDL_Delay(200);
    }

    SDL_DestroyRenderer(ecran);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}

short load(Game* jeu, short textures[], SDL_Renderer* ecran, SDL_Texture* textureTileSetV4, SDL_Texture* textureTileSetWallsV2, SDL_Texture* key){
    short depth = jeu->depth();

    short countBoss = 0;
    for (short i = 0; i < 25; ++i) {
        for (short j = 0; j < 52; ++j) {
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

short loadProjectilesMonstersDestrutiblesCoins(Game* jeu, short textures[], SDL_Renderer* ecran, SDL_Texture* textureTileSetV4, SDL_Texture* coin, SDL_Texture* heart, SDL_Texture* half){
    short depth = jeu->depth();

    vector<Destructible> destructibles = jeu->getDestructibles();
    vector<Projectile> projectiles = jeu->getProjectiles();
    vector<Drop> drops = jeu->getDrops();
    vector<Monster> monsters = jeu->getMonsters();

    Coordinates* hPos = jeu->getPlayer()->getCoordinates();

    double heroAngle;
    if(jeu->getPlayer()->focus() == 7) heroAngle = 180;
    else heroAngle = 0;
    SDL_Rect sHero; sHero.x = textures[18*8+0]; sHero.y = textures[18*8+1]; sHero.w = textures[18*8+2]; sHero.h = textures[18*8+3];
    SDL_Rect dHero; dHero.x = 400 + jeu->getPlayer()->getCoordinates()->getX() * 30, dHero.y = 200 + jeu->getPlayer()->getCoordinates()->getY() * 30, dHero.w = textures[18*8+6], dHero.h = textures[18*8+6];
    SDL_RenderCopyEx(ecran, textureTileSetV4, &sHero, &dHero, heroAngle, NULL, SDL_FLIP_NONE);

    std::vector<Projectile>::iterator it = projectiles.begin();
    while (it != projectiles.end()) {
        short index;
        double angle;
        if(it->playerProjectile()) index = 14;
        else index = 13;
        switch(it->getDirection()){
            case 1: break;
            case 2:
                angle = 45.0;
                break;
            case 3: break;
            case 4:
                angle = - 45.0;
                break;
            case 5:
                angle = - 90.0;
                break;
            case 6:
                angle = - 135.0;
                break;
            case 7:
                angle = - 180.0;
                break;
            case 8:
                angle = - 225.0;
                break;
        }

        SDL_Rect sProj; sProj.x = textures[index*8+0]; sProj.y = textures[index*8+1]; sProj.w = textures[index*8+2]; sProj.h = textures[index*8+3];
        SDL_Rect dProj; dProj.x = 400 + it->getCoordinates()->getX() * 30, dProj.y = 200 + it->getCoordinates()->getY() * 30, dProj.w = textures[index*8+6], dProj.h = textures[8*8+6];
        SDL_RenderCopyEx(ecran, textureTileSetV4, &sProj, &dProj, angle, NULL, SDL_FLIP_NONE);
        it = next(it);
    }

    std::vector<Destructible>::iterator at = destructibles.begin();
    while (at != destructibles.end()) {
        SDL_Rect sDestructible; sDestructible.x = textures[7*8+0]; sDestructible.y = textures[7*8+1]; sDestructible.w = textures[7*8+2]; sDestructible.h = textures[7*8+3];
        SDL_Rect dDestructible; dDestructible.x = 400 + at->getCoordinates()->getX() * 30, dDestructible.y = 200 + at->getCoordinates()->getY() * 30, dDestructible.w = textures[7*8+6], dDestructible.h = textures[7*8+6];
        SDL_RenderCopy(ecran, textureTileSetV4, &sDestructible, &dDestructible);
        at = next(at);
    }

    std::vector<Drop>::iterator ta = drops.begin();
    while (ta != drops.end()) {
        short dropIndex;
        if(ta->isAPotion()) dropIndex = 17;
        else dropIndex = 11;
        SDL_Rect sDrop; sDrop.x = textures[dropIndex*8+0]; sDrop.y = textures[dropIndex*8+1]; sDrop.w = textures[dropIndex*8+2]; sDrop.h = textures[dropIndex*8+3];
        SDL_Rect dDrop; dDrop.x = 400 + ta->getCoordinates()->getX() * 30, dDrop.y = 200 + ta->getCoordinates()->getY() * 30, dDrop.w = textures[dropIndex*8+6], dDrop.h = textures[dropIndex*8+6];
        if(dropIndex == 11) SDL_RenderCopy(ecran, coin, &sDrop, &dDrop);
        else SDL_RenderCopy(ecran, textureTileSetV4, &sDrop, &dDrop);
        ta = next(ta);
    }

    for (short i = 1; i <= jeu->getPlayer()->hpLeft(); ++i) {
        if (jeu->getPlayer()->hpLeft() != 0) {
            short coeurIndex;
            if (i == jeu->getPlayer()->hpLeft() && i % 2 == 1) {
                coeurIndex = 16;
            } else {
                coeurIndex = 15;
            }
            SDL_Rect sCoeur; sCoeur.x = textures[coeurIndex * 8 + 0]; sCoeur.y = textures[coeurIndex * 8 + 1]; sCoeur.w = textures[coeurIndex * 8 + 2]; sCoeur.h = textures[coeurIndex * 8 + 3];
            SDL_Rect dCoeur; dCoeur.x = 100 * i + ta->getCoordinates()->getX() * 100, dCoeur.y = 75, dCoeur.w = textures[coeurIndex * 8 + 6] / 1.5, dCoeur.h = textures[coeurIndex * 8 + 6] / 1.5;
            if (coeurIndex == 16) SDL_RenderCopy(ecran, half, &sCoeur, &dCoeur);
            else SDL_RenderCopy(ecran, heart, &sCoeur, &dCoeur);
        }
    }

    std::vector<Monster>::iterator ti = monsters.begin();
    while (ti != monsters.end()) {
        double angle;
        int size = 1;
        switch(ti->focus()){
            case 1: break;
            case 2:
                angle = 45.0;
                break;
            case 3: break;
            case 4:
                angle = - 45.0;
                break;
            case 5:
                angle = - 90.0;
                break;
            case 6:
                angle = - 135.0;
                break;
            case 7:
                angle = - 180.0;
                break;
            case 8:
                angle = - 225.0;
                break;
        }


        if(ti->monsterSize() == 2) size = 1.5;
        SDL_Rect sMoBoss; sMoBoss.x = textures[(depth+1)*8+0]; sMoBoss.y = textures[(depth+1)*8+1]; sMoBoss.w = textures[(depth+1)*8+2]; sMoBoss.h = textures[(depth+1)*8+3];
        SDL_Rect dMoBoss; dMoBoss.x = 400 + ti->getCoordinates()->getX() * size * 30, dMoBoss.y = 198 + ti->getCoordinates()->getY() * 30, dMoBoss.w = textures[(depth+1)*8+6] * size, dMoBoss.h = textures[(depth+1)*8+6] * size;
        SDL_RenderCopyEx(ecran, textureTileSetV4, &sMoBoss, &dMoBoss, angle, NULL, SDL_FLIP_NONE);
        ti = next(ti);
    }

    return 0;
}
