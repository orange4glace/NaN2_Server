// ctf_module.cpp
#include "module/ctf_module/ctf_module.h"

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

}

}

}