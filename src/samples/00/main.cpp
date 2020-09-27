#include<iostream>

#include "zeta2d/consts.h"
#include "my_game.h"

using namespace Zeta2D;

int main(int argc, char *argv[]){
    MyGame* game = new MyGame();
    App* app = new App(game);

    app->Init(WINDOW_WIDTH, WINDOW_HEIGHT);
    app->Run();
    app->Destroy();
    
    return 0;
}
