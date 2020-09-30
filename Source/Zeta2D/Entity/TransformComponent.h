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
        vec2 position_;
        float rotation_ = 0;
        vec2 scale_ = {1, 1};
        ivec2 size_ = {32, 32};

    private:
    };

}  // Zeta2D

#endif /* TRANSFORM_COMPONENT_H */
