// ctf_module.cpp
#include "module/ctf_module/ctf_module.h"

#include "../pidl/ctf_mod_s2c_common.cpp"
#include "../pidl/ctf_mod_s2c_proxy.cpp"
#include "../pidl/ctf_mod_s2c_stub.cpp"

#include <cassert>

namespace nan2 {

namespace module {

namespace ctf_module {

CTFModule::CTFModule() {
}

void CTFModule::Initialize(const void* args ...) {
  auto team_mod = team_module::TeamModule::GetModule();
  for (int i = 0; i < team_mod->num_of_teams(); i++) {
    Flag* flag = new Flag(team_mod->GetTeam(i), Vector2::ZERO);
    World::instance()->AddGameObject(flag);
  }
};

void CTFModule::Destroy() {

}


void CTFModule::OnPlayerJoin(Player* const player) {

}

const TeamInfo& CTFModule::team_info(const team_module::Team* const team) const {
#ifdef _DEBUG
  assert(team_infos_.count(team));
#endif
  return team_infos_.at(team);
}

void CTFModule::ProxyFlagCaptured(const Flag* const flag, const Player* const player) {
  ProudServer::instance()->IteratePlayers([&](Player* const p) -> bool {
    proxy_.FlagCaptured(p->id(), Proud::RmiContext::ReliableSend, player->id());
    return true;
  });
}

void CTFModule::ProxyFlagDropped(const Flag* const flag, const Player* const player, const Vector2& position) {
  ProudServer::instance()->IteratePlayers([&](Player* const p) -> bool {
    proxy_.FlagDropped(p->id(), Proud::RmiContext::ReliableSend, player->id(), position.x(), position.y());
    return true;
  });
}

void CTFModule::ProxyFlagReturned(const Flag* const flag, const Player* const player) {
  ProudServer::instance()->IteratePlayers([&](Player* const p) -> bool {
    proxy_.FlagReturned(p->id(), Proud::RmiContext::ReliableSend, player->id());
    return true;
  });
}

}

}

}