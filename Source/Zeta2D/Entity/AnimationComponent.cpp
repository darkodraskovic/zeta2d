#include "AnimationComponent.h"

using namespace Zeta2D;

void AnimationComponent::SetTexture(const string& id, int frameW, int frameH) {
    texture_ = app_->GetManager<AssetManager>()->GetTexture(id);
    numFramesX_ = texture_->GetSize().x / frameW;
    numFramesY_ = texture_->GetSize().y / frameH;
    srcRect_.w = frameW;
    srcRect_.h = frameH;

    vector<unsigned int> frames;
    for (int i = 0; i < numFramesX_ * numFramesY_; ++i) {
        frames.push_back(i);
    }
    AddAnimation("default", frames);
    currentAnim_ = "default";
}

void AnimationComponent::AddAnimation(const string& name, const vector<unsigned int> frames) {
    anims_[name] = frames;
}
        
void AnimationComponent::Render() {

    vector<unsigned int>& anim = anims_[currentAnim_];
    if (SDL_GetTicks() / speed_ > counter_) {
        counter_++;
        index_ = ++index_ % anim.size();
    }
    srcRect_.x = (anim[index_] % numFramesX_) * srcRect_.w;
    srcRect_.y = (anim[index_] / numFramesX_) * srcRect_.h;

    SpriteComponent::Render();
};
