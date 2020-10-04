#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Texture.h"
#include "../Application/Object.h"
#include "../Asset/AssetManager.h"

using namespace std;

namespace Zeta2D {

    class Animation : public Object {
    public:
        Animation(App* app) : Object(app) {};
        
        void SetTexture(const string& id, int frameW, int frameH) {
            texture_ = app_->GetManager<AssetManager>()->GetTexture(id);
            numFramesX_ = texture_->GetSize().x / frameW;
            numFramesY_ = texture_->GetSize().y / frameH;
            srcRect_.w = frameW;
            srcRect_.h = frameH;
        }

        void AddAnimation(const string& name, const vector<unsigned int> frames) {
            anims_[name] = frames;
        }
        
        void Play(const string& name, SDL_Rect* dstRect, float rotation, SDL_RendererFlip flip) {
            vector<unsigned int>& anim = anims_[name];
            if (SDL_GetTicks() / speed_ > counter_) {
                counter_++;
                index_ = ++index_ % anim.size();
            }
            srcRect_.x = (anim[index_] % numFramesX_) * srcRect_.w;
            srcRect_.y = (anim[index_] / numFramesX_) * srcRect_.h;
            texture_->Draw(&srcRect_, dstRect, rotation, flip);
        };
        unsigned int speed_ = 1000 / 24;
        unsigned int index_ = 0;

    private:
        Texture* texture_;
        unsigned int counter_ = 0;
        unsigned int numFramesX_;
        unsigned int numFramesY_;
        SDL_Rect srcRect_;
        map<string, vector<unsigned int>> anims_;
    };

}  // Zeta2D

#endif /* ANIMATION_H */
