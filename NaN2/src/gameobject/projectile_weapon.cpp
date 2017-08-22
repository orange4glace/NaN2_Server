// projectile_weapon.cpp
#include "gameobject/projectile_weapon.h"

#include <utility>

namespace nan2 {

  ProjectileWeapon::ProjectileWeapon(int cooldown, int magazine, int ammo, Projectile projectile) : 
  Weapon(),
  projectile_weapon_component_(this, projectile, cooldown, magazine, ammo) {

    AddComponent(&projectile_weapon_component_);
  }

  void ProjectileWeapon::Update() {

  }

  void ProjectileWeapon::Fire1() {
    projectile_weapon_component_.Fire(position_);
  }

}