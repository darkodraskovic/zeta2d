#ifndef APP_H
#define APP_H

#include <SDL2/SDL.h>
#include "../Entity/EntityManager.h"

namespace Zeta2D {
    class EntityManager;
    class AssetManager;
    class Game;
    
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
        EntityManager& GetManager();
        
        static SDL_Renderer* renderer_;
        static AssetManager* assetManager_;
        
    private:
        EntityManager entityManager_;
        bool running_;
        SDL_Window* window_;
        Game* game_;
        int prevFrameTime;
    };

}  // Zeta2D

#endif /* APP_H */
