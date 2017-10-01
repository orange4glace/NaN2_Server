// Placeable.cpp
#include "components/placeable.h"

namespace nan2 {

  Placeable::Placeable(GameObject* game_object, const Vector2& position, const Vector2& size, const Vector2& offset) :
  Component(game_object),
  position_(position),
  aabb_(position, size),
  offset_(offset),
  layermask_(0),
  target_layermask_(0) {
  }

  ComponentType Placeable::component_type() {
    return ComponentType::Placeable;
  }

  void Placeable::set_position(const Vector2& position) {
    position_ = position;
    aabb_.set_center(position + offset_);
  }

  void Placeable::set_position(float x, float y) {
    position_ = Vector2(x, y);
    aabb_.set_center(Vector2(x, y) + offset_);
  }

  const Vector2& Placeable::position() const {
    return position_;
  }

  void Placeable::set_size(const Vector2& val) {
    aabb_.set_size(val);
  }

  const Vector2& Placeable::size() const {
    return aabb_.size();
  }

  int Placeable::layermask() const {
    return layermask_;
  }

  int Placeable::target_layermask() const {
    return target_layermask_;
  }

  void Placeable::AddLayer(int layer) {
    layermask_ |= (1 << layer);
  }

  void Placeable::AddLayers(int layermask) {
    layermask_ |= layermask;
  }

  bool Placeable::HasLayer(int layer) {
    return ((layermask_ & (1 << layer)) > 0);
  }

  bool Placeable::HasLayers(int layermask) {
    return ((layermask_ & layermask) > 0);
  }

  void Placeable::AddTargetLayer(int layer) {
    target_layermask_ |= (1 << layer);
  }

  void Placeable::AddTargetLayers(int layermask) {
    target_layermask_ |= layermask;
  }

  bool Placeable::HasTargetLayer(int layer) {
    return ((target_layermask_ & (1 << layer)) > 0);
  }

  bool Placeable::HasTargetLayers(int layermask) {
    return ((target_layermask_ & layermask) > 0);
  }

  bool Placeable::Intersect(Placeable* const other) const {
    bool collided;
    AABB::SimpleAABB(aabb_, other->aabb_, collided);
    return collided;
  }

  bool Placeable::Contain(const Vector2& point) const {
    return aabb_.ContainsPoint(point);
  }

  const AABB& Placeable::aabb() const {
    return aabb_;
  }

}