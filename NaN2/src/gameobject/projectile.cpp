// projectile.cpp
#include "gameobject/projectile.h"

namespace nan2 {

  Projectile::Projectile(const Vector2& position, const Vector2& size,
    int dir, float speed, int damage) : 
  GameObject(GameObjectType::Projectile, true, true, false),
  placeable_(this, position, size),
  movable_(this),
  projectile_component_(this) {

    projectile_component_.set_dir(dir);
    projectile_component_.set_speed(speed);
    projectile_component_.set_damage(damage);

    placeable_.AddTargetLayer(Layer::StaticCollider);

    AddComponent(&placeable_);
    AddComponent(&movable_);
    AddComponent(&projectile_component_);
  }

  Projectile::Projectile(const Projectile& copying) :
  Projectile(copying.placeable_.position(), copying.placeable_.size(),
    copying.projectile_component_.dir(), copying.projectile_component_.speed(), copying.projectile_component_.damage()) {
  }

  void Projectile::Update() {
    projectile_component_.Update();
  }

  void Projectile::AddTargetLayer(int layer) {
    placeable_.AddTargetLayer(layer);
  }

  void Projectile::AddTargetLayers(int layermask) {
    placeable_.AddTargetLayers(layermask);
  }

  void Projectile::set_position(const Vector2& val) {
    placeable_.set_position(val);
  }

  const Vector2 Projectile::position() const {
    return placeable_.position();
  }

  void Projectile::set_dir(int val) {
    projectile_component_.set_dir(val);
  }

  int Projectile::dir() const {
    return projectile_component_.dir();
  }

}