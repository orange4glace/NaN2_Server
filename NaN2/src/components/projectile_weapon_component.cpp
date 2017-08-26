// projectile_weapon_component.cpp
#include "components/projectile_weapon_component.h"

namespace nan2 {

  ProjectileWeaponComponent::ProjectileWeaponComponent(GameObject* game_object, Projectile& projectile,
    int cooldown, int magazine, int ammo) :
  Component(game_object),
  projectile_(projectile),
  cooldown_(cooldown),
  magazine_(magazine),
  ammo_(ammo) {
  }

  ComponentType ProjectileWeaponComponent::type() const {
    return ComponentType::ProjectileWeapon;
  }

  void ProjectileWeaponComponent::Fire(const Vector2& position, int rewind_time) {
    Projectile* projectile = new Projectile(projectile_);
    projectile->set_position(position);
    projectile->set_dir(dir_);
    World::instance()->AddGameObject(projectile);
  }

  void ProjectileWeaponComponent::Update() {
    
  }

  void ProjectileWeaponComponent::set_cooldown(int val) {
    cooldown_ = val;
  }

  void ProjectileWeaponComponent::set_magazine(int val) {
    magazine_ = val;
  }

  void ProjectileWeaponComponent::set_ammo(int val) {
    ammo_ = val;
  }

  void ProjectileWeaponComponent::set_dir(int val) {
    dir_ = val;
  }

  int ProjectileWeaponComponent::cooldown() const {
    return cooldown_;
  }

  int ProjectileWeaponComponent::magazine() const {
    return magazine_;
  }

  int ProjectileWeaponComponent::ammo() const {
    return ammo_;
  }

  int ProjectileWeaponComponent::dir() const {
    return dir_;
  }

}