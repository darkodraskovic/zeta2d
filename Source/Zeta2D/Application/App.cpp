#include <iostream>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#include "Consts.h"
#include "App.h"
#include "Game.h"
#include "../Asset/AssetManager.h"
#include "../Entity/Entity.h"
#include "../Entity/EntityManager.h"

using namespace glm;
using namespace Zeta2D;

SDL_Renderer *App::renderer_ = nullptr;


App::~App() {}

bool App::GetRunning() const { return running_; }

void App::Run() {
    while (GetRunning()) {
        Input();
        Update();
        Render();
    }
}

void App::Init(Game* game, int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "ERR init SDL" << std::endl;
        return;
    }

    window_ = SDL_CreateWindow(NULL, 0, 0, width, height, SDL_WINDOW_BORDERLESS);
    if(!window_) {
        std::cerr << "ERR init window" << std::endl;
        return;
    }

    renderer_ = SDL_CreateRenderer(window_, -1, 0); // -1 = default display
    if(!renderer_) {
        std::cerr << "ERR init renderer" << std::endl;
        return;
    }

    running_ = true;

    assetManager_ = AddManager<AssetManager>();
    entityManager_ = AddManager<EntityManager>();

    game_ = game;
    game_->Init(this);

    return;
}

void App::Input() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        running_ = false;
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE) {
            running_ = false;
        }
    default:
        break;
    }

    game_->Input(&event);
}

void App::Update() {
    int now = SDL_GetTicks();
    float elapsedTime = now - prevFrameTime;
    prevFrameTime = SDL_GetTicks();
    int waitTime = FRAME_TARGET_TIME - elapsedTime;
    if (waitTime > 0) SDL_Delay(waitTime);
    float deltaTime = elapsedTime / 1000.0f;
    deltaTime = deltaTime < DELTA_TIME_MAX ? deltaTime : DELTA_TIME_MAX;

    game_->Update(deltaTime);
    entityManager_->Update(deltaTime);
}

void App::Render() {
    SDL_SetRenderDrawColor(renderer_, 21, 21, 21, 255);
    SDL_RenderClear(renderer_);

    game_->Render();
    entityManager_->Render();

    SDL_RenderPresent(renderer_);
}

void App::Destroy() {
    game_->Destroy();

    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}
