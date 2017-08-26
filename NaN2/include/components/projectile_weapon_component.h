// projectile_weapon_component.h
#ifndef PROJECTILE_WEAPON_COMPONENT_H_
#define PROJECTILE_WEAPON_COMPONENT_H_

#include "component.h"

#include "weapon_component.h"
#include "../gameobject/projectile.h"

#include <nan2/math/vector2.h>

namespace nan2 {

  class ProjectileWeaponComponent : public WeaponComponent {

  private:
    int dir_;
    Vector2 firing_point_;
    
    Projectile projectile_;

    int cooldown_;
    int magazine_;
    int ammo_;

  public:
    ProjectileWeaponComponent(GameObject* go, Projectile& projectile, int cooldown, int magazine, int ammo);

    ComponentType type() const;

    void Fire(const Vector2& position, int rewind_time);
    
    void Update();

    void set_cooldown(int val);
    void set_magazine(int val);
    void set_ammo(int val);

    int cooldown() const;
    int magazine() const;
    int ammo() const;

    void set_dir(int val);
    int dir() const;

  };

}

#endif