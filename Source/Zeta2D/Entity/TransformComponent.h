#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <glm/glm.hpp>
#include "Component.h"

using namespace glm;

namespace Zeta2D {

    class TransformComponent : public Component {
    public:
        virtual void Update(float deltaTime) override {
            position_ += velocity_ * deltaTime;
        }
        virtual void Render(SDL_Renderer* renderer) override {
            SDL_Rect rect{
                (int)position_.x, (int)position_.y,
                size_.x, size_.y,
            };
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect);
        }        
        
        vec2 position_;
        float rotation_ = 0;
        vec2 scale_;
        ivec2 size_ = {4, 4};

        vec2 velocity_;
        
    private:
    };

}  // Zeta2D

#endif /* TRANSFORM_COMPONENT_H */
