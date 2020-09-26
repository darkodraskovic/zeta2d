#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "game.h"

namespace Zeta2D {
    
    class App {
    public:
        App(Game* game);
        ~App();
        bool GetRunning() const;
        void Run();
        void Init(int width, int height);
        void Input();
        void Update();
        void Render();
        void Destroy();
        
    private:
        bool running_;
        SDL_Window* window_;
        SDL_Renderer* renderer_;
        Game* game_;
        int prevFrameTime;
    };

}  // Zeta2D

#endif /* APP_H */
