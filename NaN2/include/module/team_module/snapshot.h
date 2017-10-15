// snapshot.h
#ifndef MODULE_TEAM_MODULE_SNAPSHOT_H_
#define MODULE_TEAM_MODULE_SNAPSHOT_H_

#include <ProudNetServer.h>

#include "../../world/player.h"
#include <stdint.h>
#include <vector>

namespace nan2 {

namespace module {

namespace team_module {

struct TeamSnapshot {
  int id;
  std::vector<PlayerID> players;
  int score;
};

struct Snapshot {
  std::vector<TeamSnapshot> team_snapshots;
};

}

}

}

namespace Proud {

inline CMessage& operator >> (CMessage& a, nan2::module::team_module::Snapshot& packet) {
  return a;
}

inline CMessage& operator << (CMessage& a, const nan2::module::team_module::Snapshot& packet) {
  a << (int32_t)packet.team_snapshots.size();
  for (auto& team_snapshot : packet.team_snapshots) {
    a << team_snapshot.id;
    a << (int32_t)team_snapshot.players.size();
    for (auto& player : team_snapshot.players) {
      a << player;
    }
    a << team_snapshot.score;
  }
  return a;
}

inline void AppendTextOut(String& str, const nan2::module::team_module::Snapshot& packet) {

}

}


#endif