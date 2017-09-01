// projectile_weapon.cpp
#include "gameobject/weapon/projectile_weapon.h"

#include "gameobject/character/character.h"
#include "world/player.h"

#include <utility>

namespace nan2 {

  ProjectileWeapon::ProjectileWeapon(Character* character, Projectile& projectile,
    int cooldown, int magazine, int ammo, const Vector2& fire_point) :
  Weapon(character),
  projectile_(projectile),
  fire_point_(fire_point) {

  }

  void ProjectileWeapon::Update() {

  }

  bool ProjectileWeapon::Fire1() {
    Projectile* projectile = new Projectile(projectile_);
    Vector2 offset = MathHelper::instance().RotateVector252(fire_point_, MathHelper::instance().biased_direction(dir_));
    offset.set_x(offset.x() * MathHelper::instance().is_right_direction(dir_));
    Vector2 fire_point = position_ + offset;
    projectile->set_position(fire_point);
    projectile->set_dir(dir_);
    projectile->set_rewind_time(character_->player()->GetRecentPing());
    World::instance()->AddGameObject(projectile);
    return true;
  }

  Vector2 ProjectileWeapon::CalculateCharacterWeaponPivot() const {
    int bdir = MathHelper::instance().biased_direction(dir_);
    Vector2 t(0 * MathHelper::instance().is_right_direction(dir_), 8);
    Vector2 ret(0, -2);
    if (!MathHelper::instance().is_upper_direction(bdir))
      ret += (t * (float)-(bdir - 190 - 63) / 63);
    return ret;
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