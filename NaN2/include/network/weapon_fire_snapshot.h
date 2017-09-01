// weapon_fire_snapshot.h
#ifndef WEAPON_FIRE_SNAPSHOT_H_
#define WEAPON_FIRE_SNAPSHOT_H_

#include <ProudNetServer.h>

#include <stdint.h>

namespace nan2 {

  struct WeaponFireSnapshot {

    float pos_x;
    float pos_y;
    uint8_t dir;
    int time;

  };

}

namespace Proud {
  using namespace nan2;

  CMessage& operator >> (CMessage& a, WeaponFireSnapshot& packet);
  CMessage& operator << (CMessage& a, const WeaponFireSnapshot& packet);
  void AppendTextOut(String& str, const WeaponFireSnapshot& packet);
}

#endif