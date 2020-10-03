#include <iostream>
#include "Entity.h"
#include "Component.h"

using namespace Zeta2D;

void Entity::Update(float deltaTime) {
    for (Component* component : components_) {
        component->Update(deltaTime);
    }
}

void Entity::Render() {
    for (Component* component : components_) {
        component->Render();
    }
}

bool Entity::GetActive() const {
    return active_;
}

App* Entity::GetApp() {
    return app_;
}

vector<Component*>& Entity::GetComponents() {
    return components_;
}

void Entity::Destroy() {
    active_  = false;
}
