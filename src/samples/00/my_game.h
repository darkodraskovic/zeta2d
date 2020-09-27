#ifndef MY_GAME_H
#define MY_GAME_H

#include "zeta2d/game.h"
#include "zeta2d/entity/entity.h"
#include "zeta2d/entity/transform_component.h"

using namespace glm;
using namespace Zeta2D;

class MyGame : public Game {
public:
    virtual void Init() override {
        Entity& e = GetApp().GetManager().AddEntity("zzz");
        TransformComponent& tc = e.AddComponent<TransformComponent>();
        tc.velocity_ = {100, 50};
    }
    
    virtual void Update(float deltaTime) override {

    };
};

#endif /* MY_GAME_H */
