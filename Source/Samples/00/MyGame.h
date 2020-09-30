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

using namespace glm;
using namespace Zeta2D;

class MyGame : public Game {
public:
    virtual void Init() override {
        string textureFilePath = "../assets/images/tank-big-right.png";
        App::assetManager_->AddTexture("tank-big-right", textureFilePath.c_str());
        
        for (int i = 0; i < 4; ++i)
        {
            Entity& e = GetApp().GetManager().AddEntity("tank");
            TransformComponent& tc = e.AddComponent<TransformComponent>();
            tc.size_ = {64, 64};
            tc.position_ = linearRand(vec2{0,0}, vec2{WINDOW_WIDTH, WINDOW_HEIGHT});
            tc.velocity_ = linearRand(vec2{-30,-30}, vec2{30, 30});
            SpriteComponent& sc = e.AddComponent<SpriteComponent>("tank-big-right");
        }
        // for (int i = 0; i < 1000; ++i)
        // {
        //     Entity& e = GetApp().GetManager().AddEntity("zzz");
        //     TransformComponent& tc = e.AddComponent<TransformComponent>();
        //     tc.position_ = linearRand(vec2{0,0}, vec2{WINDOW_WIDTH, WINDOW_HEIGHT});
        //     tc.velocity_ = linearRand(vec2{-30,-30}, vec2{30, 30});
        // }
    }
    
    virtual void Update(float deltaTime) override {

    };
};

#endif /* MY_GAME_H */
