#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "app.h"

namespace Zeta2D {

    class Game {
    public:
        virtual void Init() {};
        virtual void Input(const SDL_Event* event) {}
        virtual void Update(float deltaTime) {};
        virtual void Render(SDL_Renderer* renderer) {}
        virtual void Destroy() {}
        
        App& GetApp() { return *app_;}
    private:
        App* app_;
        friend class App;
    };
    
}  // Namespace

#endif /* GAME_H */
