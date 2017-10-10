//  ctf_module.h
//  Dependencies
//    TeamModule
#ifndef MODULE_CTF_MODULE_CTF_MODULE_H_
#define MODULE_CTF_MODULE_CTF_MODULE_H_

#include "../module.h"
#include "../team_module/team_module.h"

#include "../event_listener/player_event_listener.h"

#include "../../network/proud_server.h"
#include "snapshot.h"
#include "../../../pidl/ctf_mod_s2c_common.h"
#include "../../../pidl/ctf_mod_s2c_proxy.h"
#include "../../../pidl/ctf_mod_s2c_stub.h"

#include "team_data.h"
#include "gameobject/flag.h"

#include <map>

namespace nan2 {

namespace module {

namespace ctf_module {

class CTFModule : public Module<CTFModule>,
  public event_listener::PlayerEventListener {
  friend class Module<CTFModule>;

  CTFModS2C::Proxy proxy_;
  CTFModS2C::Stub stub_;

  std::map<const team_module::Team* const, TeamData> team_infos_;

  void OnPlayerJoin(Player* const player) override;

protected:

public:
  CTFModule();

  inline static std::string GetName() {
    return "CTFModule";
  }

  void Initialize(const void* args ...) override;
  void Destroy() override;

  const TeamData& team_data(const team_module::Team* const team) const;

  void ProxyFlagCaptured(const Flag* const flag, const Player* const player);
  void ProxyFlagDropped(const Flag* const flag, const Player* const player, const Vector2& position);
  void ProxyFlagReturned(const Flag* const flag, const Player* const player);

};

}

}

}

#endif