// component.h
#ifndef COMPONENT_H_
#define COMPONENT_H_

#include "component_type.h"

namespace nan2 {

  // Forward declaration
  class GameObject;

  class Component {

  protected:
    GameObject* game_object_;

  public:
    Component(GameObject* game_object);

    // You should define this static function if a Component class is not abstract
    // static ComponentType type();
    virtual ComponentType type() const = 0;
    virtual void Awake() {};
    virtual void Start() {};
    virtual void OnDestroy() {};

    GameObject* game_object() const;

  };

}

#endif