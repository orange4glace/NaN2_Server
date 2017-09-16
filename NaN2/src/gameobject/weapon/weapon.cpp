// weapon.cpp
#include "gameobject/weapon/weapon.h"

#include "gameobject/character/character.h"

namespace nan2 {

  Weapon::Weapon(Character* character) : 
  GameObject(GameObjectType::Weapon, true, false, false),
  character_(character) {
  }

  bool Weapon::Fire1() {
    return false;
  }

  bool Weapon::Fire2() {
    return false;
  }

  Vector2 Weapon::GetFirePoint() const {
	  return Vector2::ZERO;
  }

  void Weapon::set_position(const Vector2& val) {
    position_ = val;
  }

  const Vector2& Weapon::position() const {
    return position_;
  }

  void Weapon::set_dir(int val) {
    dir_ = val;
  }

  int Weapon::dir() const {
    return dir_;
  }
}