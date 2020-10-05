#ifndef MY_GAME_H
#define MY_GAME_H

#include <glm/fwd.hpp>
#include <glm/gtc/random.hpp>
#include <string>
#include "Zeta2D/Application/Game.h"
#include "Zeta2D/Application/Consts.h"
#include "Zeta2D/Asset/AssetManager.h"
#include "Zeta2D/Entity/Entity.h"
#include "Zeta2D/Entity/SpriteComponent.h"
#include "Zeta2D/Entity/PhysicsComponent.h"
#include "Zeta2D/Entity/AnimationComponent.h"

using namespace glm;
using namespace Zeta2D;

class MyGame : public Game {
public:
    virtual void Init(App* app) override {
        Game::Init(app);
        
        string prefix = "../assets/images/";
        
        app_->GetManager<AssetManager>()->AddTexture("tank", (prefix + "tank-big-right.png").c_str());
        app_->GetManager<AssetManager>()->AddTexture("chopper", (prefix + "chopper-spritesheet.png").c_str());
        app_->GetManager<AssetManager>()->GetTexture("tank");
        for (int i = 0; i < 50; ++i)
        {
            vec2 pos = linearRand(vec2{0,0}, vec2{WINDOW_WIDTH, WINDOW_HEIGHT});
            float spd = 100;
            vec2 vel = linearRand(vec2{-spd,-spd}, vec2{spd, spd});
            CreateTank(pos, vel, linearRand(-360, 360));
        }
        
    }

    virtual void Update(float deltaTime) override {
    };

    void CreateTank(const vec2& pos, const vec2& vel, float aVel) {
        Entity* e = app_->GetManager<EntityManager>()->AddEntity("tank");
        e->transform_.position_ = pos;

        PhysicsComponent* pc = e->AddComponent<PhysicsComponent>();
        pc->velocity_ = vel;
        // pc->aVelocity_ = aVel;
        
        // SpriteComponent* sc = e->AddComponent<SpriteComponent>();
        // sc->SetTexture("tank");
        
        AnimationComponent* ac = e->AddComponent<AnimationComponent>();
        ac->SetTexture("chopper", 32, 32);
        ac->AddAnimation("down", vector<unsigned int>{0, 1, 6, 7});
        ac->speed_ = 500;
        ac->currentAnim_ = "down";
        ac->index_ = linearRand(0, 4);
    }
};

#endif /* MY_GAME_H */
