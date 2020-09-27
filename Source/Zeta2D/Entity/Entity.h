#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>

#include "EntityManager.h"

using namespace std;

namespace Zeta2D {
    class Component;
    
    class Entity {
    public:
        Entity(EntityManager* manager);
        virtual void Update(float deltaTime);
        virtual void Render(SDL_Renderer* renderer);
        virtual void Destroy();
        bool GetActive() const;
        vector<Component*> GetComponents();

        template<typename T, typename... TArgs>
        T& AddComponent(TArgs&&... args) {
            T* component(new T(std::forward<TArgs>(args)...));
            component->owner = this;
            components_.push_back(component);
            component->Init();
            return *component;
        }
        
        string name_;
        
    private:
        vector<Component*> components_;
        EntityManager* manager_;
        bool active_;
    };

}  // Zeta2D

#endif /* ENTITY_H */
