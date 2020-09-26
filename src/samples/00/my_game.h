#ifndef MY_GAME_H
#define MY_GAME_H

#include "glm/glm.hpp"
#include "zeta2d/app.h"

using namespace glm;
using namespace Zeta2D;

vec2 projectilePos{0, 0};
vec2 projectileVel{100, 100};

class MyGame : public Game {
    virtual void Update(float deltaTime) {
        projectilePos += projectileVel * deltaTime;
    };
    
    virtual void Render(SDL_Renderer* renderer) {
        SDL_Rect projectile {
            (int)projectilePos.x,
            (int)projectilePos.y,
            10, 10
        };
        SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
        SDL_RenderFillRect(renderer, &projectile);
    };
};

#endif /* MY_GAME_H */
