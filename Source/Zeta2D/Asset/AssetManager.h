#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <string>

#include "../Application/App.h"
#include "../Application/Manager.h"
#include "../Graphics/Texture.h"

using namespace std;

namespace Zeta2D {

    class AssetManager : public Manager {
    public:
        AssetManager(App* app) : Manager(app) {};
        void Clear();
        void AddTexture(string id, const char* fileName);
        Texture* GetTexture(string id);

    private:
        Texture* LoadTexture(const char* fileName);
        map<string, Texture*> textures_;
    };

}  // Zeta2D

#endif /* ASSETMANAGER_H */
