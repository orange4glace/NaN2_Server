// projectile_weapon.h
#ifndef PROJECTILE_WEAPON_H_
#define PROJECTILE_WEAPON_H_

#include "weapon.h"
#include "projectile.h"
#include "../components/projectile_weapon_component.h"

namespace nan2 {

  class ProjectileWeapon : public Weapon {

  private:
    ProjectileWeaponComponent projectile_weapon_component_;

  public:
    ProjectileWeapon(int cooldown, int magazine, int ammo, Projectile projectile);

    void Update() override;

    void Fire1() override;

  };

}

#endif