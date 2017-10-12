// module.h
#ifndef MODULE_TEAM_MODULE_MODULE_H_
#define MODULE_TEAM_MODULE_MODULE_H_

#include "../module.h"
#include "../../world/player.h"
#include "../event_listener/player_event_listener.h"

#include "snapshot.h"

#include "../../../pidl/team_mod_s2c_common.h"
#include "../../../pidl/team_mod_s2c_proxy.h"

#include "team.h"

#include <vector>
#include <map>

namespace nan2 {

namespace module {

namespace team_module {

class TeamModule : public Module<TeamModule>,
  public event_listener::PlayerEventListener {
  friend class Module<TeamModule>;

  int num_of_teams_;

  TeamModS2C::Proxy proxy_;

  std::vector<Team> teams_;
  std::map<Player*, Team*> player_team_map_;

  void OnPlayerJoin(Player* const player) override;
  void OnPlayerLeave(Player* const player) override;

protected:

public:
  TeamModule();

  inline static std::string GetName() {
    return "TeamModule";
  }

  void Initialize(const void* args ...) override;
  void Destroy() override;

  void AddPlayer(Team* const team, Player* const player);
  void RemovePlayer(Team* const team, Player* const player);

  Team* const GetTeam(TeamID id);
  Team* const GetTeam(Player* player);

  TeamModS2C::Proxy& proxy();
  //const TeamModC2S::Stub& stub() const;

  int num_of_teams() const;

};

}

}

}

#endif