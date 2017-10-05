// team_module.cpp
#include "module/team_module/team_module.h"

#include "network/proud_server.h"

#include "../../../pidl/team_mod_s2c_common.cpp"
#include "../../../pidl/team_mod_s2c_proxy.cpp"

namespace nan2 {

namespace module {

namespace team_module {

TeamModule::TeamModule() : Module<TeamModule>(),
PlayerEventListener(event_listener::HIGHEST) {

}

void TeamModule::Initialize(const void* args ...) {
  num_of_teams_ = *(int*)args;
  L_DEBUG << "Team Module initialized with # of teams = " << num_of_teams_;
  for (int i = 0; i < num_of_teams_; i ++)
    teams_.emplace_back(Team(i));
}

void TeamModule::Destroy() {

}

void TeamModule::OnPlayerJoin(Player* const player) {
  Snapshot snapshot;
  for (auto team : teams_) {
    snapshot.team_snapshots.emplace_back(TeamSnapshot{});
    auto& team_snapshot = snapshot.team_snapshots.back();
    team_snapshot.id = team.id_;
    team_snapshot.score = team.score_;
    for (auto p : team.players_)
      team_snapshot.players.push_back(p.first);
  }
  ProudServer::instance()->IteratePlayers([&](Player* const p) -> bool {
    proxy_.Snapshot(p->id(), Proud::RmiContext::ReliableSend, snapshot);
    return true;
  });
}

void TeamModule::OnPlayerLeave(Player* const player) {

}

void TeamModule::AddPlayer(Team* const team, Player* const player) {
  team->addPlayer(player);
#ifdef _DEBUG
  if (player_team_map_.count(player))
    throw std::string("[TeamModule] player_team_map duplicated player. " + player->id());
#endif
  player_team_map_.insert({ player, team });
  L_DEBUG << "[TeamModule] Player added, Team = " << team->id() << ", Player = " << player->id();
}

void TeamModule::RemovePlayer(Team* const team, Player* const player) {
  team->removePlayer(player);
#ifdef _DEBUG
  if (!player_team_map_.count(player))
    throw std::string("[TeamModule] player_team_map no player. " + player->id());
#endif
  player_team_map_.erase(player);
  L_DEBUG << "[TeamModule] Player removed, Team = " << team->id() << ", Player = " << player->id();
}

Team* const TeamModule::GetTeam(TeamID id) {
#ifdef _DEBUG
  
#endif
  return &teams_[id];
}

Team* const TeamModule::GetTeam(Player* player) {
#ifdef _DEBUG
  if (!player_team_map_.count(player))
    throw std::string("[TeamModule] player_team_map no player. " + player->id());
#endif
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