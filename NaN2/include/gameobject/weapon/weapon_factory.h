// weapon_factory.h
#ifndef WEAPON_FACTORY_H_
#define WEAPON_FACTORY_H_

#include "projectile/projectile.h"
#include "projectile_weapon.h"

namespace nan2 {

  class WeaponFactory {

  public:

    static ProjectileWeapon* CreateProjectileWeapon(Character* character);

  };

}

#endif