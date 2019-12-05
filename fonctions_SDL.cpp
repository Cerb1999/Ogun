#include "fonctions_SDL.h"
#include <SDL2/SDL.h>

SDL_Texture* charger_image(const char* nomfichier, SDL_Renderer* renderer){
    SDL_Surface* surface = SDL_LoadBMP(nomfichier);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    return texture;
}


SDL_Texture* charger_image_transparente(const char* nomfichier, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b){
    SDL_Surface* surface = SDL_LoadBMP(nomfichier);

    SDL_PixelFormat *format = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);

    Uint32 key = SDL_MapRGB(format, r, g, b);

    SDL_SetColorKey(surface, SDL_TRUE, key) ;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    return texture;
}
