#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <SDL2/SDL_render.h>
#include <glm/glm.hpp>
#include "../Application/App.h"
#include "Component.h"

using namespace glm;

namespace Zeta2D {

    class TransformComponent : public Component {
    public:
        virtual void Update(float deltaTime) override {
            position_ += velocity_ * deltaTime;
        }
        virtual void Render() override {
            SDL_Rect rect{
                (int)position_.x, (int)position_.y,
                size_.x, size_.y,
            };
            SDL_SetRenderDrawColor(App::renderer_, 255, 255, 255, 255);
            SDL_RenderFillRect(App::renderer_, &rect);
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
