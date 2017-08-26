// weapon_component.cpp
#include "components/weapon_component.h"

namespace nan2 {

  WeaponComponent::WeaponComponent(GameObject* game_object) :
    Component(game_object) {
  }

  int WeaponComponent::dir() const {
    return dir_;
  }

  void WeaponComponent::set_dir(int val) {
    dir_ = val;
  }

}