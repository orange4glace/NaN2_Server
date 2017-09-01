// movable.tpp

#include "math_helper.h"
#include "world/world.h"

#include "logger/logger.h"

namespace nan2 {

  inline Movable::Movable(GameObject* game_object) :
  Component(game_object) {
  }

  inline ComponentType Movable::component_type() {
    return ComponentType::Movable;
  }

  inline void Movable::Awake() {
    placeable_ = game_object_->GetComponent<Placeable>();
  }

  inline void Movable::set_position(const Vector2& val) {
    placeable_->set_position(val);
  }

  inline const Vector2& Movable::position() const {
    return placeable_->position();
  }

  template <typename Lambda1, typename Lambda2>
  void Movable::DiscreteMove252(int dir, float dd, Lambda1&& condition, Lambda2&& collisionCallback, int simulation_time) {
    Vector2 dv = MathHelper::instance().normal_dir_252(dir) * dd;
    DiscreteMove(dv.x(), dv.y(), condition, collisionCallback, simulation_time);
  }

  template <typename Lambda1, typename Lambda2>
  void Movable::DiscreteMove(float x, float y, Lambda1&& condition, Lambda2&& collisionCallback, int simulation_time) {
    placeable_->set_position(placeable_->position() + Vector2(x, y));
    World* world = World::instance();
    world->IterateGameObjects([&](GameObject* go)-> bool {
      if (go == game_object_) return true;
      Placeable* t_placeable = go->GetComponent<Placeable>();
      if (t_placeable == nullptr) return true;
      if (!placeable_->HasTargetLayers(t_placeable->layermask())) return true;

      if (go->rewindable() && simulation_time >= 0)
        go->Rewind(simulation_time);

      if (!condition(go)) {
        if (go->rewindable() && simulation_time >= 0)
          go->Restore();
        return true;
      }

      bool collided;
      Vector2 dv = AABB::SimpleAABB(placeable_->aabb(), t_placeable->aabb(), collided);
      placeable_->set_position(placeable_->position() + dv);

      if (go->rewindable() && simulation_time >= 0)
        go->Restore();
      if (!collided) return true;

      return collisionCallback(go);
    });
  }

  template <typename Lambda1, typename Lambda2>
  void Movable::ContinuousMove252(int dir, float dist, Lambda1&& condition, Lambda2&& collisionCallback, int simulation_time) {
    Vector2 dv = MathHelper::instance().normal_dir_252(dir) * dist;
    ContinuousMove(dv.x(), dv.y(), condition, collisionCallback, simulation_time);
  }

  template <typename Lambda1, typename Lambda2>
  void Movable::ContinuousMove(float x, float y, Lambda1&& condition, Lambda2&& collisionCallback, int simulation_time) {
    Vector2 dd(x, y);
    World* world = World::instance();
    GameObject* coll_go = nullptr;
    Vector2 collision_point(0, 0);
    world->IterateGameObjects([&](GameObject* go) -> bool {
      if (go == game_object_) return true;
      Placeable* t_placeable = go->GetComponent<Placeable>();
      if (t_placeable == nullptr) return true;

      if (!placeable_->HasTargetLayers(t_placeable->layermask())) return true;

      if (go->rewindable() && simulation_time >= 0) {
        go->Rewind(simulation_time);
      }

      if (!condition(go)) {
        if (go->rewindable() && simulation_time >= 0) {
          go->Restore();
        }
        return true;
      }

      bool collided;
      float r = AABB::SweptAABB(placeable_->aabb(), dd, t_placeable->aabb(), Vector2::ZERO, collided);
      if (collided) {
        dd *= r;
        coll_go = go;
      }
      if (go->rewindable() && simulation_time >= 0) {
        go->Restore();
      }
      return true;
    });
    placeable_->set_position(placeable_->position() + dd);
    if (coll_go != nullptr) {
      collisionCallback(coll_go, collision_point);
    }
  }

}