#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>

namespace Zeta2D {
    class Entity;
    
    class EntityManager {
    public:
        void Update(float deltaTime);
        void Render(SDL_Renderer* renderer);
        
        Entity& AddEntity(std::string name);
        std::vector<Entity*> GetEntities();
        void Clear();

    private:
        std::vector<Entity*> entities_;
    };

}  // Zeta2D

#endif /* ENTITY_MANAGER_H */
