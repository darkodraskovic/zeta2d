#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>

#include "SpriteComponent.h"

using namespace std;

namespace Zeta2D {

    class AnimationComponent : public SpriteComponent {
    public:
        AnimationComponent(App* app) : SpriteComponent(app) {};
        void SetTexture(const string& id, int frameW, int frameH);
        void AddAnimation(const string& name, const vector<unsigned int> frames);
        virtual void Render() override;

        string currentAnim_;
        unsigned int speed_ = 1000 / 24;
        unsigned int index_ = 0;

    private:
        unsigned int counter_ = 0;
        unsigned int numFramesX_;
        unsigned int numFramesY_;
        map<string, vector<unsigned int>> anims_;
    };

}  // Zeta2D

#endif /* ANIMATIONCOMPONENT_H */
