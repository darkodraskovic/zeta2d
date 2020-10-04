#ifndef ANIMATEDCOMPONENT_H
#define ANIMATEDCOMPONENT_H

#include <SDL2/SDL_timer.h>
#include <string>
#include <SDL2/SDL.h>

#include "../Graphics/Animation.h"
#include "SpriteComponent.h"

namespace Zeta2D {
    
    class AnimatedComponent : public SpriteComponent
    {
    public:
        AnimatedComponent(App* app) : SpriteComponent(app) {
            animation_ = new Animation(app);
        };
        
        void Init() override {
        }

        virtual void Update(float deltaTime) override {
        };

        virtual void Render() override {
            SpriteComponent::Render();
        };

        virtual void Draw() override {
            animation_->Play(currentAnim_, &dstRect_, owner->transform_->rotation_, spriteFlip);
        };
        
        Animation* animation_;
        string currentAnim_;
    };


}  // Zeta2D

#endif /* ANIMATEDCOMPONENT_H */
