#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions_SDL.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	char textures[19][8];
	
	ifstream infile("textures/texture_coordinates.txt");
	
	int i = -1; int j = -1;
	while(infile){
		string s;
		if(!getline(infile, s)) break;
		i++;
		istringstream ss(s);
		 	
		while(ss){
			j++;
			if(i == 19) i = -1;
			string s;
			if(!getline(ss,s,','))break;
			strcpy(textures[i], s.c_str());
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

    fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920/2, 1080/2, SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL)
    {
        printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture* fond = charger_image("textures/background/ogun-background-menu.bmp", ecran);

    Uint8 r = 255; Uint8 g = 255; Uint8 b = 0;

    SDL_Rect SrcR;

    SrcR.x = 0; SrcR.y = 0; SrcR.w = 1920; SrcR.h = 1080;

    SDL_Rect DestR;

    DestR.x = 0; DestR.y = 0; DestR.w = 1920/2; DestR.h = 1080/2;


    // Boucle principale

    while(!terminer)
    {
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, fond, &SrcR, &DestR);

		while( SDL_PollEvent( &evenements ) )
			switch(evenements.type)
			{
				case SDL_QUIT:
					terminer = true; break;
				case SDL_KEYDOWN:
					switch(evenements.key.keysym.sym){
				        case SDLK_ESCAPE:
				            SDL_DestroyRenderer(ecran);
				            SDL_DestroyWindow(fenetre);
				            SDL_Quit();
				            terminer = true; break;
				        case SDLK_SPACE:
							SDL_RenderClear(ecran);
							
				            break;
					}
            }
        SDL_RenderPresent(ecran);
    }

    SDL_DestroyRenderer(ecran);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}
