// weapon.h
#ifndef WEAPON_H_
#define WEAPON_H_

#include "../game_object.h"
#include "../../network/weapon_fire_snapshot.h"

#include <nan2/math/vector2.h>

namespace nan2 {

  class Character;

  class Weapon : public GameObject {

  private:

  protected:
    Character* character_;

    int dir_;
    Vector2 position_;

    std::vector<WeaponFireSnapshot> fire_snapshots_;

  public:
    Weapon(Character* character);

    virtual void Update() {};

    virtual bool Fire1();
    virtual bool Fire2();

    virtual Vector2 CalculateCharacterWeaponPivot() const = 0;
	Vector2 GetFirePoint() const;

    void set_position(const Vector2& val);
    const Vector2& position() const;

    int dir() const;
    void set_dir(int val);

  };

}

#endif