// team.cpp
#include "module/team_module/team.h"

namespace nan2 {

namespace module {

namespace team_module {

Team::Team(TeamID id) :
id_(id) {

}

void Team::addPlayer(Player* const player) {
#ifdef _DEBUG
  if (players_.count(player->id()))
    throw std::string("[Team] Already has player, " + player->id());
#endif
  players_.insert({ player->id(), player });
}

void Team::removePlayer(Player* const player) {
#ifdef _DEBUG
  if (!players_.count(player->id()))
    throw std::string("[Team] No player, " + player->id());
#endif
  players_.erase(player->id());
}

Player* const Team::GetPlayer(PlayerID id) const {
#ifdef _DEBUG
  if (players_.count(id))
    throw std::string("[Team] No player, " + id);
#endif
  return players_.at(id);
}

TeamID Team::id() const {
  return id_;
}

}

}

}