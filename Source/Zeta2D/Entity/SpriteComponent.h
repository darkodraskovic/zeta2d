#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <glm/fwd.hpp>
#include <iostream>

#include <SDL2/SDL.h>
#include <string>

#include "../Application/App.h"
#include "../Asset/AssetManager.h"
#include "../Graphics/Texture.h"
#include "Component.h"
#include "Entity.h"

namespace Zeta2D {

    class SpriteComponent : public Component
    {
    public:
        SpriteComponent(App* app) : Component(app) {};

        virtual void Render() override {
            Transform& transform = owner->transform_;
            dstRect_.x = (int)transform.position_.x;
            dstRect_.y = (int)transform.position_.y;
            dstRect_.w = srcRect_.w * transform.scale_.x;
            dstRect_.h = srcRect_.h * transform.scale_.y;
            Draw();
        };

        virtual void Draw() {
            texture_->Draw(&srcRect_, &dstRect_, owner->transform_.rotation_, spriteFlip);
        }

        virtual void SetTexture(const string& id) {
            texture_ = GetManager<AssetManager>()->GetTexture(id);
        }

        SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
        bool fixed_ = false;
        SDL_Rect srcRect_ = {0, 0, 32, 32};
        
    protected:
        Texture* texture_;
        SDL_Rect dstRect_;
    };


}  // Zeta2D

#endif /* SPRITECOMPONENT_H */
