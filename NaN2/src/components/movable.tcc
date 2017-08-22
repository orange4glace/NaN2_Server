// movable.tpp

#include "math_helper.h"
#include "world/world.h"

#include "logger/logger.h"

namespace nan2 {

  inline Movable::Movable(GameObject* game_object) :
  Component(game_object) {
  }

  inline ComponentType Movable::type() const {
    return ComponentType::Movable;
  }

  inline void Movable::Awake() {
    placeable_ = static_cast<Placeable*>(game_object_->GetComponent(ComponentType::Placeable));
  }

  inline void Movable::set_position(const Vector2& val) {
    placeable_->set_position(val);
  }

  inline const Vector2& Movable::position() const {
    return placeable_->position();
  }

  template <typename Lambda1, typename Lambda2>
  void Movable::DiscreteMove252(int dir, int mdt, Lambda1&& condition, Lambda2&& collisionCallback) {
    float fdt = (float)mdt / 1000.0f;
    Vector2 dv = MathHelper::instance().normal_dir_252(dir);
    DiscreteMove(dv.x(), dv.y(), condition, collisionCallback);
  }

  template <typename Lambda1, typename Lambda2>
  void Movable::DiscreteMove(float x, float y, Lambda1&& condition, Lambda2&& collisionCallback) {
    placeable_->set_position(placeable_->position() + Vector2(x, y));

    World* world = World::instance();
    world->IterateGameObjects([&](GameObject* go)-> bool {
      if (go == game_object_) return true;
      Placeable* t_placeable = static_cast<Placeable*>(go->GetComponent(ComponentType::Placeable));
      if (t_placeable == nullptr) return true;

      if (!placeable_->HasTargetLayers(t_placeable->layermask())) return true;

      if (!condition(go)) return true;

      bool collided;
      Vector2 dv = AABB::SimpleAABB(placeable_->aabb(), t_placeable->aabb(), collided);
      placeable_->set_position(placeable_->position() + dv);
      if (!collided) return true;

      return collisionCallback(go);
    });
  }

  template <typename Lambda1, typename Lambda2>
  void Movable::ContinuousMove252(int dir, float dist, Lambda1&& condition, Lambda2&& collisionCallback) {
    Vector2 dv = MathHelper::instance().normal_dir_252(dir) * dist;
    ContinuousMove(dv.x(), dv.y(), condition, collisionCallback);
  }

  template <typename Lambda1, typename Lambda2>
  void Movable::ContinuousMove(float x, float y, Lambda1&& condition, Lambda2&& collisionCallback) {
    Vector2 dd(x, y);
    L_DEBUG << "cnt " << dd << " " << placeable_->position();
    World* world = World::instance();
    GameObject* coll_go = nullptr;
    Vector2 collision_point(0, 0);
    world->IterateGameObjects([&](GameObject* go) -> bool {
      if (go == game_object_) return true;
      Placeable* t_placeable = static_cast<Placeable*>(go->GetComponent(ComponentType::Placeable));
      if (t_placeable == nullptr) return true;

      if (!placeable_->HasTargetLayers(t_placeable->layermask())) return true;

      if (!condition(go)) return true;

      bool collided;
      float r = AABB::SweptAABB(placeable_->aabb(), dd, t_placeable->aabb(), Vector2::ZERO, collided);
      if (collided) {
        dd *= r;
        coll_go = go;
      }
      return true;
    });
    L_DEBUG << "aft " << dd;
    placeable_->set_position(placeable_->position() + dd);
    if (coll_go != nullptr) {
      collisionCallback(coll_go, collision_point);
    }
  }

}


/*

// movable.h
#ifndef MOVABLE_H_
#define MOVABLE_H_

#include "placable.h"

#include <functional>

// [Require Component (Placeable)]
namespace nan2 {

  class Movable : Component {

  private:
    Placable* placable_;

  public:

    ComponentType type() const;

    void Move252(int dir);
    void MoveTo(const Vector2& position);
    void MoveTo(float x, float y);

    // Condition check function
    // bool Lambda1(GameObject* game_object)
    // Collision callback function
    // bool Lambda1(GameObject* game_object)
    template <typename Lambda1, typename Lambada2>
    void DiscreteMove252(int dir, int dt, Lambda1&& condition, Lambda2&& collisionCallback);
    template <typename Lambda1, typename Lambada2>
    void DiscreteMove(float x, float y, Lambda1&& condition, Lambda2&& collisionCallback);

  };
}

#include "placeable.tpp"

#endif

*/