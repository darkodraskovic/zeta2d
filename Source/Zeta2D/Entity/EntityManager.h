#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>

#include "../Application/App.h"
#include "../Application/Manager.h"

namespace Zeta2D {
    class Entity;

    class EntityManager : public Manager {
        CONTEXT(EntityManager)
    public:
        void Update(float deltaTime);
        void Render();

        Entity* AddEntity(std::string name);
        std::vector<Entity*>& GetEntities();
        void Clear();

    private:
        std::vector<Entity*> entities_;
    };

}  // Zeta2D

#endif /* ENTITY_MANAGER_H */
