#ifndef MANAGER_H
#define MANAGER_H

#include "App.h"

namespace Zeta2D {

    class Manager {
    protected:
        App* app_;

        friend class App;
    };
    
}  // Zeta2D

#endif /* MANAGER_H */
