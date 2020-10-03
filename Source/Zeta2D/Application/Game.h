#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "App.h"

namespace Zeta2D {

    class Game {
    public:
        virtual void Init(App* app) {
            app_ = app;
        };
        virtual void Input(const SDL_Event* event) {}
        virtual void Update(float deltaTime) {};
        virtual void Render() {}
        virtual void Destroy() {}

    protected:
        App* app_;
        friend class App;
    };

}  // Namespace

#endif /* GAME_H */
