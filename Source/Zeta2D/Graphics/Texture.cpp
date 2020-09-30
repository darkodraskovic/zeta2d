#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#include "../Application/App.h"
#include "Texture.h"

using namespace Zeta2D;

void Texture::Draw(SDL_Texture *texture, SDL_Rect *src, SDL_Rect *dst,
                   float rotation, const SDL_RendererFlip flip) {
  SDL_RenderCopyEx(App::renderer_, texture, src, dst, rotation, NULL, flip);
}
