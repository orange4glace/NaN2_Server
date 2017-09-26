// team.h
#ifndef MODULE_TEAM_MODULE_TEAM_H_
#define MODULE_TEAM_MODULE_TEAM_H_

#include "../../player.h"

namespace nan2 {

namespace module {

namespace team_module {

class Team {

  int id;

public:
  Team(int id);

  void AddPlayer(Player* player);
  void RemovePlayer(Player* player);
  Player* const GetPlayer(PlayerID id) const;

  int id() const;

};

}

}

}

#endif