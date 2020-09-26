#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

namespace Zeta2D {
    
    class Game {
    public:
        virtual void Init() {};
        virtual void Input(const SDL_Event* event) {};
        virtual void Update(float deltaTime) = 0;
        virtual void Render(SDL_Renderer* renderer) {};
        virtual void Destroy() {};
    };
    
}  // Namespace

#endif /* GAME_H */
