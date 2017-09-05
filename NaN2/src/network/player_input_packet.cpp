// player_input_packet.cpp
#include "network/player_input_packet.h"

#include "logger/logger.h"

namespace Proud {
  using namespace nan2;

  CMessage& operator >> (CMessage& a, PlayerInputPacket& packet) {
    a >> packet.dt >> packet.sequence >> packet.move_dir >> packet.fire_dir;
    return a;
  }

  // Not used
  CMessage& operator << (CMessage& a, const PlayerInputPacket& packet) {
    return a;
  }

  void AppendTextOut(String& str, const PlayerInputPacket& packet) {
    // String f;
    // f.Format(L"{move_dir=%u, fire_dir=%u}", packet.move_dir, packet.fire_dir);
    // str += f;
  }
}