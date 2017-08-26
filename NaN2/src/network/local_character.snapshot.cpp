// local_character_snapshot.cpp
#include "network/local_character_snapshot.h"

namespace Proud {
  using namespace nan2;

  // Not used
  CMessage& operator >> (CMessage& a, LocalCharacterSnapshot& packet) {
    return a;
  }

  CMessage& operator << (CMessage& a, const LocalCharacterSnapshot& packet) {
    a << packet.last_acked_input_sequence_ << packet.pos_x << packet.pos_y << packet.hp;
    return a;
  }

  void AppendTextOut(String& str, const LocalCharacterSnapshot& packet) {
    String f;
    f.Format(L"{move_dir=%u, fire_dir=%u}", packet.pos_x, packet.pos_y, packet.hp);
    str += f;
  }
}