#include<iostream>

#include "Zeta2D/Application/Consts.h"
#include "MyGame.h"

using namespace Zeta2D;

int main(int argc, char *argv[]){
    App* app = new App();

    app->Init(new MyGame(), WINDOW_WIDTH, WINDOW_HEIGHT);
    app->Run();
    app->Destroy();

    return 0;
}
