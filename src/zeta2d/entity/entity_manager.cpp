#include <iostream>
#include "entity_manager.h"
#include "entity.h"

using namespace Zeta2D;

void EntityManager::Update(float deltaTime) {
    for (auto& entity: entities_) {
        entity->Update(deltaTime);
    }
}

void EntityManager::Render(SDL_Renderer *renderer) {
    for (auto& entity: entities_) {
        entity->Render(renderer);
    }    
}

Entity& EntityManager::AddEntity(std::string name) {
    Entity* entity = new Entity(this);
    entity->name_ = name;
    entities_.emplace_back(entity);
    return *entity;
}

std::vector<Entity*> EntityManager::GetEntities() {
    return entities_;
}

void EntityManager::Clear() {
    for (auto& entity: entities_) {
        entity->Destroy();
    }
}
