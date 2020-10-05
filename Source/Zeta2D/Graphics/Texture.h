#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <glm/glm.hpp>
#include <string>
#include "../Application/Object.h"

namespace Zeta2D {
    
    class Texture : public Object {
    public:
        Texture(App* app);
        void Render(SDL_Rect* src, SDL_Rect* dst,
            float rotation, const SDL_RendererFlip flip);
        const glm::ivec2& GetSize();
        
    private:
        void SetSDLTexture(SDL_Texture* texture);
        SDL_Texture* texture_;
        glm::ivec2 size_;
        friend class AssetManager;
    };

}  // Zeta2D



#endif /* TEXTURE_H */
