#ifndef MY_GAME_H
#define MY_GAME_H

#include <glm/fwd.hpp>
#include <glm/gtc/random.hpp>
#include <string>
#include "Zeta2D/Application/Game.h"
#include "Zeta2D/Application/Consts.h"
#include "Zeta2D/Asset/AssetManager.h"
#include "Zeta2D/Entity/Entity.h"
#include "Zeta2D/Entity/TransformComponent.h"
#include "Zeta2D/Entity/SpriteComponent.h"
#include "Zeta2D/Entity/PhysicsComponent.h"

using namespace glm;
using namespace Zeta2D;

class MyGame : public Game {
public:
    virtual void Init() override {
        string textureFilePath = "../assets/images/tank-big-right.png";
        App::assetManager_->AddTexture("tank-big-right", textureFilePath.c_str());

        for (int i = 0; i < 10; ++i)
        {
            Entity& e = GetApp().GetManager().AddEntity("tank");
            TransformComponent& tc = e.AddComponent<TransformComponent>();
            tc.size_ = {64, 64};
            tc.position_ = linearRand(vec2{0,0}, vec2{WINDOW_WIDTH, WINDOW_HEIGHT});
            PhysicsComponent& pc = e.AddComponent<PhysicsComponent>();
            pc.velocity_ = linearRand(vec2{-50,-50}, vec2{50, 50});
            pc.aVelocity_ = linearRand(-120, 120);
            SpriteComponent& sc = e.AddComponent<SpriteComponent>("tank-big-right");
        }
    }

    virtual void Update(float deltaTime) override {
    };
};

#endif /* MY_GAME_H */
