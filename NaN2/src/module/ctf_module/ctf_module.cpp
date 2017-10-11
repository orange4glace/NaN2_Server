// ctf_module.cpp
#include "module/ctf_module/ctf_module.h"

#include "../pidl/ctf_mod_s2c_common.cpp"
#include "../pidl/ctf_mod_s2c_proxy.cpp"
#include "../pidl/ctf_mod_s2c_stub.cpp"

#include "logger/logger.h"

#include <cassert>

namespace nan2 {

namespace module {

namespace ctf_module {

CTFModule::CTFModule() {
}

void CTFModule::Initialize(const void* args ...) {
  ProudServer::instance()->AttachProxy(&proxy_);
  ProudServer::instance()->AttachStub(&stub_);
  auto team_mod = team_module::TeamModule::GetModule();
  for (int i = 0; i < team_mod->num_of_teams(); i++) {
    auto team = team_mod->GetTeam(i);
    Flag* flag = new Flag(team_mod->GetTeam(i), Vector2::ZERO);
    World::instance()->AddGameObject(flag);
    team_infos_[team].team_id = i;
    team_infos_[team].flag = flag;
    team_infos_[team].base_point = Vector2::ZERO;
  }
};

void CTFModule::Destroy() {

}


void CTFModule::OnPlayerJoin(Player* const player) {
  return;
  Snapshot snapshot;
  for (auto team_data_pair : team_infos_) {
    auto& team_data = team_data_pair.second;
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

  proxy_.Snapshot(player->id(), Proud::RmiContext::ReliableSend, snapshot);
}

void CTFModule::OnPlayerLeave(Player* const player) {
  L_DEBUG << "[CTFModule] Player leave";
  // Check is attached player
  for (auto team_data_pair : team_infos_) {
    auto& team_data = team_data_pair.second;
    if (team_data.flag->attached_player() == player) {
      L_DEBUG << "[CTFModule] Try detach " << team_data.flag;
      team_data.flag->Detach();
      L_DEBUG << "[CTFModule] Detached";
    }
  }
  L_DEBUG << "[CTFModule] Player leave Done";
}

const TeamData& CTFModule::team_data(const team_module::Team* const team) const {
  assert(team_infos_.count(team));
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
