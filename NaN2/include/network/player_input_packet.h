// player_input.h
#ifndef PLAYER_INPUT_H_
#define PLAYER_INPUT_H_

#include <ProudNetServer.h>

#include <stdint.h>

namespace nan2 {

  struct PlayerInputPacket {

    uint32_t dt;
    int32_t sequence;
    uint8_t move_dir;
    uint8_t aim_dir;
	int32_t skill_type;

  };

}

namespace Proud {
  using namespace nan2;

  CMessage& operator >> (CMessage& a, PlayerInputPacket& packet);
  CMessage& operator << (CMessage& a, const PlayerInputPacket& packet);
  void AppendTextOut(String& str, const PlayerInputPacket& packet);
}

#endif