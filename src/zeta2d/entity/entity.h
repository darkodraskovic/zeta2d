#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <string>
#include <SDL2/SDL.h>

#include "entity_manager.h"

using namespace std;

namespace Zeta2D {
    class Component;
    
    class Entity {
    public:
        Entity(EntityManager& manager);
        virtual void Init() {};
        virtual void Update(float deltaTime);
        virtual void Render(SDL_Renderer* renderer);
        virtual void Destroy();
        bool GetActive() const;
        
        string name_;
    private:
        EntityManager& manager_;
        bool active_;
        vector<Component*> components_;
    };

}  // Zeta2D

#endif /* ENTITY_H */
