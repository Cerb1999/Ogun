#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions_SDL.h"

int main(int argc, char *argv[])
{
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

    fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL)
    {
        printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture* fond = charger_image("textures/background/ogun-background-menu", ecran);

    Uint8 r = 255;
    Uint8 g = 255;
    Uint8 b = 0;

    SDL_Rect SrcR;

    SrcR.x = 0;
    SrcR.y = 0;
    SrcR.w = 1920; // Largeur de l’objet en pixels (à récupérer)
    SrcR.h = 1080; // Hauteur de l’objet en pixels (à récupérer)

    SDL_Rect DestR;

    DestR.x = 350;
    DestR.y = 350;
    DestR.w = 1920/2;
    DestR.h = 1080/3;


    // Boucle principale

    while(!terminer)
    {
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, fond, NULL, NULL);

        while( SDL_PollEvent( &evenements ) )
            switch(evenements.type)
            {
                case SDLK_ESCAPE:
                    SDL_DestroyRenderer(ecran);
                    SDL_DestroyWindow(fenetre);
                    SDL_Quit();
                    terminer = true; break;
                case SDLK_SPACE:
                    break;
            }
        SDL_RenderPresent(ecran);
    }

    SDL_DestroyRenderer(ecran);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}