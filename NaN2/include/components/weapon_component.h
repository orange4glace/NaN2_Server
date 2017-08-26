// weapon_component.h
#ifndef WEAPON_COMPONENT_H_
#define WEAPON_COMPONENT_H_

#include "component.h"

#include <nan2/math/vector2.h>

namespace nan2 {

  class WeaponComponent : public Component {

  protected:
    Vector2 position_;
    int dir_;

  public:
    WeaponComponent(GameObject* go);

    virtual void Fire() = 0;

    void set_position(const Vector2& val);
    const Vector2& position() const;

    int dir() const;
    void set_dir(int val);

  };

}

#endif