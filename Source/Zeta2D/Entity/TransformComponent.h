#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <SDL2/SDL_render.h>
#include <glm/glm.hpp>
#include "Component.h"

using namespace glm;

namespace Zeta2D {
    class Entity;
    
    class TransformComponent : public Component {
    public:
        TransformComponent(App* app) : Component(app) {};
        vec2 position_;
        float rotation_ = 0;
        vec2 scale_ = {1, 1};
        ivec2 size_ = {32, 32};
    };

}  // Zeta2D

#endif /* TRANSFORM_COMPONENT_H */
