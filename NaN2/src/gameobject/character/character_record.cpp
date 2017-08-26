// character_record.cpp
#include "gameobject/character/character_record.h"

namespace nan2 {

  CharacterRecord CharacterRecord::Interpolate(const CharacterRecord& a, const CharacterRecord& b, float t) {
    auto dv = b.position - a.position;
    return{
      a.hp,
      a.position + dv * t
    };
  }

}