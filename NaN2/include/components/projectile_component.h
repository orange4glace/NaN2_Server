// projectile_component.h
#ifndef PROJECTILE_COMPONENT_H_
#define PROJECTILE_COMPONENT_H_

#include "component.h"
#include "movable.h"

// RequireComponent(Movable)
namespace nan2 {

  class ProjectileComponent : public Component {

  private:
    Movable* movable_;

    int dir_;
    float speed_;
    int damage_;

    int rewind_time_;

  public:
    ProjectileComponent(GameObject* go);

    ComponentType type() const;

    void Awake();
    void Update();

    void set_dir(int dir);
    int dir() const;

    void set_speed(float speed);
    float speed() const;

    void set_damage(int damage);
    int damage() const;

    void set_rewind_time(int val);
    int rewind_time() const;

  };

}

#endif