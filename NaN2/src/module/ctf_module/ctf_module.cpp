// ctf_module.cpp
#include "module/ctf_module/ctf_module.h"

#include "../pidl/ctf_mod_s2c_common.cpp"
#include "../pidl/ctf_mod_s2c_proxy.cpp"
#include "../pidl/ctf_mod_s2c_stub.cpp"

#include <cassert>

namespace nan2 {

namespace module {

namespace ctf_module {

CTFModule::CTFModule() {
}

void CTFModule::Initialize(const void* args ...) {
  auto team_mod = team_module::TeamModule::GetModule();
  for (int i = 0; i < team_mod->num_of_teams(); i++) {
    auto team = team_mod->GetTeam(i);
    Flag* flag = new Flag(team_mod->GetTeam(i), Vector2::ZERO);
    World::instance()->AddGameObject(flag);
    team_infos_[team].team_id = i;
    team_infos_[team].flag = flag;
  }
};

void CTFModule::Destroy() {

}


void CTFModule::OnPlayerJoin(Player* const player) {
  Snapshot snapshot;
  for (auto team_data_pair : team_infos_) {
    auto team_data = team_data_pair.second;
    snapshot.team_data_snapshots.emplace_back(TeamDataSnapshot{});
    auto& team_data_snapshot = snapshot.team_data_snapshots.back();
    team_data_snapshot.team_id = team_data.team_id;
    team_data_snapshot.base_point_x = team_data.base_point.x();
    team_data_snapshot.base_point_y = team_data.base_point.y();
    auto attached_player = team_data.flag->attached_player();
    team_data_snapshot.flag_snapshot.attached_player = (attached_player == nullptr ? -1 : attached_player->id());
    if (team_data.flag->returned()) {
      team_data_snapshot.flag_snapshot.x = -1;
      team_data_snapshot.flag_snapshot.x = -1;
    }
    else {
      team_data_snapshot.flag_snapshot.x = team_data.flag->position().x();
      team_data_snapshot.flag_snapshot.y = team_data.flag->position().y();
    }
  }
  ProudServer::instance()->IteratePlayers([&](Player* const p) -> bool {
    proxy_.Snapshot(p->id(), Proud::RmiContext::ReliableSend, snapshot);
    return true;
  });
}

const TeamData& CTFModule::team_data(const team_module::Team* const team) const {
#ifdef _DEBUG
  assert(team_infos_.count(team));
#endif
  return team_infos_.at(team);
}

void CTFModule::ProxyFlagCaptured(const Flag* const flag, const Player* const player) {
  ProudServer::instance()->IteratePlayers([&](Player* const p) -> bool {
    proxy_.FlagCaptured(p->id(), Proud::RmiContext::ReliableSend, player->id());
    return true;
  });
}

void CTFModule::ProxyFlagDropped(const Flag* const flag, const Player* const player, const Vector2& position) {
  ProudServer::instance()->IteratePlayers([&](Player* const p) -> bool {
    proxy_.FlagDropped(p->id(), Proud::RmiContext::ReliableSend, player->id(), position.x(), position.y());
    return true;
  });
}

void CTFModule::ProxyFlagReturned(const Flag* const flag, const Player* const player) {
  ProudServer::instance()->IteratePlayers([&](Player* const p) -> bool {
    proxy_.FlagReturned(p->id(), Proud::RmiContext::ReliableSend, player->id());
    return true;
  });
}

}

}

}