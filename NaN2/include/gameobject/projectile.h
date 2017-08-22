// projectile.h
#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "game_object.h"

#include "../components/projectile_component.h"
#include "../components/movable.h"

namespace nan2 {

  class Projectile : public GameObject {

  private:
    ProjectileComponent projectile_component_;
    Placeable placeable_;
    Movable movable_;

    int player_id_;

  public:
    Projectile(const Vector2& position, const Vector2& size,
      int dir, float speed, int damage);
    Projectile(const Projectile& copying);

    void Update();

    void AddTargetLayer(int layer);
    void AddTargetLayers(int layermask);

    void set_position(const Vector2& val);
    const Vector2 position() const;

    void set_dir(int val);
    int dir() const;

  };

}

#endif