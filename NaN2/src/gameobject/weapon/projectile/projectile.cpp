// projectile.cpp
#include "gameobject/weapon/projectile/projectile.h"

#include "components/living.h"

#include "world_time.h"

namespace nan2 {

  Projectile::Projectile(const Vector2& position, const Vector2& size,
    int dir, float speed, int damage) : 
  GameObject(GameObjectType::Projectile, true, false, false),
  placeable_(this, position, size),
  movable_(this),
  dir_(dir),
  speed_(speed), 
  alive_time_(0),
  damage_(damage) {
    placeable_.AddTargetLayer(Layer::STATIC_COLLIDER);
    placeable_.AddTargetLayer(Layer::CHARACTER);

    AddComponent(&placeable_);
    AddComponent(&movable_);
  }

  Projectile::Projectile(const Projectile& copying) :
  Projectile(copying.placeable_.position(), copying.placeable_.size(),
    copying.dir_, copying.speed_, copying.damage_) {
  }

  void Projectile::Update() {
    alive_time_ += Time::delta_time();
    if (alive_time_ > 10 * 1000) {
      World::instance()->RemoveGameObject(this);
      return;
    }
    return;
    movable_.ContinuousMove252(dir_, Time::f_delta_time() * speed_,
      [&](GameObject* go)-> bool {
      return true;
    },
      [&](GameObject* go, Vector2 collision_point)-> bool {
      Living* living = go->GetComponent<Living>();
      if (living != nullptr) {
        living->Subtract(damage_);
      }
      return true;
    });
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
    dir_ = val;
  }

  int Projectile::dir() const {
    return dir_;
  }

  void Projectile::set_rewind_time(int val) {
    rewind_time_ = val;
  }

  int Projectile::rewind_time() const {
    return rewind_time_;
  }

}