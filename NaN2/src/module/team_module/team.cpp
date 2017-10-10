// team.cpp
#include "module/team_module/team.h"

#include "module/team_module/team_module.h"
#include "network/proud_server.h"

#include "logger/logger.h"

namespace nan2 {

namespace module {

namespace team_module {

Team::Team(TeamID id) :
id_(id) {

}

void Team::addPlayer(Player* const player) {
  assert(!players_.count(player->id()));
  players_.insert({ player->id(), player });
}

void Team::removePlayer(Player* const player) {
  assert(players_.count(player->id()));
  players_.erase(player->id());
}

Player* const Team::GetPlayer(PlayerID id) const {
  assert(players_.count(id) > 0);
  return players_.at(id);
}

void Team::AddScore(int score) {
  /* WHY ProudNet ASSERT ? 
  auto proxy = team_module::TeamModule::GetModule()->proxy();
  ProudServer::instance()->IteratePlayers([&](Player* const p) -> bool {
    proxy.Scored(p->id(), Proud::RmiContext::ReliableSend, id_, score);
    return true;
  });
  */
}

int Team::score() const {
  return score_;
}

TeamID Team::id() const {
  return id_;
}

}

}

}