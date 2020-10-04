#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h>
#include "../Application/Object.h"

namespace Zeta2D {
    class Entity;
    class Component : public Object {
    public:
        Component(App* app) : Object(app) {};
        virtual void Init() {};
        virtual void Update(float deltaTime) {};
        virtual void Render() {};
        virtual void Destroy() {}

    protected:
        Entity* owner;

    private:
        friend class Entity;
    };

}  // Zeta2D

#endif /* COMPONENT_H */
