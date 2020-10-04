#ifndef MANAGER_H
#define MANAGER_H

#include "Object.h"

namespace Zeta2D  {
    
    class Manager : public Object {
    public:
        Manager(App* app) : Object(app) {};
    };
    
}  // Zeta2D

#endif /* MANAGER_H */
