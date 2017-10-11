// team_module.cpp
#include "module/team_module/team_module.h"

#include "network/proud_server.h"

#include "../../../pidl/team_mod_s2c_common.cpp"
#include "../../../pidl/team_mod_s2c_proxy.cpp"

#include "logger/logger.h"

namespace nan2 {

namespace module {

namespace team_module {

TeamModule::TeamModule() : Module<TeamModule>(),
PlayerEventListener(event_listener::HIGHEST) {

}

void TeamModule::Initialize(const void* args ...) {
  ProudServer::instance()->AttachProxy(&proxy_);
  num_of_teams_ = *(int*)args;
  L_DEBUG << "Team Module initialized with # of teams = " << num_of_teams_;
  for (int i = 0; i < num_of_teams_; i ++)
    teams_.emplace_back(Team(i));
}

void TeamModule::Destroy() {

}

void TeamModule::OnPlayerJoin(Player* const player) {
  Snapshot snapshot;

  // For test
  AddPlayer(GetTeam(player->id() % 2), player);

  for (auto team : teams_) {
    snapshot.team_snapshots.emplace_back(TeamSnapshot{});
    auto& team_snapshot = snapshot.team_snapshots.back();
    team_snapshot.id = team.id_;
    team_snapshot.score = team.score_;
    for (auto p : team.players_)
      team_snapshot.players.push_back(p.first);
  }

  proxy_.Snapshot(player->id(), Proud::RmiContext::ReliableSend, snapshot);
}

void TeamModule::OnPlayerLeave(Player* const player) {
  L_DEBUG << "[TeamModule] Player leave";
  auto team = GetTeam(player);
  RemovePlayer(team, player);
  L_DEBUG << "[TeamModule] Player leave Done";
}

void TeamModule::AddPlayer(Team* const team, Player* const player) {
  team->addPlayer(player);
  assert(!player_team_map_.count(player));
  player_team_map_.insert({ player, team });
  ProudServer::instance()->IteratePlayers([&](Player* const p) -> bool {
    proxy_.TeamJoined(p->id(), Proud::RmiContext::ReliableSend, player->id(), team->id());
    return true;
  });
  L_DEBUG << "[TeamModule] Player added, Team = " << team->id() << ", Player = " << player->id();
}

void TeamModule::RemovePlayer(Team* const team, Player* const player) {
  team->removePlayer(player);
  assert(player_team_map_.count(player) > 0);
  player_team_map_.erase(player);
  ProudServer::instance()->IteratePlayers([&](Player* const p) -> bool {
    proxy_.TeamLeft(p->id(), Proud::RmiContext::ReliableSend, player->id(), team->id());
    return true;
  });
  L_DEBUG << "[TeamModule] Player removed, Team = " << team->id() << ", Player = " << player->id();
}

Team* const TeamModule::GetTeam(TeamID id) {
  assert(teams_.size() > id);
  return &teams_[id];
}

Team* const TeamModule::GetTeam(Player* player) {
  assert(player_team_map_.count(player) > 0);
  return player_team_map_.at(player);
}

const TeamModS2C::Proxy& TeamModule::proxy() const {
  return proxy_;
}

int TeamModule::num_of_teams() const {
  return num_of_teams_;
}
}
}
}
