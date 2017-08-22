// projectile_component.cpp
#include "components/projectile_component.h"

#include "components/living.h"

namespace nan2 {

  ProjectileComponent::ProjectileComponent(GameObject* game_object) :
  Component(game_object) {
  }

  ComponentType ProjectileComponent::type() const {
    return ComponentType::Projectile;
  }

  void ProjectileComponent::Awake() {
    movable_ = static_cast<Movable*>(game_object_->GetComponent(ComponentType::Movable));
  }

  void ProjectileComponent::Update() {
    int dt;
    L_DEBUG << "[Projectile] " << movable_->position();
    movable_->ContinuousMove252(dir_, 33 * speed_,
      [&](GameObject* go)-> bool {
        return true;
      },
      [&](GameObject* go, Vector2 collision_point)-> bool {
        Living* living = static_cast<Living*>(go->GetComponent(ComponentType::Living));
        if (living != nullptr) {
          living->Subtract(damage_);
        }
        return true;
      });
  }

  void ProjectileComponent::set_dir(int val) {
    dir_ = val;
  }

  int ProjectileComponent::dir() const {
    return dir_;
  }

  void ProjectileComponent::set_speed(float val) {
    L_DEBUG << "ss " << val;
    speed_ = val;
  }

  float ProjectileComponent::speed() const {
    return speed_;
  }

  void ProjectileComponent::set_damage(int val) {
    damage_ = val;
  }

  int ProjectileComponent::damage() const {
    return damage_;
  }

}