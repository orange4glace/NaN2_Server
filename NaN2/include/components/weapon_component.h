// weapon_component.h
#ifndef WEAPON_COMPONENT_H_
#define WEAPON_COMPONENT_H_

#include "component.h"

namespace nan2 {

  class WeaponComponent : public Component {

  private:

  public:
    WeaponComponent(GameObject* go);

    ComponentType type() const;

    virtual void Fire();

  };

}

#endif