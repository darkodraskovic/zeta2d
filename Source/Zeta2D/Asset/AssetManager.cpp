#include "AssetManager.h"
#include "../Application/App.h"
#include "Zeta2D/Graphics/Texture.h"
#include <SDL2/SDL_image.h>

using namespace Zeta2D;

void AssetManager::Clear() {
    textures_.clear();
}

Texture* AssetManager::LoadTexture(const char *fileName) {
    SDL_Surface* surface = IMG_Load(fileName);
    SDL_Texture* sdlTexture = SDL_CreateTextureFromSurface(
        GetRenderer(), surface);
    SDL_FreeSurface(surface);
    
    Texture* texture = new Texture(app_);
    texture->SetSDLTexture(sdlTexture);
    return texture;
}

void AssetManager::AddTexture(string id, const char* fileName) {
    textures_.emplace(id, LoadTexture(fileName));
}

Texture* AssetManager::GetTexture(string id) {
    return textures_[id];
}
