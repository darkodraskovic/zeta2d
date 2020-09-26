#include<iostream>

#include "zeta2d/consts.h"
#include "zeta2d/entity/entity.h"
#include "zeta2d/entity/entity_manager.h"
#include "zeta2d/game.h"
#include "my_game.h"

using namespace Zeta2D;

int main(int argc, char *argv[]){
    App* app = new App(new MyGame());
    app->Init(WINDOW_WIDTH, WINDOW_HEIGHT);

    // EntityManager entityManager;
    // Entity* entity = new Entity(entityManager);
    
    app->Run();
    app->Destroy();
    
    return 0;
}
