#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <typeinfo>
#include <vector>
#include <string>
#include <map>
#include <SDL2/SDL.h>

#include "../Application/App.h"
#include "../Application/Object.h"
#include "EntityManager.h"
#include "TransformComponent.h"

using namespace std;

namespace Zeta2D {
    // class Component;
    
    class Entity :public Object {        
    public:
        Entity(App* app) : Object(app) {
            transform_ = AddComponent<TransformComponent>();
        };
        virtual void Update(float deltaTime);
        virtual void Render();
        virtual void Destroy();
        bool GetActive() const;
        vector<Component*>& GetComponents();
        App* GetApp();

        template<typename T, typename... TArgs>
        T* AddComponent() {
            T* component(new T(this->app_));
            component->owner = this;
            components_.push_back(component);
            component->Init();
            typeMap_[&typeid(T)] = component;
            return component;
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
        TransformComponent* transform_;

    private:
        vector<Component*> components_;
        map<const type_info*, Component*> typeMap_;
        bool active_ = true;

        friend class EntityManager;
    };

}  // Zeta2D

#endif /* ENTITY_H */
