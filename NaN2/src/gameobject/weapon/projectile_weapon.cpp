// projectile_weapon.cpp
#include "gameobject/weapon/projectile_weapon.h"

#include "gameobject/character/character.h"
#include "world/player.h"

#include <utility>

namespace nan2 {

  ProjectileWeapon::ProjectileWeapon(Character* character, Projectile& projectile,
    int cooldown, int magazine, int ammo) :
  Weapon(character),
  projectile_(projectile) {

  }

  void ProjectileWeapon::Update() {

  }

  void ProjectileWeapon::Fire1() {
    Projectile* projectile = new Projectile(projectile_);
    projectile->set_position(position_);
    projectile->set_dir(dir_);
    World::instance()->AddGameObject(projectile);
  }

  void ProjectileWeapon::set_cooldown(int val) {
    cooldown_ = val;
  }

  void ProjectileWeapon::set_magazine(int val) {
    magazine_ = val;
  }

  void ProjectileWeapon::set_ammo(int val) {
    ammo_ = val;
  }

  int ProjectileWeapon::cooldown() const {
    return cooldown_;
  }

  int ProjectileWeapon::magazine() const {
    return magazine_;
  }

  int ProjectileWeapon::ammo() const {
    return ammo_;
  }

}