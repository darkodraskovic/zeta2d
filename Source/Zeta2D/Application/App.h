#ifndef APP_H
#define APP_H

#include <map>
#include <typeinfo>
#include <SDL2/SDL.h>

using namespace std;

namespace Zeta2D {
    class Manager;
    class EntityManager;
    class AssetManager;
    class Game;
        
    class App {
    public:
        App() {};
        ~App();
        bool GetRunning() const;
        void Run();
        void Init(Game* game, int width, int height);
        void Input();
        void Update();
        void Render();
        void Destroy();

        template <typename T>
        T* AddManager() {
            T* manager(new T());
            manager->app_ = this;
            typeMap_[&typeid(T)] = manager;
            return manager;
        }
        
        template <typename T>
        T* GetManager() {
            return static_cast<T*>(typeMap_[&typeid(T)]);
        }
        
        static SDL_Renderer* renderer_;
        
    private:
        AssetManager* assetManager_;
        EntityManager* entityManager_;
        
        map<const type_info*, Manager*> typeMap_;
        bool running_ = false;
        SDL_Window* window_;
        Game* game_;
        int prevFrameTime;
    };

}  // Zeta2D

#endif /* APP_H */
