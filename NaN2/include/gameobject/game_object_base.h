// game_object_base.h
#ifndef GAME_OBJECT_BASE_H_
#define GAME_OBJECT_BASE_H_

#include "components/component.h"

namespace nan2 {

  class GameObjectBase {

    virtual void addComponent(Component* component) = 0;
    virtual Component* getComponent(ComponentType type) = 0;

  public:

    template<class T>
    void AddComponent(T* component);

    template<class T>
    T* GetComponent();

  };

  template<class T>
  void GameObjectBase::AddComponent(T* component) {
    addComponent(static_cast<Component*>(component));
  }

  template<class T>
  T* GameObjectBase::GetComponent() {
    return static_cast<T*>(getComponent(T::component_type()));
  }

}

#endif