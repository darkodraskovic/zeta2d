#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

namespace Zeta2D {
    
    class TextureManager {
    public:
        static SDL_Texture* LoadTexture(const char* fileName);
        static void Draw( SDL_Texture* texture, SDL_Rect* src, SDL_Rect* dest, const SDL_RendererFlip flip);
    
    private:
        SDL_Renderer* renderer_;
    };

}  // Zeta2D



#endif /* TEXTUREMANAGER_H */
