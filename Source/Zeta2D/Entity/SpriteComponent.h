#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include <iostream>

#include <SDL2/SDL.h>
#include <string>

#include "../Application/App.h"
#include "../Asset/AssetManager.h"
#include "../Graphics/Texture.h"
#include "Component.h"
#include "TransformComponent.h"

namespace Zeta2D {

    class SpriteComponent : public Component
    {
    public:
        SpriteComponent() {
            
        };
        
        void Init() override {
            transform_ = owner->GetComponent<TransformComponent>();
            srcRect_.x = 0;
            srcRect_.y = 0;
            srcRect_.w = transform_->size_.x;
            srcRect_.h = transform_->size_.y;
        }

        virtual void Update(float deltaTime) override {
        };

        virtual void Render() override {
            dstRect_.x = (int)transform_->position_.x;
            dstRect_.y = (int)transform_->position_.y;
            dstRect_.w = transform_->size_.x * transform_->scale_.x;
            dstRect_.h = transform_->size_.y * transform_->scale_.y;
            Texture::Draw(texture_, &srcRect_, &dstRect_,
                          transform_->rotation_, spriteFlip);
        };

        void SetTexture(const string& id) {
            texture_ = owner->GetManager<AssetManager>()->GetTexture(id);
        }

        SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

    private:
        TransformComponent* transform_;
        SDL_Texture* texture_;
        SDL_Rect srcRect_;
        SDL_Rect dstRect_;
    };


}  // Zeta2D

#endif /* SPRITECOMPONENT_H */
