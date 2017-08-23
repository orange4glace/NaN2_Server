// remote_character_snapshot.cpp
#include "network/remote_character_snapshot.h"

namespace Proud {
  using namespace nan2;

  // Not used
  CMessage& operator >> (CMessage& a, RemoteCharacterSnapshot& packet) {
    return a;
  }

  CMessage& operator << (CMessage& a, const RemoteCharacterSnapshot& packet) {
    a << packet.pos_x << packet.pos_y << packet.hp;
    return a;
  }

  void AppendTextOut(String& str, const RemoteCharacterSnapshot& packet) {
    String f;
    f.Format(L"{move_dir=%u, fire_dir=%u}", packet.pos_x, packet.pos_y, packet.hp);
    str += f;
  }
}