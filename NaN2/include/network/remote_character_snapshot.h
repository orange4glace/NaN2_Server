// remote_player_snapshot.h
#ifndef REMOTE_CHARACTER_SNAPSHOT_H_
#define REMOTE_CHARACTER_SNAPSHOT_H_

#include <ProudNetServer.h>

#include "weapon_fire_snapshot.h"

#include <stdint.h>

namespace nan2 {

  struct RemoteCharacterSnapshot {

    Proud::HostID player_id;
    float pos_x;
    float pos_y;
    uint8_t hp;

    std::vector<WeaponFireSnapshot> weapon_fire_snapshots;

  };

}

namespace Proud {
  using namespace nan2;

  CMessage& operator >> (CMessage& a, RemoteCharacterSnapshot& packet);
  CMessage& operator << (CMessage& a, const RemoteCharacterSnapshot& packet);
  void AppendTextOut(String& str, const RemoteCharacterSnapshot& packet);
}

#endif