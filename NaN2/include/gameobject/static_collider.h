// static_collider.h
#ifndef STATIC_COLLIDER_H_
#define STATIC_COLLIDER_H_

#include "game_object.h"
#include "../components/placeable.h"

namespace nan2 {

  class StaticCollider : public GameObject {

  private:
    Placeable placeable_;

  public:
    StaticCollider(const Vector2& position, const Vector2& size);

  };

}

#endif