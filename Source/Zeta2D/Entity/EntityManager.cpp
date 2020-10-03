#include <iostream>
#include "EntityManager.h"
#include "Entity.h"

using namespace Zeta2D;

void EntityManager::Update(float deltaTime) {
    for (Entity* entity: entities_) {
        entity->Update(deltaTime);
    }
}

void EntityManager::Render() {
    for (Entity* entity: entities_) {
        entity->Render();
    }
}

Entity* EntityManager::AddEntity(std::string name) {
    Entity* entity = new Entity(app_);
    entity->name_ = name;
    entities_.emplace_back(entity);
    return entity;
}

std::vector<Entity*>& EntityManager::GetEntities() {
    return entities_;
}

void EntityManager::Clear() {
    for (auto& entity: entities_) {
        entity->Destroy();
    }
}
