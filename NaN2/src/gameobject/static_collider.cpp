// static_collider.cpp
#include "gameobject/static_collider.h"

namespace nan2 {

  StaticCollider::StaticCollider(const Vector2& position, const Vector2& size) : 
  GameObject(GameObjectType::Weapon, false, false, false),
  placeable_(this, position, size) {
    placeable_.AddLayer(Layer::StaticCollider);

    AddComponent(&placeable_);
  }

}