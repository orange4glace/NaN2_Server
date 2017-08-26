// local_character_snapshot.h
#ifndef LOCAL_CHARACTER_SNAPSHOT_H_
#define LOCAL_CHARACTER_SNAPSHOT_H_

#include <ProudNetServer.h>

#include <stdint.h>

namespace nan2 {

  struct LocalCharacterSnapshot {

    int last_acked_input_sequence_;
    float pos_x;
    float pos_y;
    uint8_t hp;

  };

}

namespace Proud {
  using namespace nan2;

  CMessage& operator >> (CMessage& a, LocalCharacterSnapshot& packet);
  CMessage& operator << (CMessage& a, const LocalCharacterSnapshot& packet);
  void AppendTextOut(String& str, const LocalCharacterSnapshot& packet);
}

#endif