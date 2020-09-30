#include "AssetManager.h"
#include "../Application/App.h"
#include <SDL2/SDL_image.h>

using namespace Zeta2D;

void AssetManager::Clear() {
    textures_.clear();
}

SDL_Texture* AssetManager::LoadTexture(const char *fileName) {
    SDL_Surface* surface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(App::renderer_, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void AssetManager::AddTexture(string id, const char* fileName) {
    textures_.emplace(id, LoadTexture(fileName));
}

SDL_Texture* AssetManager::GetTexture(string id) {
    return textures_[id];
}
