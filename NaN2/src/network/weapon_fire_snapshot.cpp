// weapon_fire_snapshot.cpp
#include "network/weapon_fire_snapshot.h"

#include "world_time.h"

#include "logger\logger.h"

namespace Proud {
  using namespace nan2;

  // Not used
  CMessage& operator >> (CMessage& a, WeaponFireSnapshot& snapshot) {
    return a;
  }

  CMessage& operator << (CMessage& a, const WeaponFireSnapshot& snapshot) {
    a << snapshot.pos_x << snapshot.pos_y << snapshot.dir << (Time::current_time() - snapshot.time);
    return a;
  }

  void AppendTextOut(String& str, const WeaponFireSnapshot& snapshot) {
    String f;
    f.Format(L"{move_dir=%f, fire_dir=%f, time=%f}", snapshot.pos_x, snapshot.pos_y, snapshot.time);
    str += f;
  }
}