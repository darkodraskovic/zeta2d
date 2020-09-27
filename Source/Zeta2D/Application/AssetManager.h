#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <string>
#include "../Entity/EntityManager.h"

using namespace std;

namespace Zeta2D {

    class AssetManager {
    public:
        AssetManager(EntityManager* manager_);
        ~AssetManager();
        void Clear();
        
    private:
        EntityManager* entityManager_;
        map<string, SDL_Texture*> textures;
    };

}  // Zeta2D

#endif /* ASSETMANAGER_H */
