// team.h
#ifndef MODULE_TEAM_MODULE_TEAM_H_
#define MODULE_TEAM_MODULE_TEAM_H_

#include "../../world/player.h"

#include <map>

namespace nan2 {

namespace module {

namespace team_module {

using TeamID = int;

class Team {
  friend class TeamModule;

  TeamID id_;
  std::map<PlayerID, Player* const> players_;

  void addPlayer(Player* const player);
  void removePlayer(Player* const player);

protected:

public:
  Team(TeamID id);

  Player* const GetPlayer(PlayerID id) const;

  TeamID id() const;

};

}

}

}

#endif