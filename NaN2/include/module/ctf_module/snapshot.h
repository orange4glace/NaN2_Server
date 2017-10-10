// snapshot.h
#ifndef MODULE_CTF_MODULE_SNAPSHOT_H_
#define MODULE_CTF_MODULE_SNAPSHOT_H_

#include <ProudNetServer.h>

#include <vector>

namespace nan2 {

namespace module {

namespace ctf_module {

struct FlagSnapshot {
  int attached_player;
  float x, y;
};

struct TeamDataSnapshot {
  int team_id;
  float base_point_x, base_point_y;
  FlagSnapshot flag_snapshot;
};

struct Snapshot {
  std::vector<TeamDataSnapshot> team_data_snapshots;
};

}

}

}

namespace Proud {

inline CMessage& operator >> (CMessage& a, nan2::module::ctf_module::Snapshot& packet) {
  return a;
}

inline CMessage& operator << (CMessage& a, const nan2::module::ctf_module::Snapshot& packet) {
  a << packet.team_data_snapshots.size();
  for (auto& team_data_snapshot : packet.team_data_snapshots) {
    a << team_data_snapshot.team_id << team_data_snapshot.base_point_x << team_data_snapshot.base_point_y;
    a << team_data_snapshot.flag_snapshot.attached_player << team_data_snapshot.flag_snapshot.x << team_data_snapshot.flag_snapshot.y;
  }
  return a;
}

inline void AppendTextOut(String& str, const nan2::module::ctf_module::Snapshot& packet) {

}

}


#endif