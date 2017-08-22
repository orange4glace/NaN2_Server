// weapon_factory.cpp
#include "gameobject/weapon_factory.h"

namespace nan2 {

  ProjectileWeapon* WeaponFactory::CreateProjectileWeapon() {
    Projectile projectile(Vector2(0, 0), Vector2(0, 0), 0, 30.f, 10);
    ProjectileWeapon* weapon = new ProjectileWeapon(30, 30, 30, projectile);
    return weapon;
  }

}