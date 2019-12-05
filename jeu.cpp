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

    SDL_Texture* fond = charger_image("textures/ogun-background-menu", ecran);

    Uint8 r = 255;
    Uint8 g = 255;
    Uint8 b = 255;

    SDL_Rect SrcR;

    SrcR.x = 0;
    SrcR.y = 0;
    SrcR.w = 640; // Largeur de l’objet en pixels (à récupérer)
    SrcR.h = 192; // Hauteur de l’objet en pixels (à récupérer)

    SDL_Rect DestR;

    DestR.x = 350;
    DestR.y = 350;
    DestR.w = 640/3;
    DestR.h = 192/3;


    // Boucle principale

    while(!terminer)
    {
        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, fond, NULL, NULL);

        while( SDL_PollEvent( &evenements ) )
            switch(evenements.type)
            {
                case SDL_QUIT:
                    terminer = true; break;
                case SDL_KEYDOWN:
                    switch(evenements.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                        case SDLK_q:
                            terminer = true; break;
                    }
            }
        SDL_RenderPresent(ecran);
    }

    SDL_DestroyRenderer(ecran);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;
}