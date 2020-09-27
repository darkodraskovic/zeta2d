#include<iostream>

#include "Zeta2D/Application/Consts.h"
#include "MyGame.h"

using namespace Zeta2D;

int main(int argc, char *argv[]){
    MyGame* game = new MyGame();
    App* app = new App(game);

    app->Init(WINDOW_WIDTH, WINDOW_HEIGHT);
    app->Run();
    app->Destroy();
    
    return 0;
}
