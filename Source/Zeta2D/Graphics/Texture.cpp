#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#include "../Application/App.h"
#include "../Asset/AssetManager.h"
#include "Texture.h"

using namespace Zeta2D;

Texture::Texture(App* app) : Object(app) {}

void Texture::Render(SDL_Rect *src, SDL_Rect *dst, float rotation, const SDL_RendererFlip flip) {
    SDL_RenderCopyEx(GetRenderer(), texture_, src, dst, rotation, NULL, flip);
}

const glm::ivec2& Texture::GetSize() {
    return size_;
}

void Texture::SetSDLTexture(SDL_Texture* texture) {
    texture_ = texture;
    SDL_QueryTexture(texture_, nullptr, nullptr, &size_.x, &size_.y);
}
