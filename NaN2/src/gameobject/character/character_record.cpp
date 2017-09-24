// character_record.cpp
#include "gameobject/character/character_record.h"

#include "logger/logger.h"

namespace nan2 {

  CharacterRecord CharacterRecord::Interpolate(const CharacterRecord& a, const CharacterRecord& b, float t) {
    auto dv = b.position - a.position;
    L_DEBUG << "Interpolate " << t << endl << a << endl << b;
    return{
      a.hp,
      a.position + dv * t
    };
  }

  std::ostream& operator<<(std::ostream& os, const CharacterRecord& record) {
    os << "CharacterRecord(" << record.position << ", " << record.hp << ") ";
    return os;
  }
}