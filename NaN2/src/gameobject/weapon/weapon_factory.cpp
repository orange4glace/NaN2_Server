// weapon_factory.cpp
#include "gameobject/weapon/weapon_factory.h"

namespace nan2 {

  ProjectileWeapon* WeaponFactory::CreateProjectileWeapon(Character* character) {
    Projectile projectile(Vector2(0, 0), Vector2(0, 0), 0, 30.f, 10);
    ProjectileWeapon* weapon = new ProjectileWeapon(character, projectile, 30, 30, 30, Vector2(22, 4));
    return weapon;
  }

}