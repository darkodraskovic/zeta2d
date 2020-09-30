#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

namespace Zeta2D {

    class Texture {
    public:
        static void Draw(
            SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dst,
            float rotation, const SDL_RendererFlip flip);
    };

}  // Zeta2D



#endif /* TEXTURE_H */
