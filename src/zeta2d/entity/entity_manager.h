#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>

namespace Zeta2D {
    class Entity;
    
    class EntityManager {
    public:
        virtual void Update(float deltaTime);
        virtual void Render(SDL_Renderer* renderer);
        
        Entity& AddEntity(std::string name);
        std::vector<Entity*> GetEntities() const;
        void Clear();

    private:
        std::vector<Entity* > entities_;
    };

}  // Zeta2D

#endif /* ENTITY_MANAGER_H */
