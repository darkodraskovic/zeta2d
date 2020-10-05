#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "../Asset/AssetManager.h"
#include "../Entity/Entity.h"
#include "../Graphics/Texture.h"
#include "Component.h"

namespace Zeta2D {

    class SpriteComponent : public Component
    {
    public:
        SpriteComponent(App* app) : Component(app) {};

        virtual void SetTexture(const string& id) {
            texture_ = app_->GetManager<AssetManager>()->GetTexture(id);
        }
        
        virtual void Render() override {
            Transform& transform = owner->transform_;
            dstRect_.x = (int)transform.position_.x;
            dstRect_.y = (int)transform.position_.y;
            dstRect_.w = srcRect_.w * transform.scale_.x;
            dstRect_.h = srcRect_.h * transform.scale_.y;
            texture_->Render(&srcRect_, &dstRect_, transform.rotation_, flip_);
        }
        
        SDL_RendererFlip flip_ = SDL_FLIP_NONE;
        bool fixed_ = false;
        SDL_Rect srcRect_ = {0, 0, 32, 32};
        SDL_Rect dstRect_;

        Texture* texture_;
    };

}  // Zeta2D

#endif /* SPRITECOMPONENT_H */
