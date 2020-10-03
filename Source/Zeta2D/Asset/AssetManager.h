#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <string>

#include "../Application/App.h"
#include "../Application/Manager.h"

using namespace std;

namespace Zeta2D {

    class AssetManager : public Manager {
        CONTEXT(AssetManager)
    public:
        void Clear();
        void AddTexture(string id, const char* fileName);
        SDL_Texture* GetTexture(string id);

    private:
        SDL_Texture* LoadTexture(const char* fileName);
        map<string, SDL_Texture*> textures_;
    };

}  // Zeta2D

#endif /* ASSETMANAGER_H */
