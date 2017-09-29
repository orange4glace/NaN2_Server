// team_module.cpp
#include "module/team_module/team_module.h"

namespace nan2 {

namespace module {

namespace team_module {

TeamModule::TeamModule() : Module<TeamModule>() {

}

void TeamModule::Initialize(const void* args ...) {
  int team_num = *(int*)args;
#ifdef _DEBUG
  L_DEBUG << "Team Module initialized with # of teams = " << team_num;
#endif
  for (int i = 0; i < team_num; i ++)
    teams_.emplace_back(Team(i));
}

void TeamModule::Destroy() {

}

void TeamModule::AddPlayer(Team* const team, Player* const player) {
  team->addPlayer(player);
#ifdef _DEBUG
  if (player_team_map_.count(player))
    throw std::string("[TeamModule] player_team_map duplicated player. " + player->id());
#endif
  player_team_map_.insert({ player, team });
#ifdef _DEBUG
  L_DEBUG << "[TeamModule] Player added, Team = " << team->id() << ", Player = " << player->id();
#endif
}

void TeamModule::RemovePlayer(Team* const team, Player* const player) {
  team->removePlayer(player);
#ifdef _DEBUG
  if (!player_team_map_.count(player))
    throw std::string("[TeamModule] player_team_map no player. " + player->id());
#endif
  player_team_map_.erase(player);
#ifdef _DEBUG
  L_DEBUG << "[TeamModule] Player removed, Team = " << team->id() << ", Player = " << player->id();
#endif
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

}

}

}