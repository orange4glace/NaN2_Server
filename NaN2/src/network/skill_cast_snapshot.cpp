// skill_cast_snapshot.cpp
#include "network/skill_cast_snapshot.h"

#include "world_time.h"

#include "logger/logger.h"

namespace Proud {
  using namespace nan2;

  // Not used
  CMessage& operator >> (CMessage& a, SkillCastSnapshot& snapshot) {
    return a;
  }

  CMessage& operator << (CMessage& a, const SkillCastSnapshot& snapshot) {
    a << snapshot.skill_type << snapshot.direction << snapshot.pos_y << snapshot.pos_x;
    return a;
  }

  void AppendTextOut(String& str, const SkillCastSnapshot& snapshot) {
    // String f;
    // f.Format(L"{move_dir=%f, fire_dir=%f, time=%f}", snapshot.pos_x, snapshot.pos_y, snapshot.time);
    // str += f;
  }
}