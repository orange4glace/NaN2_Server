// game_object_type.h
#ifndef GAME_OBJECT_TYPE_H_
#define GAME_OBJECT_TYPE_H_

#include <iostream>
#include <type_traits>

namespace nan2 {

  enum class GameObjectType {
    Character,
    StaticCollider,
    Weapon,
    Projectile
  };

  inline std::ostream& operator << (std::ostream& os, const GameObjectType& obj)
  {
     os << static_cast<std::underlying_type<GameObjectType>::type>(obj);
     return os;
  }

}

#endif