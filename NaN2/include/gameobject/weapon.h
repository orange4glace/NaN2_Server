// weapon.h
#ifndef WEAPON_H_
#define WEAPON_H_

#include "game_object.h"

#include <nan2/math/vector2.h>

namespace nan2 {

  class Weapon : public GameObject {

  private:

  protected:
    Vector2 position_;

  public:
    Weapon();

    virtual void Update() {};

    virtual void Fire1() {};
    virtual void Fire2() {};

    void set_position(const Vector2& val);
    const Vector2& position() const;

  };

}

#endif