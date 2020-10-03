#ifndef OBJECT_H
#define OBJECT_H

#define OBJECT(DerivedClass, BaseClass)                                        \
public:                                                                        \
  DerivedClass(App *app) : BaseClass(app) {}                                   \
  template <typename T> T *GetManager() {                                      \
    TypeMap &typeMap = app_->GetTypeMap();                                     \
    return static_cast<T *>(typeMap[&typeid(T)]);                              \
  }                                                                            \

namespace Zeta2D {
    class App;
    
    class Object {
    public:
        Object(App* app) : app_(app) {}
    protected:
        App* app_;
};
    

}  // Zeta2D


#endif /* OBJECT_H */
