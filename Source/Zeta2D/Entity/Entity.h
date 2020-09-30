#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
#include <map>
#include <SDL2/SDL.h>

#include "EntityManager.h"

using namespace std;

namespace Zeta2D {
    class Component;

    class Entity {
    public:
        Entity(EntityManager* manager);
        virtual void Update(float deltaTime);
        virtual void Render();
        virtual void Destroy();
        bool GetActive() const;
        vector<Component*>& GetComponents();

        template<typename T, typename... TArgs>
        T& AddComponent(TArgs&&... args) {
            T* component(new T(std::forward<TArgs>(args)...));
            component->owner = this;
            components_.push_back(component);
            component->Init();
            typeMap_[&typeid(*component)] = component;
            return *component;
        }

        template<typename T>
        T* GetComponent() {
            return static_cast<T*>(typeMap_[&typeid(T)]);
        }

        template<typename T>
        bool HasComponent() const {
            return typeMap_.find(&typeid(T)) != typeMap_.end();
        };

        string name_;

    private:
        vector<Component*> components_;
        map<const type_info*, Component*> typeMap_;
        EntityManager* manager_;
        bool active_;
    };

}  // Zeta2D

#endif /* ENTITY_H */
