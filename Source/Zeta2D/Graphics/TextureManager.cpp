#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#include "../Application/App.h"
#include "TextureManager.h"

using namespace Zeta2D;

SDL_Texture* TextureManager::LoadTexture(const char *fileName) {
    SDL_Surface* surface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(App::renderer_, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void TextureManager::Draw(
        SDL_Texture* texture,
        SDL_Rect* src, SDL_Rect* dest,
        const SDL_RendererFlip flip) {
    SDL_RenderCopyEx(App::renderer_, texture, src, dest, 0.0, NULL, flip);
}
