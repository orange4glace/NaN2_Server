// projectile_weapon.h
#ifndef PROJECTILE_WEAPON_H_
#define PROJECTILE_WEAPON_H_

#include "weapon.h"

#include "projectile/projectile.h"

namespace nan2 {

  class Character;

  class ProjectileWeapon : public Weapon {

  protected:
    Vector2 fire_point_;

    Projectile projectile_;

    int cooldown_;
    int magazine_;
    int ammo_;

  public:
    ProjectileWeapon(Character* character, Projectile& projectile,
      int cooldown, int magazine, int ammo, const Vector2& fire_point);

    void Update() override;

    bool Fire1() override;

    Vector2 CalculateCharacterWeaponPivot() const override;

    void set_cooldown(int val);
    void set_magazine(int val);
    void set_ammo(int val);

    int cooldown() const;
    int magazine() const;
    int ammo() const;

  };

}

#endif