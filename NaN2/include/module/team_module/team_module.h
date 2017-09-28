// module.h
#ifndef MODULE_TEAM_MODULE_MODULE_H_
#define MODULE_TEAM_MODULE_MODULE_H_

#include "../module.h"
#include "../../world/player.h"
#include "../player_event_listener.h"

#include "team.h"

#include <vector>

namespace nan2 {

namespace module {

namespace team_module {

class TeamModule : public Module<TeamModule> {

  std::vector<Team> teams_;

protected:

public:
  TeamModule(int num_of_teams);

  inline static std::string GetName() {
    return "TeamModule";
  }

  Team* const GetTeam(int id);

};

}

}

}

#endif