// module.h
#ifndef MODULE_TEAM_MODULE_MODULE_H_
#define MODULE_TEAM_MODULE_MODULE_H_

#include "../module.h"
#include "../player_event_listener.h"

#include "team.h"

#include <vector>

namespace nan2 {

namespace module {

namespace team_module {

class Module : public ::nan2::MODULE::Module, public PlayerEventListener {

  std::vector<Team> teams_;
  void OnPlayerJoin(Player* const player) override;
  void OnPlayerLeave(Player* const player) override;

};

}

}

}

#endif