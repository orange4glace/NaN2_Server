// weapon.cpp
#include "gameobject/weapon.h"

namespace nan2 {

  Weapon::Weapon() : 
  GameObject(GameObjectType::Weapon, true, false, false) {
  }

  void Weapon::set_position(const Vector2& val) {
    position_ = val;
  }

  const Vector2& Weapon::position() const {
    return position_;
  }
}