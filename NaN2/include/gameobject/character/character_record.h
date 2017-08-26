// character_record.h
#ifndef CHARACTER_RECORD_H_
#define CHARACTER_RECORD_H_

#include <nan2/math/vector2.h>

namespace nan2 {

  struct CharacterRecord {
    int hp;
    Vector2 position;

    static CharacterRecord Interpolate(const CharacterRecord& a, const CharacterRecord& b, float t);
  };

}

#endif