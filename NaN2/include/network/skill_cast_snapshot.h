// skill_cast_snapshot.h
#ifndef SKILL_CAST_SNAPSHOT_H_
#define SKILL_CAST_SNAPSHOT_H_

#include <ProudNetServer.h>

#include <stdint.h>

namespace nan2 {

  struct SkillCastSnapshot {
    
    int skill_type;
    uint8_t direction;
    float pos_x;
    float pos_y;

  };

}

namespace Proud {
  using namespace nan2;

  CMessage& operator >> (CMessage& a, SkillCastSnapshot& packet);
  CMessage& operator << (CMessage& a, const SkillCastSnapshot& packet);
  void AppendTextOut(String& str, const SkillCastSnapshot& packet);
}

#endif