// projectile.h
#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "../../game_object.h"

#include "../../../components/movable.h"

namespace nan2 {

  class Projectile : public GameObject {

  private:
    Placeable placeable_;
    Movable movable_;

    int dir_;
    int speed_;
    int damage_;
    int alive_time_;

    int player_id_;

    int rewind_time_;

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

    void set_rewind_time(int val);
    int rewind_time() const;

  };

}

#endif