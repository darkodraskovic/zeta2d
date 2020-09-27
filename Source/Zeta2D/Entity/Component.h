#ifndef COMPONENT_H
#define COMPONENT_H

#include <SDL2/SDL.h>
#include "Entity.h"

namespace Zeta2D {

    class Component {
    public:
        virtual void Init() {};
        virtual void Update(float deltaTime) {};
        virtual void Render(SDL_Renderer* renderer) {};
        virtual void Destroy() {}
        Entity& GetOwner() {return *owner;}
        
    private:
        Entity* owner;
        friend class Entity;
    };    

}  // Zeta2D

#endif /* COMPONENT_H */
