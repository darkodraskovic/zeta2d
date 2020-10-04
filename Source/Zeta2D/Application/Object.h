#ifndef OBJECT_H
#define OBJECT_H

#include <map>
#include <typeinfo>
#include "App.h"

namespace Zeta2D {
    class App;

    class Object {
    public:
        Object(App* app) : app_(app) {}
        template <typename T> T *GetManager() {
            TypeMap &typeMap = app_->GetTypeMap();
            return static_cast<T *>(typeMap[&typeid(T)]);
        }
        SDL_Renderer* GetRenderer() {
            return app_->renderer_;
        }

    protected:
        App* app_;
    };

}  // Zeta2D


#endif /* OBJECT_H */
